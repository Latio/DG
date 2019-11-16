#include "SWEFaceFluxSolver2d.h"



SWEFaceFluxSolver2d::SWEFaceFluxSolver2d()
{
}


SWEFaceFluxSolver2d::~SWEFaceFluxSolver2d()
{
}

void SWEFaceFluxSolver2d::evaluate(double hmin_, double gra_, double *nx_, double *ny_, double *fm_, double *fluxM_, int fm_Nfp, int fm_Ne, int fm_Nfield)
{
	c_EvaluateSurfFlux(hmin_, gra_, nx_, ny_, fm_, fluxM_, fm_Nfp, fm_Ne, fm_Nfield);
};