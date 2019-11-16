#include "NdgPhysMat.h"
#include "NdgQuadFreeStrongFormAdvSolver2d.h"
#include"cblas.h"


//int NdgPhysMat::Np = 0;
//int NdgPhysMat::K = 0;
//int NdgPhysMat::Nfield = 0;
extern const MeshUnion *meshunion;

double *NdgPhysMat::fphys0 = NULL;
double *NdgPhysMat::fphys = NULL;
double NdgPhysMat::dt = 0;

NdgPhysMat::NdgPhysMat() :time(0)
{
	ftime = 10;//total simulation time;
	Nfield = 7;
	Nvar = 3;

	gra = 9.8;
	hmin = 0.05;
	Np = *meshunion->cell->Np;
	K = *meshunion->K;

	requestmemory(&dx, *meshunion->K);

	//for (int i = 0; i < (*meshunion->cell->Np)*(*meshunion->K); i++)
	//{
	//	std::cout << *(fphys0 + i) << std::endl;
	//}
}


NdgPhysMat::~NdgPhysMat()
{
	freememory(&fphys);
	freememory(&fphys0);
	freememory(&frhs);

	freememory(&dx);
	std::cout << "析构NdgPhyMat" << std::endl;

}


void NdgPhysMat::matSolver()
{
	matEvaluateSSPRK22();
}


void NdgPhysMat::matEvaluateSSPRK22()
{
	//fphys0{n} = zeros( obj.meshUnion(n).cell.Np, obj.meshUnion(n).K, obj.Nvar );
	requestmemory(&fphys0, meshunion->cell->Np, meshunion->K, Nfield);//申请内存并初始化fphys0为0；
	requestmemory(&fphys, meshunion->cell->Np, meshunion->K, Nfield);//申请内存并初始化fphys为0；
	requestmemory(&frhs, meshunion->cell->Np, meshunion->K, Nvar);//申请内存并初始化fphys为0；

 //这一行需要给定fphys的初始场条件;

	while (time < ftime)
	{
		dt = UpdateTimeInterval(fphys)*0.4;

		if (time + dt > ftime)
		{
			dt = ftime - time;
		}

		//fphys0{ n } = fphys{ n };
		cblas_dcopy((*meshunion->K)*(*meshunion->cell->Nv)*Nfield, fphys, 1, fphys0, 1);//cblas拷贝函数

		for (int intRK = 0; intRK < 2; intRK++)
		{
			double tlol = time + dt;//tloc是否要是局部变量待确定。
			//UpdateExternalField(fphys);
			EvaluateRHS(fphys);

			//for (int i = 0; i < (*meshunion->cell->Np)*(*meshunion->K) * 3; i++)
			//{
			//	*(fphys + i) = *(fphys + i) + dt * (*(frhs + i));
			//}



			fphys = EvaluatePostFunc(fphys);
		}

		for (int i = 0; i < (*meshunion->cell->Np)*(*meshunion->K) * 3; i++)
		{
			*(fphys + i) = *(fphys0 + i)*0.5 + (*(fphys + i)*0.5);
		};

		time = time + dt;
		//UpdateOutputResult(time, fphys);

		double timeRatio = time / ftime;
	}
}

double NdgPhysMat::UpdateTimeInterval(double *fphys)
{
	dt = 0;
	for (int i = 0; i < *meshunion->K; i++)
	{
		*(dx + i) = pow(*(meshunion->LAV + i), 0.5);
	}
	int N = *meshunion->cell->N;
	double dtm = UpdateTimeInterval2d(hmin, gra, N, meshunion->status, fphys, dx, Np, K, Nfield);

	if (dtm > 0)
	{
		dt = (dt < dtm/*  *cfl  */) ? dt : dtm;
	}//如需改cfl.

};//计算时间步长



void NdgPhysMat::EvaluateRHS(double *fphys)
{
	ndgquadfreestrongformadvsolver2d.evaluateAdvectionRHS(fphys, frhs);
	//matEvaluateRHS(fphys);
	//matEvaluateSourceTerm(fphys);
};


void NdgPhysMat::UpdateOutputResult(double time, double *fphys) {};
void NdgPhysMat::UpdateExternalField(double *fphys) {};
double* NdgPhysMat::EvaluatePostFunc(double *fphys) {};
void NdgPhysMat::EvaluateSourceTerm(double *fphys) {};