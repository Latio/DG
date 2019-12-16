#pragma once

#include<iostream>
#include"MeshUnion.h"
#include"cblas.h"

extern "C" {
	void c_EvaluateVertAverage(double *cvar_, int *Nv_, double *Nvc_, double *VToM_, double *VToK_, double *VToW_, double *fvert_, double *fvmin_, double *fvmax_, int Nvcmax_);
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
	double *Nvc, *VToK, *VToM, *VToW;
};


