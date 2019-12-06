#include"NdgPhysMat.h"
using namespace std;

MeshUnion mesh;
const MeshUnion *meshunion = &mesh;

int main()
{
	NdgPhysMat Solver;
	Solver.matSolver();

	cout << "hello";
	system("pause");
	return 0;
}

