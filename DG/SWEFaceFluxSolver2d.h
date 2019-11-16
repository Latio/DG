#pragma once
extern "C" {
	void c_EvaluateSurfFlux(double hmin_, double gra_,double *nx_, double *ny_, double *fm_, double *fluxM_);
}

class SWEFaceFluxSolver2d
{
public:
	SWEFaceFluxSolver2d(); 
	~SWEFaceFluxSolver2d();

	friend class SWEAbstract2d;

	void evaluate(double hmin_, double gra_, double *nx_, double *ny_, double *fm_, double *fluxM_);
};

