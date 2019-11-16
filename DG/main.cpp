
#include"NdgPhysMat.h"
using namespace std;


const MeshUnion mesh;
const MeshUnion *meshunion=&mesh;

int main()
{
	
	{	

		for (int i = 0; i < 6; i++)
		{
			cout << *(meshunion->cell->FToV+i) << endl;
		}

		double xxxx = pow(5, 0.5);
		cout << xxxx << endl;
	NdgPhysMat x;
	}

	cout << "hello";
	system("pause");
	return 0;
}

