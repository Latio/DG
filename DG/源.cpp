#include<iostream>
#include <netcdfcpp.h>
#include<vector>

using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

//static const int NX = 6;
//static const int NY = 12;

static const int NC_ERR = 2;

int main()
{
	try
	{

		static int two=2;
		static int Ne_boundary;
		static int Nfp;

		NcFile dataFile("meshUnion.nc", NcFile::read);
		NcVar Ne_boundary_v = dataFile.getVar("BoundaryEdge_Ne");
		Ne_boundary_v.getVar(&Ne_boundary);

		NcVar Nfp_v = dataFile.getVar("InnerEdge_Nfp");
		Nfp_v.getVar(&Nfp);

		cout << Nfp<< endl;
		double *BoundaryEdge_M = new double[Nfp*Nfp];
		NcVar BoundaryEdge_M_v = dataFile.getVar("BoundaryEdge_M");
		BoundaryEdge_M_v.getVar(BoundaryEdge_M);

		double *BoundaryEdge_FToF = new double[2 * Ne_boundary];

	/*	vector<vector<double> >BoundaryEdge_FToF(2, vector<double>(Ne_boundary));*/

		//vector<double> BoundaryEdge_FToF(2 * Ne_boundary);
		NcVar BoundaryEdge_FToF_v = dataFile.getVar("BoundaryEdge_FToF");

		BoundaryEdge_FToF_v.getVar(BoundaryEdge_FToF);

		//cout << BoundaryEdge_FToF.size() << endl;
		//int dataIn[NX][NY];

		//NcFile dataFile("simple_xy.nc", NcFile::read);

		//NcVar data = dataFile.getVar("data");
		//if (data.isNull()) return NC_ERR;
		//data.getVar(dataIn);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < Ne_boundary; j++)
			{
				cout << *(BoundaryEdge_FToF++) << ",";
			}
			cout << endl;
		}
		for (int i = 0; i < Nfp*Nfp; i++)
			cout << *(BoundaryEdge_M++)<<"   ";
		cout << endl;	

	/*	for (int i = 0; i < BoundaryEdge_FToF.size(); i++)
		{
			cout << BoundaryEdge_FToF[i] << "; ";
		}*/

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

