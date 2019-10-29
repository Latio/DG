#include "InnerEdge.h"
#include<iostream>

double *InnerEdge::FToE = NULL;
double *InnerEdge::FToF = NULL;
double *InnerEdge::FToM = NULL;
double *InnerEdge::FToN1 = NULL;
double *InnerEdge::FToN2 = NULL;
double *InnerEdge::FToV = NULL;
double *InnerEdge::Js = NULL;
double *InnerEdge::LAV = NULL;
double *InnerEdge::M = NULL;
double *InnerEdge::Ne = NULL;
double *InnerEdge::Nfp = NULL;
double *InnerEdge::nx = NULL;
double *InnerEdge::ny = NULL;
double *InnerEdge::nz = NULL;
double *InnerEdge::r = NULL;

InnerEdge::InnerEdge()
{
	MeshUnion_dim::ncvar_read(FToE, "InnerEdge_FToE", MeshUnion_dim::Ne_inner, MeshUnion_dim::two);
	MeshUnion_dim::ncvar_read(FToF, "InnerEdge_FToF", MeshUnion_dim::Ne_inner, MeshUnion_dim::two);
	MeshUnion_dim::ncvar_read(FToM, "InnerEdge_FToM", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(FToN1, "InnerEdge_FToN1", MeshUnion_dim::Ne_inner, MeshUnion_dim::Nfp);
	MeshUnion_dim::ncvar_read(FToN2, "InnerEdge_FToN2", MeshUnion_dim::Ne_inner, MeshUnion_dim::Nfp);
	MeshUnion_dim::ncvar_read(FToV, "InnerEdge_FToV", MeshUnion_dim::Ne_inner, MeshUnion_dim::two);
	MeshUnion_dim::ncvar_read(Js, "InnerEdge_Js", MeshUnion_dim::Ne_inner, MeshUnion_dim::Nfp);
	MeshUnion_dim::ncvar_read(LAV, "InnerEdge_LAV", MeshUnion_dim::Ne_inner, MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(M, "InnerEdge_M", MeshUnion_dim::Nfp, MeshUnion_dim::Nfp);
	MeshUnion_dim::ncvar_read(Ne, "InnerEdge_Ne", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(Nfp, "InnerEdge_Nfp", MeshUnion_dim::one);
	MeshUnion_dim::ncvar_read(nx, "InnerEdge_nx", MeshUnion_dim::Ne_inner, MeshUnion_dim::Nfp);
	MeshUnion_dim::ncvar_read(ny, "InnerEdge_ny", MeshUnion_dim::Ne_inner, MeshUnion_dim::Nfp);
	MeshUnion_dim::ncvar_read(nz, "InnerEdge_nz", MeshUnion_dim::Ne_inner, MeshUnion_dim::Nfp);
	MeshUnion_dim::ncvar_read(r, "InnerEdge_r", MeshUnion_dim::one, MeshUnion_dim::Nfp);
}


InnerEdge::~InnerEdge()
{
	delete FToE;
	delete FToF;
	delete FToM;
	delete FToN1;
	delete FToN2;
	delete FToV;
	delete Js;
	delete LAV;
	delete M;
	delete Ne;
	delete Nfp;
	delete nx;
	delete ny;
	delete nz;
	delete r;
	std::cout << "Îö¹¹MeshUnion_InnerEdge" << std::endl;
}
