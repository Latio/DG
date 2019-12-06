#include "NdgPhysMat.h"


NdgPhysMat::NdgPhysMat() :frhs(NULL)
{
	Np = meshunion->cell_p->Np;
	K = meshunion->K;
	Nv = meshunion->cell_p->Nv;
	boundarydge_Nfp = meshunion->boundarydge_p->Nfp;
	boundarydge_Ne = meshunion->boundarydge_p->Ne;
	Nfield = meshunion->Nfield;
	Nvar = 3;

	requestmemory(&fphys, Np, K, Nfield);
	requestmemory(&fphys0, Np, K, Nfield);
	requestmemory(&fext, boundarydge_Nfp, boundarydge_Ne, Nvar);
	requestmemory(&zGrad, Np, K, 2);
}


NdgPhysMat::~NdgPhysMat()
{
	freememory(&fphys);
	freememory(&fphys0);
	freememory(&fext);
	freememory(&zGrad);

	std::cout << "����NdgPhyMat" << std::endl;
}


void NdgPhysMat::matSolver()
{
	matEvaluateSSPRK22();
}


void NdgPhysMat::matEvaluateSSPRK22()
{
	netCDF::NcFile dataFile("init_fphys.nc", netCDF::NcFile::read);
	netCDF::NcVar fphys_v = dataFile.getVar("fphys");
	fphys_v.getVar(fphys);
	netCDF::NcVar zGrad_v = dataFile.getVar("zGrad");
	zGrad_v.getVar(zGrad);

	double time = 0;
	double ftime = 10;
	const int num = (*K)*(*Nv)*Nvar;

	while (time < ftime)
	{

		for (int i = 0; i < 3; i++)
		{
			std::cout << i << "  " << fphys[i] << std::endl;
		}

		double dt = sweabstract2d.UpdateTimeInterval(fphys)*0.4;
		if (time + dt > ftime)
		{
			dt = ftime - time;
		}
		std::cout << "dt: " << dt << std::endl;

		cblas_dcopy(num, fphys, 1, fphys0, 1);//fphys0{n} = fphys{n};

		for (int intRK = 0; intRK < 2; intRK++)
		{

			double tloc = time + dt;
			UpdateExternalField(tloc);

			requestmemory(&frhs, Np, K, Nvar);
			EvaluateRHS(fphys, frhs);

			//fphys{ n }(:, : , obj.varFieldIndex) ...
			//	= fphys{ n }(:, : , obj.varFieldIndex) + dt * obj.frhs{ n };
			//const int num = (*Np)*(*K)*Nvar;
			////const int dis1 = 1;
			////const int dis2 = 1;
			////const int alpha = 1;
			//double *frhs_temp;
			//requestmemory(&frhs_temp, Np, K, Nvar);
			//cblas_dcopy(num, frhs, 1, frhs_temp, 1);
			//cblas_dscal(num, dt, frhs_temp, 1);
			//cblas_daxpy(num, 1, frhs_temp, 1, fphys, 1);
			//freememory(&frhs_temp);

			cblas_daxpy(num, dt, frhs, 1, fphys, 1);

			sweconventional2d.EvaluatePostFunc(fphys);//Update status
			freememory(&frhs);
		}

		cblas_dscal(num, 0.5, fphys, 1);
		cblas_daxpy(num, 0.5, fphys0, 1, fphys, 1);



		time = time + dt;
		//UpdateOutputResult(time, fphys);

		double timeRatio = time / ftime;
		std::cout << "____________________finished____________________: " << timeRatio << std::endl;
	}
}


void NdgPhysMat::EvaluateRHS(double *fphys, double *frhs)
{
	ndgquadfreestrongformadvsolver2d.evaluateAdvectionRHS(fphys, frhs, fext);
	sweabstract2d.EvaluateSourceTerm(fphys, frhs, zGrad);
};



//void NdgPhysMat::UpdateOutputResult(double time, double *fphys) {};
void NdgPhysMat::UpdateExternalField(double tloc)
{

};
