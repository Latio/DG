#pragma once
#include"MeshUnion.h"

extern MeshUnion *meshunion;

class NdgQuadFreeStrongFormAdvSolver2d
{
public:
	NdgQuadFreeStrongFormAdvSolver2d();
	~NdgQuadFreeStrongFormAdvSolver2d();

	static void evaluateAdvectionRHS(double *fphys, double *frhs);
};

