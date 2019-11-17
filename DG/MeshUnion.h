#pragma once

#include"BoundaryEdge.h"
#include"InnerEdge.h"
#include"Cell.h"


class MeshUnion
{
public:
	MeshUnion() ;

	~MeshUnion();

	friend class NdgQuadFreeStrongFormAdvSolver2d;
	
	InnerEdge inneredge;
	static InnerEdge *inneredge_p;

	BoundaryEdge boundarydge;
	static BoundaryEdge *boundarydge_p;

	Cell cell;
	static Cell *cell_p;
	//notice the order of definition,which will cause the of constructor. 

	static int*K;
	static int*Nv;
	static int Nfield;

	static double*charLength;
	static double*EToE;
	static double*EToF;
	static double*EToM;
	static double*EToR;
	static double*EToV;
	static double*ind;
	static double*J;
	//static double*K;
	static double*LAV;
	//static double*Nv;
	static double*rx;
	static double*ry;
	static double*rz;
	static double*status;
	static double*sx;
	static double*sy;
	static double*sz;
	static double*tx;
	static double*ty;
	static double*type;
	static double*tz;
	static double*vx;
	static double*vy;
	static double*vz;
	static double*x;
	static double*xc;
	static double*y;
	static double*yc;
	static double*z;
	static double*zc;
};


