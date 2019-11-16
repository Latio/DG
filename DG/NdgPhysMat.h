#pragma once

#include "MeshUnion.h"

extern "C" {
	double  UpdateTimeInterval2d(double hmin, double gra, int N, double *status, double *fphys, double *dx, int Np_, int K_, int Nfield_);
}
class NdgPhysMat
{
public:
	NdgPhysMat();
	~NdgPhysMat();

	void matSolver();
	void matEvaluateSSPRK22();
	double UpdateTimeInterval(double *fphys);



	void EvaluateSourceTerm(double *fphys);

	void UpdateExternalField(double *fphys);
	void EvaluateRHS(double *fphys);

	double* EvaluatePostFunc(double *fphys);

	void UpdateOutputResult(double time, double *fphys);


protected:



	double *fext;
	int *outputfile;
	double *limiter;
	double *davectionSolver;
	double *viscositySolver;
	double *NonhydrostaticSolver;

	double *dx;

	static double dt;
	double time;
	double ftime;

	double *frhs;

	double gra;
	double hmin;

	double *fluxS;


	static double *fphys0;
	static double *fphys;

	int Np;// dimension 
	int K;// dimension 
	int Nfield;// dimension 







};

