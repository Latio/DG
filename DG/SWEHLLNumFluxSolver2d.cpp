#include "SWEHLLNumFluxSolver2d.h"



SWEHLLNumFluxSolver2d::SWEHLLNumFluxSolver2d()
{
}


SWEHLLNumFluxSolver2d::~SWEHLLNumFluxSolver2d()
{
}

void SWEHLLNumFluxSolver2d::numfluxSolver_evaluate(double hmin_, double gra_, double *nx_, double *ny_, double *fm_, double *fp_, double *fluxS_)
{
	c_Evaluate();
};