#pragma once
#include"NdgQuadFreeStrongFormAdvSolver2d.h"
#include"SWEAbstract2d.h"

extern "C" {
	
}
class NdgPhysMat
{
public:
	NdgPhysMat();
	~NdgPhysMat();

	void matSolver();
	void matEvaluateSSPRK22();
	//double UpdateTimeInterval(double *fphys);



	void EvaluateSourceTerm(double *fphys);

	void UpdateExternalField(double *fphys);
	void EvaluateRHS(double *fphys);

	double* EvaluatePostFunc(double *fphys);

	void UpdateOutputResult(double time, double *fphys);


protected:

	SWEAbstract2d sweabstract2d;

	double *fext;
	int *outputfile;
	double *limiter;
	double *davectionSolver;
	double *viscositySolver;
	double *NonhydrostaticSolver;


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
	int Nvar;// dimension 

	NdgQuadFreeStrongFormAdvSolver2d ndgquadfreestrongformadvsolver2d;







};

