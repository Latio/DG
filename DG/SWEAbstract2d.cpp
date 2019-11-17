#include "SWEAbstract2d.h"

double SWEAbstract2d::gra = 9.8;
double SWEAbstract2d::hmin = 0.05;
double SWEAbstract2d::cfl = 1;

SWEAbstract2d::SWEAbstract2d() :Nfield(7), Nvar(3)
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

void SWEAbstract2d::EvaluateSurfFlux(double *fm, double *fluxM_)
{
	double *nx = meshunion->inneredge->nx;
	double *ny = meshunion->inneredge->ny;
	int *Nfp = meshunion->inneredge->Nfp;
	int *Ne = meshunion->inneredge->Ne;
	int Nfield = meshunion->Nfield;

	swefacefluxsolver2d.evaluate(hmin, gra, fm, nx, ny, fluxM_, Nfp, Ne, Nfield);
};




//����ʱ�䲽��
double SWEAbstract2d::UpdateTimeInterval(double *fphys)
{
	double dt = 0;
	int N = *meshunion->cell->N;
	double *status = meshunion->status;
	int *Np = meshunion->cell->Np;
	int *K = meshunion->K;

	double dtm = UpdateTimeInterval2d(hmin, gra, N, status, fphys, dx, Np, K, Nfield);
	if (dtm > 0)
	{
		dt = (dt < dtm*cfl) ? dt : dtm * cfl;
	}//�����cfl.

	return dt;
};
