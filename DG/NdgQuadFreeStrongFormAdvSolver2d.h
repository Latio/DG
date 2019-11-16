#pragma once
#include"MeshUnion.h"

extern const MeshUnion *meshunion;


class NdgQuadFreeStrongFormAdvSolver2d
{
public:
	NdgQuadFreeStrongFormAdvSolver2d();
	~NdgQuadFreeStrongFormAdvSolver2d();

	void evaluateAdvectionRHS(double *fphys, double *frhs);


	InnerEdge inneredge;
};

