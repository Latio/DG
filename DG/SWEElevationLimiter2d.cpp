#include "SWEElevationLimiter2d.h"



SWEElevationLimiter2d::SWEElevationLimiter2d()
{
	int Nv = *meshunion->Nv;
	int	Nv_cell = *meshunion->cell_p->Nv;
	int K = *meshunion->K;

	double *xc = meshunion->xc;
	double *yc = meshunion->yc;
	double *vx = meshunion->vx;
	double *vy = meshunion->vy;
	double *EToV = meshunion->EToV;

	requestmemory(&Nvc, Nv);

	double *v;
	requestmemory(&v, Nv_cell);

	for (int k = 0; k < K; k++)
	{
		double *temp_etov = EToV + k * Nv_cell;
		cblas_dcopy(Nv_cell, temp_etov, 1, v, 1);

		for (int i = 0; i < Nv_cell; i++)
		{
			Nvc[(int)v[i] - 1] = Nvc[(int)v[i] - 1] + 1;
		}
	}

	const int maxindex = cblas_idamax(Nv, Nvc, 1);
	Nvcmax = (int)Nvc[maxindex];

	freememory(&Nvc);

	requestmemory(&VToK, Nvcmax, Nv);
	requestmemory(&VToM, Nvcmax, Nv);
	requestmemory(&Nvc, Nv);

	double *ind;
	requestmemory(&ind, Nv_cell);

	for (int k = 0; k < K; k++)
	{
		double *temp_etov = EToV + k * Nv_cell;
		cblas_dcopy(Nv_cell, temp_etov, 1, v, 1);

		for (int n = 0; n < Nv_cell; n++)
		{
			ind[n] = Nvc[(int)v[n] - 1] + 1 + (v[n] - 1)*Nvcmax;
			VToK[(int)ind[n] - 1] = k + 1;
			VToM[(int)ind[n] - 1] = 1;
			Nvc[(int)v[n] - 1] = Nvc[(int)v[n] - 1] + 1;
		}

	}

	requestmemory(&VToW, Nvcmax, Nv);
	for (int n = 0; n < Nv; n++)
	{
		int nvcn = (int)Nvc[n];
		double *w;
		requestmemory(&w, nvcn);
		for (int m = 0; m < nvcn; m++)
		{
			int cellid = VToK[n*Nvcmax + m] - 1;
			int msehid = VToM[n*Nvcmax + m] - 1;
			double xc_ = xc[cellid];
			double yc_ = yc[cellid];

			w[m] = 1.0 / (pow(vx[n] - xc_, 2) + pow(vy[n] - yc_, 2));

		}

		double sum = cblas_dasum(nvcn, w, 1);

		for (int i = 0; i < nvcn; i++)
		{
			VToW[n*Nvcmax + i] = w[i] / sum;
		}


		freememory(&w);
	}

	freememory(&ind);
	freememory(&v);
}


SWEElevationLimiter2d::~SWEElevationLimiter2d()
{
	freememory(&Nvc);
	freememory(&VToK);
	freememory(&VToM);
	freememory(&VToW);

}

void SWEElevationLimiter2d::apply(double *fphys, int *Np, int *K)
{
	const int num = (*Np)*(*K);
	double *fphys_1 = fphys;
	double *fphys_4 = fphys + 3 * num;
	double *fphys_5 = fphys + 4 * num;
	cblas_dcopy(num, fphys_1, 1, fphys_5, 1);
	cblas_daxpy(num, 1, fphys_4, 1, fphys_5, 1);

};


void SWEElevationLimiter2d::matLimit(double *fphys, int fieldId)
{
	int K = *meshunion->K;
	int Np = *meshunion->cell_p->Np;
	double  *fvert, *fvmin, *fvmax, *cvar;

	requestmemory(&fvert, K);
	requestmemory(&fvmin, K);
	requestmemory(&fvmax, K);
	requestmemory(&cvar, K);

	EvaluateVertAverage(fphys, fieldId, fvert, fvmin, fvmax, cvar);
	double *fphys_field = fphys + (fieldId - 1)*K*Np;


	freememory(&fvert);
	freememory(&fvmin);
	freememory(&fvmax);
	freememory(&cvar);
};


void SWEElevationLimiter2d::EvaluateVertAverage(double *fphys, int fieldId, double *fvert, double *fvmin, double *fvmax, double *cvar)
{
	int *Nv = meshunion->Nv;
	int Np = *meshunion->cell_p->Np;
	int K = *meshunion->K;

	double *fphys_fieldId = fphys + (fieldId - 1) * K*Np;
	mesh.GetMeshAverageValue(fphys_fieldId, cvar);

	c_EvaluateVertAverage(cvar, Nv, Nvc, VToM, VToK, VToW, fvert, fvmin, fvmax, Nvcmax);

};

void  assembleVertexCellConnect()
{

};