#include "SWEAbstract2d.h"

//double SWEAbstract2d::gra = 9.8;
//double SWEAbstract2d::hmin = 0.05;
//double SWEAbstract2d::cfl = 1;


SWEAbstract2d::SWEAbstract2d() :gra(9.8), hmin(0.05), cfl(1), Nfield(7), Nvar(3)
{
	requestmemory(&dx, *meshunion->K);
	for (int i = 0; i < *meshunion->K; i++)
	{
		*(dx + i) = pow(*(meshunion->LAV + i), 0.5);
	}
}


SWEAbstract2d::~SWEAbstract2d()
{
	freememory(&dx);
}

void SWEAbstract2d::EvaluateSurfFlux(double *nx, double *ny, double *fm, double *fluxM_)
{
	//int *Nfp = meshunion->inneredge_p->Nfp;
	//int *Ne = meshunion->inneredge_p->Ne;
	//int Nfield = meshunion->Nfield;

	swefacefluxsolver2d.surfluxSolver_evaluate(hmin, gra, nx, ny, fm, fluxM_);
};

void SWEAbstract2d::EvaluateSurfNumFlux(double *nx, double *ny, double *fm, double *fp, double *fluxS)
{
	swehllnumfluxsolver2d.numfluxSolver_evaluate(hmin, gra, nx, ny, fm, fp, fluxS);
};

//计算时间步长
double SWEAbstract2d::UpdateTimeInterval(double *fphys)
{
	double dt = 0;
	int N = *meshunion->cell_p->N;
	double *status = meshunion->status;
	int *Np = meshunion->cell_p->Np;
	int *K = meshunion->K;

	double dtm = UpdateTimeInterval2d(hmin, gra, N, status, fphys, dx, Np, K, Nfield);
	if (dtm > 0)
	{
		dt = (dt < dtm*cfl) ? dt : dtm * cfl;
	}

	return dt;
};
