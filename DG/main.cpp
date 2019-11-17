
#include"NdgPhysMat.h"
using namespace std;


MeshUnion mesh;
const MeshUnion *meshunion = &mesh;

int main()
{

	{

		for (int i = 0; i < 6; i++)
		{
			cout << *(meshunion->cell_p->FToV + i) << endl;
		}

		double xxxx = pow(5, 0.5);
		cout << xxxx << endl;
		NdgPhysMat x;
	}
	for (int i = 0; i < 4; i++)
	{
		cout << *(meshunion->inneredge_p->M + i) << endl;
	}


	cout << "hello";
	system("pause");
	return 0;
}

