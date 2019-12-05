#include "NdgPhysMat.h"
#include"cblas.h"


//int NdgPhysMat::Np = 0;
//int NdgPhysMat::K = 0;
//int NdgPhysMat::Nfield = 0;


double *NdgPhysMat::fphys0 = NULL;
double *NdgPhysMat::fphys = NULL;


NdgPhysMat::NdgPhysMat() :ftime(10), time(0)
{
	int *Np = meshunion->cell_p->Np;
	int *K = meshunion->K;
	int Nfield = meshunion->Nfield;
	int *Nv = meshunion->cell_p->Nv;
	int Nvar = 3;
	int *boundarydge_Nfp = meshunion->boundarydge_p->Nfp;
	int *boundarydge_Ne = meshunion->boundarydge_p->Ne;

	requestmemory(&fphys0, Np, K, Nfield);//申请内存并初始化fphys0为0；
	requestmemory(&fphys, Np, K, Nfield);//申请内存并初始化fphys为0；

	requestmemory(&fext, boundarydge_Nfp, boundarydge_Ne, Nvar);
	requestmemory(&zGrad, Np, K, 2);

	//Nfield = 7;
	//Nvar = 3;

	//gra = 9.8;
	//hmin = 0.05;
	//Np = *meshunion->cell_p->Np;
	//K = *meshunion->K;

	//for (int i = 0; i < (*meshunion->cell->Np)*(*meshunion->K); i++)
	//{
	//	std::cout << *(fphys0 + i) << std::endl;
	//}
}


NdgPhysMat::~NdgPhysMat()
{
	freememory(&fphys);
	freememory(&fphys0);

	freememory(&fext);
	freememory(&zGrad);

	//freememory(&dx);
	std::cout << "析构NdgPhyMat" << std::endl;

}


void NdgPhysMat::matSolver()
{
	matEvaluateSSPRK22();
}


void NdgPhysMat::matEvaluateSSPRK22()
{

	//fphys0{n} = zeros( obj.meshUnion(n).cell.Np, obj.meshUnion(n).K, obj.Nvar );
	int *Np = meshunion->cell_p->Np;
	int *K = meshunion->K;
	int Nfield = meshunion->Nfield;
	//std::cout << "Nfield:" << Nfield;
	int *Nv = meshunion->cell_p->Nv;
	int Nvar = 3;


	//requestmemory(&fphys0, Np, K, Nfield);//申请内存并初始化fphys0为0；
	//requestmemory(&fphys, Np, K, Nfield);//申请内存并初始化fphys为0；
	//requestmemory(&frhs, Np, K, Nvar);//申请内存并初始化frhs为0；

	netCDF::NcFile dataFile("init_fphys.nc", netCDF::NcFile::read);
	netCDF::NcVar fphys_v = dataFile.getVar("fphys");
	fphys_v.getVar(fphys);
	netCDF::NcVar zGrad_v = dataFile.getVar("zGrad");
	zGrad_v.getVar(zGrad);
	//这一行需要给定fphys的初始场条件;
	double *frhs;
	//double time = 0;
	while (time < ftime)
	{
		for (int i = 0; i < 9; i++)
		{
			std::cout << i << "  " << fphys[i] << std::endl;
		}



		double dt = sweabstract2d.UpdateTimeInterval(fphys)*0.4;

		std::cout << "dt: " << dt << std::endl;
		if (time + dt > ftime)
		{
			dt = ftime - time;
		}

		//fphys0{ n } = fphys{ n };
		int num_fphys0 = (*K)*(*Nv)*Nvar;
		cblas_dcopy(num_fphys0, fphys, 1, fphys0, 1);//cblas拷贝函数

		for (int intRK = 0; intRK < 2; intRK++)
		{
			requestmemory(&frhs, Np, K, Nvar);//申请内存并初始化frhs为0；

			double tlol = time + dt;//tloc是否要是局部变量待确定。
			UpdateExternalField(fphys);
			EvaluateRHS(fphys, frhs);




			//fphys{ n }(:, : , obj.varFieldIndex) ...
			//	= fphys{ n }(:, : , obj.varFieldIndex) + dt * obj.frhs{ n };

	/*		const int num = (*Np)*(*K)*Nvar;*/
			////const int dis1 = 1;
			////const int dis2 = 1;
			////const int alpha = 1;
			//double *frhs_temp;
			//requestmemory(&frhs_temp, Np, K, Nvar);
			//cblas_dcopy(num, frhs, 1, frhs_temp, 1);
			//cblas_dscal(num, dt, frhs_temp, 1);
			//cblas_daxpy(num, 1, frhs_temp, 1, fphys, 1);
			//freememory(&frhs_temp);


			const int num = (*K)*(*Np)*Nvar;
			cblas_daxpy(num, dt, frhs, 1, fphys, 1);




			sweconventional2d.EvaluatePostFunc(fphys);//Update status
			freememory(&frhs);
		}
		//freememory(&frhs);
		const int num = (*K)*(*Np)*Nvar;
		cblas_dscal(num, 0.5, fphys, 1);
		cblas_daxpy(num, 0.5, fphys0, 1, fphys, 1);



		//for (int i = 0; i < (*Np)*(*K) * 3; i++)
		//{
		//	*(fphys + i) = *(fphys0 + i)*0.5 + (*(fphys + i)*0.5);
		//};

		time = time + dt;
		//UpdateOutputResult(time, fphys);

		double timeRatio = time / ftime;
		std::cout << "__________finished__________: " << timeRatio << std::endl;
	}
}

//double NdgPhysMat::UpdateTimeInterval(double *fphys)
//{
//	dt = 0;
//	for (int i = 0; i < *meshunion->K; i++)
//	{
//		*(dx + i) = pow(*(meshunion->LAV + i), 0.5);
//	}
//	int N = *meshunion->cell->N;
//	double dtm = UpdateTimeInterval2d(hmin, gra, N, meshunion->status, fphys, dx, Np, K, Nfield);
//
//	if (dtm > 0)
//	{
//		dt = (dt < dtm/*  *cfl  */) ? dt : dtm;
//	}//如需改cfl.
//
//};//计算时间步长



void NdgPhysMat::EvaluateRHS(double *fphys, double *frhs)
{
	ndgquadfreestrongformadvsolver2d.evaluateAdvectionRHS(fphys, frhs, fext);
	//matEvaluateRHS(fphys);
	//NEED 


	sweabstract2d.EvaluateSourceTerm(fphys, frhs, zGrad);
	//for (int i = 0; i < 1080 * 3; i++)
	//{
	//	std::cout << i << "    " << frhs[i] << std::endl;
	//}

};



//void NdgPhysMat::UpdateOutputResult(double time, double *fphys) {};
void NdgPhysMat::UpdateExternalField(double *fphys)
{

};
//double* NdgPhysMat::EvaluatePostFunc(double *fphys) {};
//void NdgPhysMat::EvaluateSourceTerm(double *fphys) {};
