#pragma once
#include"NdgQuadFreeStrongFormAdvSolver2d.h"

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

	void UpdateExternalField(double tloc);

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

	//double ftime;

	double *frhs;
	double *fext;//
	double *fphys0;
	double *fphys;
	double *zGrad;


	int *Np;
	int *K;
	int Nfield;
	int *Nv;
	int Nvar;
	int *boundarydge_Nfp;
	int *boundarydge_Ne;
	//double gra;
	//double hmin;
	//int Np;// dimension 
	//int K;// dimension 
	//int Nfield;// dimension 
	//int Nvar;// dimension 

	NdgQuadFreeStrongFormAdvSolver2d ndgquadfreestrongformadvsolver2d;







};

