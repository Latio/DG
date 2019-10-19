//#include <iostream>
//#include <netcdfcpp.h>
//#include <vector>
//using namespace std;
//using namespace netCDF;
//using namespace netCDF::exceptions;
//
//static const int NX = 6;
//static const int NY = 12;
//
//static const int NC_ERR = 2;
//
//int main()
//{
//	int dataOut[NX][NY];
//
//	for (int i = 0; i < NX; i++)
//		for (int j = 0; j < NY; j++)
//			dataOut[i][j] = i * NY + j;
//
//	try
//	{
//		NcFile dataFile("simple_xy.nc", NcFile::replace);
//
//		NcDim xDim = dataFile.addDim("x", NX);
//		NcDim yDim = dataFile.addDim("y", NY);
//
//		vector<NcDim> dims;
//		dims.push_back(xDim);
//		dims.push_back(yDim);
//		NcVar data = dataFile.addVar("data", ncInt, dims);
//
//		data.putVar(dataOut);
//		system("pause");
//		return 0;
//	}
//	catch (NcException& e)
//	{
//		e.what();
//		return NC_ERR; 
//	}
//}

//DFSADF
#include<iostream>
#include <netcdfcpp.h>
using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

static const int NX = 6;
static const int NY = 12;

static const int NC_ERR = 2;

int main()
{
	try
	{
		int dataIn[NX][NY];

		NcFile dataFile("simple_xy.nc", NcFile::read);

		NcVar data = dataFile.getVar("data");
		if (data.isNull()) return NC_ERR;
		data.getVar(dataIn);

		for (int i = 0; i < NX; i++)
			for (int j = 0; j < NY; j++)
			{
				cout << dataIn[i][j] << endl;

			}

		system("pause");
		return 0;
	}
	catch (NcException& e)
	{
		e.what();
		cout << "FAILURE*************************************" << endl;
		return NC_ERR;
	}
}




//#include<cblas.h>   // <strong>����cblas.h�ļ��Ѿ�����������Ŀ¼�У�ֻ����˫���� </strong>
//#include<iostream>
//using namespace std;
//int main(void) {
//	const enum CBLAS_ORDER Order = CblasRowMajor;
//	const enum CBLAS_TRANSPOSE TransA = CblasNoTrans;
//	const enum CBLAS_TRANSPOSE TransB = CblasNoTrans;
//	const int M = 4;//A��������C������
//	const int N = 2;//B��������C������
//	const int K = 3;//A��������B������
//	const float alpha = 1;
//	const float beta = 0;
//	const int lda = K;//A����
//	const int ldb = N;//B����
//	const int ldc = N;//C����
//	const float A[K*M] = { 1,2,3,4,5,6,7,8,9,8,7,6 };
//	const float B[K*N] = { 5,4,3,2,1,0 };
//	float C[M*N];
//
//	cblas_sgemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
//
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cout << C[i*N + j] << "/t" << endl;
//		}
//	}
//	system("pause");
//
//	return EXIT_SUCCESS;
//}