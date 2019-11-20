#include "SWEFaceFluxSolver2d.h"



SWEFaceFluxSolver2d::SWEFaceFluxSolver2d()
{
}


SWEFaceFluxSolver2d::~SWEFaceFluxSolver2d()
{
}

void SWEFaceFluxSolver2d::surfluxSolver_evaluate(double hmin, double gra, double *nx, double *ny, double *fm, double *fluxM,int *Nfp,int *Ne)
{
	//double *nx = nx_;
	//double *ny = ny_;
	//int *fm_Nfp = meshunion->inneredge_p->Nfp;
	//int *fm_Ne = meshunion->inneredge_p->Ne;
	int Nfield = meshunion->Nfield;

	c_EvaluateSurfFlux(hmin, gra, nx, ny, fm, fluxM, Nfp, Ne, Nfield);
};