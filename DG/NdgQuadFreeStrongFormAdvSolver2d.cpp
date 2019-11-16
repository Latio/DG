#include "NdgQuadFreeStrongFormAdvSolver2d.h"

#define NVAR 3 

NdgQuadFreeStrongFormAdvSolver2d::NdgQuadFreeStrongFormAdvSolver2d()
{

}


NdgQuadFreeStrongFormAdvSolver2d::~NdgQuadFreeStrongFormAdvSolver2d()
{
}

void NdgQuadFreeStrongFormAdvSolver2d::evaluateAdvectionRHS(double *fphys, double *frhs)
{
	// evaluate inner edge

	InnerEdge *edge = meshunion->inneredge;
	double *fm;
	double *fp;
	double *fluxM;
	double *fluxP;
	double *fluxS;

	requestmemory(&fm, meshunion->inneredge->Nfp, meshunion->inneredge->Ne, meshunion->Nfield);
	requestmemory(&fp, meshunion->inneredge->Nfp, meshunion->inneredge->Ne, meshunion->Nfield);
	requestmemory(&fluxM, meshunion->inneredge->Nfp, meshunion->inneredge->Ne,NVAR);
	requestmemory(&fluxP, meshunion->inneredge->Nfp, meshunion->inneredge->Ne,NVAR);
	requestmemory(&fluxS, meshunion->inneredge->Nfp, meshunion->inneredge->Ne,NVAR);

	inneredge.EvaluateSurfValue(fphys, fm, fp,meshunion->cell->Np,meshunion->K,meshunion->Nfield);


	freememory(&fm);
	freememory(&fp);
	freememory(&fluxM);
	freememory(&fluxP);
	freememory(&fluxS);

};
