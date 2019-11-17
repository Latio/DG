#pragma once
#include"MeshUnion.h"
#include"SWEAbstract2d.h"



class NdgQuadFreeStrongFormAdvSolver2d
{
public:
	NdgQuadFreeStrongFormAdvSolver2d();
	~NdgQuadFreeStrongFormAdvSolver2d();

	void evaluateAdvectionRHS(double *fphys, double *frhs);

	SWEAbstract2d sweabstract2d;
	/*InnerEdge inneredge;*/
};

