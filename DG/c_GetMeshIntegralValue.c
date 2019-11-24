/*
 * @file
 * Calculate the integral averaged value in each cells.
 *
 * @details
 * Calculate the cell intergal averaged values by the formula
 * \f$ \int_{\Omega_k} u dA = \sum_{n=1}^{N_q} w_n J_n u(\xi_n) \f$
 * where \f$ \xi_n \f$ is the Gauss quadrature points.
 *
 * @param[in] fvar The field value on each interpolation points in all elements
 * @param[in] wq The quadrature weights in each cell
 * @param[in] J The Jacobian determination on interpolation points in all
 * elements
 * @param[in] Vq The transform matrix to convert nodal values to quadrature
 * values
 * @return fint The integral values in each elements
 *
 * @code
 *  [ fint ] = mxGetMeshIntegralValue( fvar, wq, J, Vq )
 * @endcode
 *
 */
 //#include "mex.h"
#include <math.h>
#include<stdlib.h>
#include "cblas.h"


void myfree(double **pt)
{
	if (*pt != NULL)
	{
		free(*pt);
		*pt = NULL;
	}
};

//#if !defined(_WIN32)
//#define dgemm dgemm_
//#endif

#ifdef _OPENMP
#include <omp.h>
#endif

void c_GetMeshIntegralValue(double *nodeVal_, double *wq_, double *J_, double *Vq_, int *Np_, int *K_, int *Nq_, double *integralValue_)
{
	//void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {

	//	/* check input & output */
	//	if (nrhs != 4)
	//		mexErrMsgIdAndTxt("Matlab:mxGetIntegralValue:InvalidNumberInput",
	//			"4 inputs required.");
	//	if (nlhs != 1)
	//		mexErrMsgIdAndTxt("Matlab:mxGetIntegralValue:InvalidNumberOutput",
	//			"1 output required.");

		/* get inputs */
	double *fvar = nodeVal_;
	double *wq = wq_;
	double *J = J_;
	double *Vq = Vq_;

	/* get dimensions */
	int Np = *Np_; // number of interpolation points
	int Nq = *Nq_; // number of quadrature points
	int K = *K_;  // number of elements

	/* allocate output array */
	//plhs[0] = mxCreateDoubleMatrix((mwSize)1, (mwSize)K, mxREAL);
	double *fint = integralValue_;

	//const double one = 1;
	//const double zero = 0;
	//int one_ptrdiff = 1;
	//int Np_ptrdiff = Np;
	//int Nq_ptrdiff = Nq;
	//char *tran = "N";

	const enum CBLAS_ORDER Order = CblasColMajor;
	const enum CBLAS_TRANSPOSE TransA = CblasNoTrans;
	const enum CBLAS_TRANSPOSE TransB = CblasNoTrans;
	const int M = Nq;//A的行数，C的行数
	const int N = 1;//B的列数，C的列数
	const int K = Np;//A的列数，B的行数
	const double alpha = 1.0;
	const float beta = 0.0;
	const int lda = M;//A的行        
	const int ldb = K;//B的行
	const int ldc = M;//C的行   //如果列优先，分别写ABC的行

#ifdef _OPENMP
#pragma omp parallel for num_threads(DG_THREADS)
#endif

	for (int k = 0; k < K; k++) {
		//double Jq[Nq], fq[Nq];
		double *Jq = (double*)malloc(sizeof(double)*Nq);
		double *fq = (double*)malloc(sizeof(double)*Nq);

		// map the node values fvar to quadrature nodes by
		// \f$ fq = Vq * fvar \f$

		//cblas_dgemm(tran, tran, &Nq_ptrdiff, &one_ptrdiff, &Np_ptrdiff, &one, Vq,
		//	&Nq_ptrdiff, fvar + k * Np, &Np_ptrdiff, &zero, fq, &Nq_ptrdiff);
		cblas_dgemm(Order, TransA, TransB, M, N, K, alpha, Vq, lda, fvar + k * Np, ldb, beta, fq, ldc);

		//cblas_dgemm(tran, tran, &Nq_ptrdiff, &one_ptrdiff, &Np_ptrdiff, &one, Vq,
		//	&Nq_ptrdiff, J + k * Np, &Np_ptrdiff, &zero, Jq, &Nq_ptrdiff);
		cblas_dgemm(Order, TransA, TransB, M, N, K, alpha, Vq, lda, J + k * Np, ldb, beta, Jq, ldc);




		for (int n = 0; n < Nq; n++) {
			fint[k] += wq[n] * Jq[n] * fq[n];
		}

		myfree(&Jq);
		myfree(&fq);
	}
}


//void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
//    
//    /* check input & output */
//    if (nrhs != 4)
//        mexErrMsgIdAndTxt("Matlab:mxGetIntegralValue:InvalidNumberInput",
//                          "4 inputs required.");
//    if (nlhs != 1)
//        mexErrMsgIdAndTxt("Matlab:mxGetIntegralValue:InvalidNumberOutput",
//                          "1 output required.");
//    
//    /* get inputs */
//    double *fvar = mxGetPr(prhs[0]);
//    double *wq = mxGetPr(prhs[1]);
//    double *J = mxGetPr(prhs[2]);
//    double *Vq = mxGetPr(prhs[3]);
//    
//    /* get dimensions */
//    size_t Np = mxGetM(prhs[0]); // number of interpolation points
//    size_t Nq = mxGetM(prhs[3]); // number of quadrature points
//    size_t K = mxGetN(prhs[0]);  // number of elements
//    
//    /* allocate output array */
//    plhs[0] = mxCreateDoubleMatrix((mwSize)1, (mwSize)K, mxREAL);
//    double *fint = mxGetPr(plhs[0]);
//    
//    const double one = 1;
//    const double zero = 0;
//    ptrdiff_t one_ptrdiff = 1;
//    ptrdiff_t Np_ptrdiff = Np;
//    ptrdiff_t Nq_ptrdiff = Nq;
//    char *tran = "N";
//#ifdef _OPENMP
//#pragma omp parallel for num_threads(DG_THREADS)
//#endif
//    
//    for (int k = 0; k < K; k++) {
//        double Jq[Nq], fq[Nq];
//        
//        // map the node values fvar to quadrature nodes by
//        // \f$ fq = Vq * fvar \f$
//        dgemm(tran, tran, &Nq_ptrdiff, &one_ptrdiff, &Np_ptrdiff, &one, Vq,
//              &Nq_ptrdiff, fvar + k * Np, &Np_ptrdiff, &zero, fq, &Nq_ptrdiff);
//        dgemm(tran, tran, &Nq_ptrdiff, &one_ptrdiff, &Np_ptrdiff, &one, Vq,
//              &Nq_ptrdiff, J + k * Np, &Np_ptrdiff, &zero, Jq, &Nq_ptrdiff);
//        
//        for (int n = 0; n < Nq; n++) {
//            fint[k] += wq[n] * Jq[n] * fq[n];
//        }
//    }
//}
