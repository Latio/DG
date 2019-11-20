#pragma once
#include"Bcell.h"
extern "C" {
	void c_boundary_EvaluateSurfValue(const double *FToM_, const double *FToE_, const double *FToN1_, const double *FToN2_, double *fphys_, double *fm_, double *fp_, const int *Nfp_, const  int *Ne_, const  int *Np_, const  int *K_, const  int Nfield_);
}

class BoundaryEdge
{
public:
	BoundaryEdge();
	~BoundaryEdge();
	void EvaluateSurfValue(double *fphys, double *fm, double *fp, int *Np, int *K, int Nfield);

	Bcell bcell;

	static double* FToE;
	static double* FToF;
	static double* FToM;
	static double* FToN1;
	static double* FToN2;
	static double* FToV;
	static int* ftype;
	static double* Js;
	static double* LAV;
	static double* M;
	static int* Ne;
	static int* Nfp;
	static double* nx;
	static double* ny;
	static double* nz;
	static double* r;
	static double* xb;
	static double* yb;
};

