#pragma once

#include<iostream>
#include"MeshUnion.h"
#include"cblas.h"

extern "C" {
	void c_EvaluateVertAverage();
}

extern MeshUnion mesh;
extern const MeshUnion *meshunion;

class SWEElevationLimiter2d
{
public:
	SWEElevationLimiter2d();
	~SWEElevationLimiter2d();

	void apply(double *fphys, int *Np, int *K);
	void matLimit(double *fphys, int fieldId);
	void EvaluateVertAverage(double *fphys, int fieldId, double *fvert, double *fvmin, double *fvmax, double *cvar);

protected:
	int Nvcmax;
	double *Nvc, *VToK, *VToM, *VTow;
};


