#include "SWEFaceFluxSolver2d.h"



SWEFaceFluxSolver2d::SWEFaceFluxSolver2d()
{
}


SWEFaceFluxSolver2d::~SWEFaceFluxSolver2d()
{
}

void SWEFaceFluxSolver2d::surfluxSolver_evaluate(double hmin_, double gra_, double *nx_, double *ny_, double *fm_, double *fluxM_)
{
	double *nx = nx_;
	double *ny = ny_;
	int *fm_Nfp = meshunion->inneredge_p->Nfp;
	int *fm_Ne = meshunion->inneredge_p->Ne;
	int fm_Nfield = meshunion->Nfield;

	c_EvaluateSurfFlux(hmin_, gra_, nx, ny, fm_, fluxM_, fm_Nfp, fm_Ne, fm_Nfield);
};