#pragma once
#include"MeshUnion.h"
extern "C" {
	void c_Evaluate();
}

extern MeshUnion mesh;
extern const MeshUnion *meshunion;

class SWEHLLNumFluxSolver2d
{
public:
	SWEHLLNumFluxSolver2d();
	~SWEHLLNumFluxSolver2d();

	void numfluxSolver_evaluate(double hmin_, double gra_, double *nx_, double *ny_, double *fm_, double *fp_, double *fluxS_);
};

