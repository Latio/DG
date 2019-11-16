#pragma once
#include "NdgPhysMat.h"
#include "SWEFaceFluxSolver2d.h"

extern "C" {
	void surfluxSolver_evaluate(double hmin_,double gra_,double *nx_,double *ny_,MeshUnion *mesh_,InnerEdge *edge_);//(hmin, gra, nx, ny, fm, mesh, edge)
}

class SWEAbstract2d :
	public NdgPhysMat
{




public:

	static double gra;
	static double hmin;
	const int Nfield;
	const double Nvar;
	int varFieldIndex[3];
	int outputFieldOrder[3];

	void EvaluateSurfFlux(MeshUnion *mesh, double *nx, double *ny, double *fm, double *fluxM_);

	SWEAbstract2d();
	~SWEAbstract2d();

	SWEFaceFluxSolver2d swefacefluxsolver2d;

};

