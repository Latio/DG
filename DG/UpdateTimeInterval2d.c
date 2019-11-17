#include "SWE2d.h"
#include <math.h>

#ifdef _OPENMP
#include <omp.h>
#endif

void evaluateFlowRateByCellState(
	const NdgRegionType type,  ///< cell types
	const double h,            ///< water depth
	const double hu,           ///< flux
	const double hv,           ///< flux
	double* u,                 ///< velocity result
	double* v                  ///< velocity result
) {
	if (type == NdgRegionWet) {
		*u = hu / h;
		*v = hv / h;
	}
	else {
		*u = 0;
		*v = 0;
	}
	return;
}


double UpdateTimeInterval2d(double hmin, double gra, int N, double *status, double *fphys, double *dx, int *Np_, int *K_, int Nfield_)
{

	signed char* regionType = (signed char*)status;
	PhysField fphys_ = convertMexToPhysField(fphys, Np_, K_, Nfield_);

	const int Np = fphys_.Np;
	const int K = fphys_.K;

	double dt = 1e6;
	for (int k = 0; k < K; k++) {
		NdgRegionType type = (NdgRegionType)regionType[k];
		if (type == NdgRegionDry) {
			continue;
		}
		double dx_ = dx[k];
		for (int n = 0; n < Np; n++) {
			const int sk = k * Np + n;
			const double h_ = fphys_.h[sk];

			double u, v;
			evaluateFlowRateByCellState(type, h_, fphys_.hu[sk], fphys_.hv[sk], &u, &v);
			const double spe = sqrt(u * u + v * v);
			const double dtloc = dx_ / (spe + sqrt(gra * h_)) / (2 * N + 1);
			dt = min(dt, dtloc);
		}
	}

	return dt;
}

