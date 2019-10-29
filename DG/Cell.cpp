#include "Cell.h"
#include<netcdfcpp.h>

using namespace netCDF;


int *Cell::Nq = NULL;
int *Cell::Nv = NULL;

double *Cell::Dr = NULL;
double *Cell::Ds = NULL;
double *Cell::Dt = NULL;
double *Cell::EToV = NULL;
double *Cell::faceType = NULL;
double *Cell::Fmask = NULL;
double *Cell::invM = NULL;
double *Cell::LAV = NULL;
double *Cell::M = NULL;
double *Cell::N = NULL;
double *Cell::Nface = NULL;
double *Cell::Nfp = NULL;
double *Cell::Nfv = NULL;
double *Cell::Np = NULL;
//double *cell:: Nq = NULL;
//double *cell:: Nv = NULL;
double *Cell::r = NULL;
double *Cell::rq = NULL;
double *Cell::s = NULL;
double *Cell::sq = NULL;
double *Cell::t = NULL;
double *Cell::TNfp = NULL;
double *Cell::tq = NULL;
double *Cell::type = NULL;
double *Cell::V = NULL;
double *Cell::Vq = NULL;
double *Cell::vr = NULL;
double *Cell::vs = NULL;
double *Cell::vt = NULL;
double *Cell::wq = NULL;

Cell::Cell()
{
	MeshUnion_dim::ncvar_read(Nq, "cell_Nq", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(Nv, "cell_Nv", MeshUnion_dim::one);

	MeshUnion_dim::ncvar_read(Dr, "cell_Dr", MeshUnion_dim::Np, MeshUnion_dim::Np);
	MeshUnion_dim::MeshUnion_dim::ncvar_read(Ds, "cell_Ds", MeshUnion_dim::Np, MeshUnion_dim::Np);
	MeshUnion_dim::MeshUnion_dim::ncvar_read(Dt, "cell_Dt", MeshUnion_dim::Np, MeshUnion_dim::Np);
	MeshUnion_dim::MeshUnion_dim::ncvar_read(EToV, "cell_EToV", MeshUnion_dim::cell_Nv, MeshUnion_dim::two);
	MeshUnion_dim::MeshUnion_dim::ncvar_read(faceType, "cell_faceType", MeshUnion_dim::cell_Nv, MeshUnion_dim::one);
	MeshUnion_dim::MeshUnion_dim::ncvar_read(Fmask, "cell_Fmask", MeshUnion_dim::cell_Nv, MeshUnion_dim::Nfp);
	MeshUnion_dim::MeshUnion_dim::ncvar_read(invM, "cell_invM", MeshUnion_dim::Np, MeshUnion_dim::Np);
	MeshUnion_dim::MeshUnion_dim::ncvar_read(LAV, "cell_LAV", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(M, "cell_M", MeshUnion_dim::Np, MeshUnion_dim::Np);
	MeshUnion_dim::ncvar_read(N, "cell_N", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(Nface, "cell_Nface", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(Nfp, "cell_Nfp", MeshUnion_dim::one, MeshUnion_dim::cell_Nv);
	MeshUnion_dim::ncvar_read(Nfv, "cell_Nfv", MeshUnion_dim::cell_Nv, MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(Np, "cell_Np", MeshUnion_dim::one);
	//MeshUnion_dim::ncvar_read(cell_Nq, "cell_Nq", one);
	//MeshUnion_dim::ncvar_read(cell_Nv, "cell_Nv", one);
	MeshUnion_dim::ncvar_read(r, "cell_r", MeshUnion_dim::one, MeshUnion_dim::Np);
	MeshUnion_dim::ncvar_read(rq, "cell_rq", MeshUnion_dim::one, MeshUnion_dim::cell_Nq);
	MeshUnion_dim::ncvar_read(s, "cell_s", MeshUnion_dim::one, MeshUnion_dim::Np);
	MeshUnion_dim::ncvar_read(sq, "cell_sq", MeshUnion_dim::one, MeshUnion_dim::cell_Nq);
	MeshUnion_dim::ncvar_read(t, "cell_t", MeshUnion_dim::one, MeshUnion_dim::Np);
	MeshUnion_dim::ncvar_read(TNfp, "cell_TNfp", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(tq, "cell_tq", MeshUnion_dim::one, MeshUnion_dim::cell_Nq);
	MeshUnion_dim::ncvar_read(type, "cell_type", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(V, "cell_V", MeshUnion_dim::Np, MeshUnion_dim::Np);
	MeshUnion_dim::ncvar_read(Vq, "cell_Vq", MeshUnion_dim::Np, MeshUnion_dim::cell_Nq);
	MeshUnion_dim::ncvar_read(vr, "cell_vr", MeshUnion_dim::one, MeshUnion_dim::cell_Nv);
	MeshUnion_dim::ncvar_read(vs, "cell_vs", MeshUnion_dim::one, MeshUnion_dim::cell_Nv);
	MeshUnion_dim::ncvar_read(vt, "cell_vt", MeshUnion_dim::one, MeshUnion_dim::cell_Nv);
	MeshUnion_dim::ncvar_read(wq, "cell_wq", MeshUnion_dim::one, MeshUnion_dim::cell_Nq);
}


Cell::~Cell()
{
	delete Nq;
	delete Nv;
	delete Dr;
	delete Ds;
	delete Dt;
	delete EToV;
	delete faceType;
	delete Fmask;
	delete invM;
	delete LAV;
	delete M;
	delete N;
	delete Nface;
	delete Nfp;
	delete Nfv;
	delete Np;
	delete r;
	delete rq;
	delete s;
	delete sq;
	delete t;
	delete TNfp;
	delete tq;
	delete type;
	delete V;
	delete Vq;
	delete vr;
	delete vs;
	delete vt;
	delete wq;
	std::cout << "Îö¹¹MeshUnion_Cell" << std::endl;
}
