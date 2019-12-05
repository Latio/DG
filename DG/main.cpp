#include"NdgPhysMat.h"
using namespace std;

MeshUnion mesh;
const MeshUnion *meshunion = &mesh;

int main()
{
	NdgPhysMat Solver;
	Solver.matSolver();


	//{

	//	for (int i = 0; i < 72; i++)
	//	{
	//		cout << *(meshunion->boundarydge_p->ftype + i) << endl;
	//	}

	//	double xxxx = pow(5, 0.5);
	//	cout << xxxx << endl;
	//	NdgPhysMat x;
	//	for (int i = 0; i < 1080; i++)
	//	{
	//		cout << *(x.fext + i) << endl;
	//	}
	//};
	//typedef enum {
	//	NdgRegionNormal = 1,
	//	NdgRegionRefine = 2,
	//	NdgRegionSponge = 3,
	//	NdgRegionWet = 4,
	//	NdgRegionDry = 5,
	//	NdgRegionPartialWet = 6,
	//	NdgRegionPartialWetFlood = 7,
	//	NdgRegionPartialWetDamBreak = 8
	//} test;
	//double *fphys;
	//requestmemory(&fphys, meshunion->cell_p->Nv, meshunion->K, meshunion->Nfield);

	//netCDF::NcFile dataFile("init_fphys.nc", netCDF::NcFile::read);
	//netCDF::NcVar fphys_v = dataFile.getVar("fphys");
	//fphys_v.getVar(fphys);

	//int j = 1;
	//for (int i = 0; i < (*meshunion->cell_p->Nv)*(*meshunion->K)*meshunion->Nfield; i++)
	//{

	//	cout << *(fphys + i) << "	" << j << endl;
	//	j++;
	//	if (j > 3)
	//	{
	//		j = 1;
	//	}
	//}



	//enum enumSWERegion {
	//	Sponge = 3, // % sponge cell
	//	Wet,		//well cell(SWE)
	//	Dry,		//dry cell(SWE)
	//	PartialWet,
	//	PartialWetFlood,
	//	PartialWetDamBreak
	//} ;

	//int xxx[10] = { 1,2,-3,4,-5,6,-7,8,9,10 };
	//signed char test[5];
	//bool b[5];
	//int hmin = 0;

	//for (int i = 0; i < 5; i++)
	//{

	//	b[i] = true;
	//	for (int j = 0; j < 2; j++)
	//	{
	//		if (xxx[i * 2 + j] < hmin)
	//		{
	//			b[i] = false;
	//			break;
	//		}

	//	}
	//}

	//for (int k = 0; k < 5; k++)
	//{
	//	if (b[k])
	//	{
	//		test[k] =(signed char)enumSWERegion::Wet;
	//	}
	//	else
	//	{
	//		test[k] = (signed char)enumSWERegion::Dry;
	//	}

	//	cout << (int)test[k] << endl;
	//}

	//signed char *xxx = meshunion->status;
	//signed char* regType = xxx;


	//int a = 0;
	//for (int i = 0; i < 360; i++)
	//{
	//	test type = (test)xxx[i];
	//	if (type == NdgRegionWet)
	//	{
	//		a++;
	//		//cout << "success" <<a <<"  "<< i<<endl;
	//		cout << int(xxx[i]) << "num:"<<i<<endl;
	//	}
	//}



	cout << "hello";
	system("pause");
	return 0;
}

