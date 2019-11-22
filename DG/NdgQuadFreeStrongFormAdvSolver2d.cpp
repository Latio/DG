#include "NdgQuadFreeStrongFormAdvSolver2d.h"

NdgQuadFreeStrongFormAdvSolver2d::NdgQuadFreeStrongFormAdvSolver2d()
{
}

NdgQuadFreeStrongFormAdvSolver2d::~NdgQuadFreeStrongFormAdvSolver2d()
{
}

void dotmul(const int num, const double *matrix1, double *matrix2)
{

	for (int i = 0; i < num; i++)
	{
		*(matrix2 + i) = (*(matrix1 + i))*((*matrix2 + i));
	}
	return;
}

void multiply(const double *matrix1, const double *matrix2, double *result)
{
	const enum CBLAS_ORDER Order = CblasColMajor;
	const enum CBLAS_TRANSPOSE TransA = CblasNoTrans;
	const enum CBLAS_TRANSPOSE TransB = CblasNoTrans;
	const int M = *meshunion->cell_p->Np;//A的行数，C的行数
	const int N = *meshunion->K;//B的列数，C的列数
	const int L = *meshunion->cell_p->Np;//A的列数，B的行数
	const double alpha = 1.0;
	const double beta = 0.0;
	const int lda = M;//A的行        
	const int ldb = L;//B的行
	const int ldc = M;//C的行   //如果列优先，分别写ABC的行

	cblas_dgemm(Order, TransA, TransB, M, N, L, alpha, matrix1, lda, matrix2, ldb, beta, result, ldc);
}


