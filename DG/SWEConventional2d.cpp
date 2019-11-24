#include "SWEConventional2d.h"



SWEConventional2d::SWEConventional2d()
{

}


SWEConventional2d::~SWEConventional2d()
{

}

void SWEConventional2d::EvaluatePostFunc(double *fphys)
{
	int *K = meshunion->K;
	int *Np = meshunion->cell_p->Np;
	double *hc, *qxc, *qyc;
	requestmemory(&hc, K);
	requestmemory(&qxc, K);
	requestmemory(&qyc, K);
	int dis = (*K)*(*Np);

	double *fphys1 = fphys;
	mesh.GetMeshAverageValue(fphys1, hc);
	double *fphys2 = fphys + dis;
	mesh.GetMeshAverageValue(fphys2, qxc);
	double *fphys3 = fphys + dis * 2;
	mesh.GetMeshAverageValue(fphys3, qyc);

	c_EvaluatePostFunc2d(hmin, fphys, hc, qxc, qyc, K, Np);

	freememory(&hc);
	freememory(&qxc);
	freememory(&qyc);

	UpdateWetDryState(fphys);
};