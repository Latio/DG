#include"NdgPhysMat.h"
using namespace std;

MeshUnion mesh;
const MeshUnion *meshunion = &mesh;

int main()
{

	{

		for (int i = 0; i < 72; i++)
		{
			cout << *(meshunion->boundarydge_p->ftype + i) << endl;
		}

		double xxxx = pow(5, 0.5);
		cout << xxxx << endl;
		NdgPhysMat x;
		for (int i = 0; i < 1080; i++)
		{
			cout << *(x.fext + i) << endl;
		}
	};
	typedef enum {
		NdgRegionNormal = 1,
		NdgRegionRefine = 2,
		NdgRegionSponge = 3,
		NdgRegionWet = 4,
		NdgRegionDry = 5,
		NdgRegionPartialWet = 6,
		NdgRegionPartialWetFlood = 7,
		NdgRegionPartialWetDamBreak = 8
	} test;

	signed char *xxx = meshunion->status;
	signed char* regType = xxx;


	int a = 0;
	for (int i = 0; i < 360; i++)
	{
		test type = (test)xxx[i];
		if (type == NdgRegionWet)
		{
			a++;
			//cout << "success" <<a <<"  "<< i<<endl;
			cout << int(xxx[i]) << "num:"<<i<<endl;
		}
	}



	cout << "hello";
	system("pause");
	return 0;
}

