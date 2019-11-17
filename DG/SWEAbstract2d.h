#pragma once
//#include "NdgPhysMat.h"
#include "SWEFaceFluxSolver2d.h"

extern "C" {
	void surfluxSolver_evaluate(double hmin_, double gra_, double *nx_, double *ny_, MeshUnion *mesh_, InnerEdge *edge_);//(hmin, gra, nx, ny, fm, mesh, edge)
	double UpdateTimeInterval2d(double hmin, double gra, int N, double *status, double *fphys, double *dx, int *Np_, int *K_, int Nfield_);
}

class SWEAbstract2d
{




public:

	static double gra;
	static double hmin;
	static double cfl;
	const int Nfield = 7;
	const double Nvar = 3;

	double *dx;

	int varFieldIndex[3];
	int outputFieldOrder[3];

	void EvaluateSurfFlux(double *fm, double *fluxM_);
	double UpdateTimeInterval(double *fphys);

	SWEAbstract2d();
	~SWEAbstract2d();

	SWEFaceFluxSolver2d swefacefluxsolver2d;

};

