#include "SWEFaceFluxSolver2d.h"



SWEFaceFluxSolver2d::SWEFaceFluxSolver2d()
{
}


SWEFaceFluxSolver2d::~SWEFaceFluxSolver2d()
{
}

void SWEFaceFluxSolver2d::evaluate(double hmin_, double gra_, double *nx_, double *ny_, double *fm_, double *fluxM_, int fm_dim1, int fm_dim2, int fm_dim3)
{
	c_EvaluateSurfFlux(hmin_, gra_, nx_, ny_, fm_, fluxM_);
};