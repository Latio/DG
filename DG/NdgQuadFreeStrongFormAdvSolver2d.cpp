#include "NdgQuadFreeStrongFormAdvSolver2d.h"



NdgQuadFreeStrongFormAdvSolver2d::NdgQuadFreeStrongFormAdvSolver2d()
{

}


NdgQuadFreeStrongFormAdvSolver2d::~NdgQuadFreeStrongFormAdvSolver2d()
{
}

void NdgQuadFreeStrongFormAdvSolver2d::evaluateAdvectionRHS(double *fphys, double *frhs)
{
	// evaluate inner edge
	MeshUnion *mesh = meshunion;
	InnerEdge *edge = mesh->inneredge;
	double *fm;
	double *fp;
	requestmemory(&fm, meshunion->inneredge->Nfp, meshunion->inneredge->Ne, meshunion->Nfield);
	requestmemory(&fp, meshunion->inneredge->Nfp, meshunion->inneredge->Ne, meshunion->Nfield);



	freememory(&fm);
	freememory(&fp);

};
