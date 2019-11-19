#include "NdgQuadFreeStrongFormAdvSolver2d.h"

NdgQuadFreeStrongFormAdvSolver2d::NdgQuadFreeStrongFormAdvSolver2d()
{
}

NdgQuadFreeStrongFormAdvSolver2d::~NdgQuadFreeStrongFormAdvSolver2d()
{
}

void NdgQuadFreeStrongFormAdvSolver2d::evaluateAdvectionRHS(double *fphys, double *frhs)
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
	sweabstract2d.EvaluateSurfFlux(nx, ny, fm, fluxM);//return fluxM
	sweabstract2d.EvaluateSurfFlux(nx, ny, fm, fluxP);//return fluxP
	sweabstract2d.EvaluateSurfNumFlux(nx, ny, fm, fp, fluxS);//retuen fluxS
	mesh.inneredge.EvaluateStrongFromEdgeRHS(fluxM, fluxP, fluxS, frhs, invM, J, Np, K, Nfield);

	freememory(&fm);
	freememory(&fp);
	freememory(&fluxM);
	freememory(&fluxP);
	freememory(&fluxS);


	// evaluate boundary edge
	int *Nfp_b = meshunion->boundarydge_p->Nfp;//define temporary dimemsion
	int *Ne_b = meshunion->boundarydge_p->Ne;//define temporary dimemsion

	requestmemory(&fm, Nfp_b, Ne_b, Nfield);
	requestmemory(&fp, Nfp_b, Ne_b, Nfield);
	requestmemory(&fluxM, Nfp_b, Ne_b, NVAR);
	requestmemory(&fluxP, Nfp_b, Ne_b, NVAR);
	requestmemory(&fluxS, Nfp_b, Ne_b, NVAR);
	mesh.boundarydge.EvaluateSurfValue(fphys, fm, fp, Np, K, Nfield);



	freememory(&fm);
	freememory(&fp);
	freememory(&fluxM);
	freememory(&fluxP);
	freememory(&fluxS);

};