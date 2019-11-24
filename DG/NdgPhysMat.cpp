#include "NdgPhysMat.h"
#include"cblas.h"


//int NdgPhysMat::Np = 0;
//int NdgPhysMat::K = 0;
//int NdgPhysMat::Nfield = 0;


double *NdgPhysMat::fphys0 = NULL;
double *NdgPhysMat::fphys = NULL;


NdgPhysMat::NdgPhysMat()
{
	ftime = 10;//total simulation time;
	requestmemory(&fext, meshunion->boundarydge_p->Nfp, meshunion->boundarydge_p->Ne, meshunion->Nfield);

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
	freememory(&frhs);
	freememory(&fext);

	//freememory(&dx);
	std::cout << "����NdgPhyMat" << std::endl;

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
	int *Nv = meshunion->cell_p->Nv;
	int Nvar = 3;

	requestmemory(&fphys0, Np, K, Nfield);//�����ڴ沢��ʼ��fphys0Ϊ0��
	requestmemory(&fphys, Np, K, Nfield);//�����ڴ沢��ʼ��fphysΪ0��
	requestmemory(&frhs, Np, K, Nvar);//�����ڴ沢��ʼ��fphysΪ0��

 //��һ����Ҫ����fphys�ĳ�ʼ������;
	double time = 0;
	while (time < ftime)
	{
		double dt = sweabstract2d.UpdateTimeInterval(fphys)*0.4;

		if (time + dt > ftime)
		{
			dt = ftime - time;
		}

		//fphys0{ n } = fphys{ n };
		cblas_dcopy((*K)*(*Nv)*Nfield, fphys, 1, fphys0, 1);//cblas��������

		for (int intRK = 0; intRK < 2; intRK++)
		{
			double tlol = time + dt;//tloc�Ƿ�Ҫ�Ǿֲ�������ȷ����
			//UpdateExternalField(fphys);
			EvaluateRHS(fphys, frhs);

			//fphys{ n }(:, : , obj.varFieldIndex) ...
			//	= fphys{ n }(:, : , obj.varFieldIndex) + dt * obj.frhs{ n };

			const int num = (*Np)*(*K)*Nvar;
			//const int dis1 = 1;
			//const int dis2 = 1;
			//const int alpha = 1;
			double *frhs_temp;
			requestmemory(&frhs_temp, Np, K, Nvar);
			cblas_dcopy(num, frhs, 1, frhs_temp, 1);
			cblas_dscal(num, dt, frhs_temp, 1);
			cblas_daxpy(num, 1, frhs_temp, 1, fphys, 1);

			freememory(&frhs_temp);
			//fphys = EvaluatePostFunc(fphys);


		}

		for (int i = 0; i < (*Np)*(*K) * 3; i++)
		{
			*(fphys + i) = *(fphys0 + i)*0.5 + (*(fphys + i)*0.5);
		};

		time = time + dt;
		//UpdateOutputResult(time, fphys);

		double timeRatio = time / ftime;
	}
}
//
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
//	}//�����cfl.
//
//};//����ʱ�䲽��



void NdgPhysMat::EvaluateRHS(double *fphys, double *frhs)
{
	ndgquadfreestrongformadvsolver2d.evaluateAdvectionRHS(fphys, frhs, fext);
	//matEvaluateRHS(fphys);
	double *zGrad;
	sweabstract2d.EvaluateSourceTerm(fphys, frhs, zGrad);
};


void NdgPhysMat::UpdateOutputResult(double time, double *fphys) {};
void NdgPhysMat::UpdateExternalField(double *fphys) {};
double* NdgPhysMat::EvaluatePostFunc(double *fphys) {};
void NdgPhysMat::EvaluateSourceTerm(double *fphys) {};