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





	cout << "hello";
	system("pause");
	return 0;
}

