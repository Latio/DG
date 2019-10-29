#pragma once
#include"Bcell.h"
class BoundaryEdge
{
public:
	BoundaryEdge();
	~BoundaryEdge();

	Bcell bcell;

	static double* FToE;
	static double* FToF;
	static double* FToM;
	static double* FToN1;
	static double* FToN2;
	static double* FToV;
	static double* ftype;
	static double* Js;
	static double* LAV;
	static double* M;
	static double* Ne;
	static double* Nfp;
	static double* nx;
	static double* ny;
	static double* nz;
	static double* r;
	static double* xb;
	static double* yb;
};

