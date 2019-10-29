#pragma once
#include"Icell.h"

class InnerEdge
{
public:
	InnerEdge();
	~InnerEdge();

	Icell icell;

	static double* FToE;
	static double* FToF;
	static double* FToM;
	static double* FToN1;
	static double* FToN2;
	static double* FToV;
	static double* Js;
	static double* LAV;
	static double* M;
	static double* Ne;
	static double* Nfp;
	static double* nx;
	static double* ny;
	static double* nz;
	static double* r;
};

