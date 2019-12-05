#pragma once
#include"NdgQuadFreeStrongFormAdvSolver2d.h"
//#include"SWEAbstract2d.h"

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



	//void EvaluateSourceTerm(double *fphys);

	void UpdateExternalField(double *fphys);

	void EvaluateRHS(double *fphys, double *frhs);

	//double* EvaluatePostFunc(double *fphys);

	//void UpdateOutputResult(double time, double *fphys);


protected:

	SWEAbstract2d sweabstract2d;
	SWEConventional2d sweconventional2d;

	//double *fext;

	//int *outputfile;
	//double *limiter;
	//double *davectionSolver;
	//double *viscositySolver;
	//double *NonhydrostaticSolver;

	double ftime;
	double time;
	//double *frhs;
	double *fext;
	static double *fphys0;
	static double *fphys;
	double *zGrad;
	//double gra;
	//double hmin;
	//int Np;// dimension 
	//int K;// dimension 
	//int Nfield;// dimension 
	//int Nvar;// dimension 

	NdgQuadFreeStrongFormAdvSolver2d ndgquadfreestrongformadvsolver2d;







};

