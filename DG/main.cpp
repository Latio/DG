#include"NdgPhysMat.h"
#include<time.h>


using namespace std;

MeshUnion mesh;
const MeshUnion *meshunion = &mesh;

int main()
{
	clock_t begintime, endtime;

	NdgPhysMat Solver;
	begintime = clock();
	Solver.matSolver();


	endtime = clock();

	for (int i = 0; i < 97; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << i << "is " << Solver.tidal[i * 3 + j] << "   ";
		}
		cout << endl;
	}

	cout << "\n\nRunning Time : " << endtime - begintime << " ms\n" << endl;
	cout << "hello";
	system("pause");
	return 0;

}