void NdgQuadFreeStrongFormAdvSolver2d::evaluateAdvectionRHS(double *fphys, double *frhs, double *fext)
{

	double *fm;
	double *fp;
	double *fluxM;
	double *fluxP;
	double *fluxS;
	const int  NVAR = 3;

	int *Nfp = meshunion->inneredge_p->Nfp;//define temporary dimemsion
	int *Ne = meshunion->inneredge_p->Ne;//define temporary dimemsion
	int Nfield = meshunion->Nfield;//define temporary dimemsion
	int *Np = meshunion->cell_p->Np;//define temporary dimemsion
	int *K = meshunion->K;//define temporary dimemsion
	double *invM = meshunion->cell_p->invM;
	double *J = meshunion->J;

	requestmemory(&fm, Nfp, Ne, Nfield);
	requestmemory(&fp, Nfp, Ne, Nfield);
	requestmemory(&fluxM, Nfp, Ne, NVAR);
	requestmemory(&fluxP, Nfp, Ne, NVAR);
	requestmemory(&fluxS, Nfp, Ne, NVAR);//request memory for fm,fp,fluxM,fluxP,fluxS.

	// evaluate inner edge
	double *nx = meshunion->inneredge_p->nx;
	double *ny = meshunion->inneredge_p->ny;
	mesh.inneredge.EvaluateSurfValue(fphys, fm, fp, Np, K, Nfield);//return fm,fp
	sweabstract2d.EvaluateSurfFlux(nx, ny, fm, fluxM, Nfp, Ne);//return fluxM
	sweabstract2d.EvaluateSurfFlux(nx, ny, fm, fluxP, Nfp, Ne);//return fluxP
	sweabstract2d.EvaluateSurfNumFlux(nx, ny, fm, fp, fluxS, Nfp, Ne);//retuen fluxS
	mesh.inneredge.EvaluateStrongFromEdgeRHS(fluxM, fluxP, fluxS, frhs, invM, J, Np, K, Nfield);

	freememory(&fm);
	freememory(&fp);
	freememory(&fluxM);
	freememory(&fluxP);
	freememory(&fluxS);

	int *Nfp_b = meshunion->boundarydge_p->Nfp;//define temporary dimemsion
	int *Ne_b = meshunion->boundarydge_p->Ne;//define temporary dimemsion

	requestmemory(&fm, Nfp_b, Ne_b, Nfield);
	requestmemory(&fp, Nfp_b, Ne_b, Nfield);
	requestmemory(&fluxM, Nfp_b, Ne_b, NVAR);
	//requestmemory(&fluxP, Nfp_b, Ne_b, NVAR);
	requestmemory(&fluxS, Nfp_b, Ne_b, NVAR);

	// evaluate boundary edge
	nx = meshunion->boundarydge_p->nx;
	ny = meshunion->boundarydge_p->ny;

	mesh.boundarydge.EvaluateSurfValue(fphys, fm, fp, Np, K, Nfield);
	sweabstract2d.ImposeBoundaryCondition(nx, ny, fm, fp, fext);
	sweabstract2d.EvaluateSurfFlux(nx, ny, fm, fluxM, Nfp_b, Ne_b);//return fluxM
	sweabstract2d.EvaluateSurfNumFlux(nx, ny, fm, fp, fluxS, Nfp_b, Ne_b);

	double *frhs_temp;
	requestmemory(&frhs_temp, Np, K, Nfield);

	mesh.boundarydge.EvaluateStrongFromEdgeRHS(invM, J, fluxM, fluxS, Np, K, Nfield, frhs_temp);
	const int num = (*Np)*(*K)*Nfield;
	const double alpha = 1;
	const int dis1 = 1;
	const int dis2 = 1;
	cblas_daxpy(num, alpha, frhs_temp, dis1, frhs, dis2);

	freememory(&frhs_temp);
	freememory(&fm);
	freememory(&fp);
	freememory(&fluxM);
	//freememory(&fluxP);
	freememory(&fluxS);

	double *E;
	double *G;
	requestmemory(&E, Np, K, NVAR);
	requestmemory(&G, Np, K, NVAR);
	swepreblanaced2d.EvaluateFlux(fphys, E, G);

	const double* Dr = meshunion->cell_p->Dr;
	const double* Ds = meshunion->cell_p->Ds;
	const double* rx = meshunion->rx;
	const double* ry = meshunion->ry;
	const double* sx = meshunion->sx;
	const double* sy = meshunion->sy;

	double *rx_dr_e, *sx_ds_e, *ry_dr_g, *sy_ds_g;
	requestmemory(&rx_dr_e, Np, K);
	requestmemory(&sx_ds_e, Np, K);
	requestmemory(&ry_dr_g, Np, K);
	requestmemory(&sy_ds_g, Np, K);


	//cblas_dgemm(chn, chn, &np, &oneI, &np, &one, invM, &np, rhs_, &np, &zero, temp, &np);


	//for i = 1:phys.Nvar
	//	phys.frhs{ m }(:, : , i) = ...
	//	phys.frhs{ m }(:, : , i) + ...
	//	- obj.rx{ m }.*(obj.Dr{ m } *E(:, : , i)) ...
	//	- obj.sx{ m }.*(obj.Ds{ m } *E(:, : , i)) ...
	//	- obj.ry{ m }.*(obj.Dr{ m } *G(:, : , i)) ...
	//	- obj.sy{ m }.*(obj.Ds{ m } *G(:, : , i)); ...
	int dis = (*Np)*(*K);
	for (int i = 0; i < NVAR; i++)
	{
		double *frhs_ = frhs + i * dis;
		double *E_ = E + i * dis;
		double *G_ = G + i * dis;
		multiply(Dr, E_, rx_dr_e);
		multiply(Ds, E_, sx_ds_e);
		multiply(Dr, G_, ry_dr_g);
		multiply(Ds, G_, sy_ds_g);

		dotmul(dis, rx, rx_dr_e);
		dotmul(dis, sx, sx_ds_e);
		dotmul(dis, ry, ry_dr_g);
		dotmul(dis, sy, sy_ds_g);

		double alpha_ = -1.0;
		//	cblas_daxpy(num,alpha,a,1,a,1);
		cblas_daxpy(dis, alpha, rx_dr_e, dis1, sx_ds_e, dis2);
		cblas_daxpy(dis, alpha, sx_ds_e, dis1, ry_dr_g, dis2);
		cblas_daxpy(dis, alpha, ry_dr_g, dis1, sy_ds_g, dis2);
		cblas_daxpy(dis, alpha_, sy_ds_g, dis1, frhs_, dis2);

	}

	freememory(&E);
	freememory(&G);
	freememory(&rx_dr_e);
	freememory(&sx_ds_e);
	freememory(&ry_dr_g);
	freememory(&sy_ds_g);

};


