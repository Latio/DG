#include "MeshUnion.h"
#include<netcdfcpp.h>

using namespace netCDF;

double *MeshUnion::BoundaryEdge_FToE = NULL;
double *MeshUnion::BoundaryEdge_FToF = NULL;
double *MeshUnion::BoundaryEdge_FToM = NULL;
double *MeshUnion::BoundaryEdge_FToN1 = NULL;
double *MeshUnion::BoundaryEdge_FToN2 = NULL;
double *MeshUnion::BoundaryEdge_FToV = NULL;
double *MeshUnion::BoundaryEdge_ftype = NULL;
double *MeshUnion::BoundaryEdge_Js = NULL;
double *MeshUnion::BoundaryEdge_LAV = NULL;
double *MeshUnion::BoundaryEdge_M = NULL;
double *MeshUnion::BoundaryEdge_Ne = NULL;
double *MeshUnion::BoundaryEdge_Nfp = NULL;
double *MeshUnion::BoundaryEdge_nx = NULL;
double *MeshUnion::BoundaryEdge_ny = NULL;
double *MeshUnion::BoundaryEdge_nz = NULL;
double *MeshUnion::BoundaryEdge_r = NULL;
double *MeshUnion::BoundaryEdge_xb = NULL;
double *MeshUnion::BoundaryEdge_yb = NULL;
double *MeshUnion::cell_Dr = NULL;
double *MeshUnion::cell_Ds = NULL;
double *MeshUnion::cell_Dt = NULL;
double *MeshUnion::cell_EToV = NULL;
double *MeshUnion::cell_faceType = NULL;
double *MeshUnion::cell_Fmask = NULL;
double *MeshUnion::cell_invM = NULL;
double *MeshUnion::cell_LAV = NULL;
double *MeshUnion::cell_M = NULL;
double *MeshUnion::cell_N = NULL;
double *MeshUnion::cell_Nface = NULL;
double *MeshUnion::cell_Nfp = NULL;
double *MeshUnion::cell_Nfv = NULL;
double *MeshUnion::cell_Np = NULL;
//double *MeshUnion::cell_Nq = NULL;
//double *MeshUnion::cell_Nv = NULL;
double *MeshUnion::cell_r = NULL;
double *MeshUnion::cell_rq = NULL;
double *MeshUnion::cell_s = NULL;
double *MeshUnion::cell_sq = NULL;
double *MeshUnion::cell_t = NULL;
double *MeshUnion::cell_TNfp = NULL;
double *MeshUnion::cell_tq = NULL;
double *MeshUnion::cell_type = NULL;
double *MeshUnion::cell_V = NULL;
double *MeshUnion::cell_Vq = NULL;
double *MeshUnion::cell_vr = NULL;
double *MeshUnion::cell_vs = NULL;
double *MeshUnion::cell_vt = NULL;
double *MeshUnion::cell_wq = NULL;
double *MeshUnion::charLength = NULL;
double *MeshUnion::EToE = NULL;
double *MeshUnion::EToF = NULL;
double *MeshUnion::EToM = NULL;
double *MeshUnion::EToR = NULL;
double *MeshUnion::EToV = NULL;
double *MeshUnion::ind = NULL;
double *MeshUnion::InnerEdge_cell_Dr = NULL;
double *MeshUnion::InnerEdge_cell_Ds = NULL;
double *MeshUnion::InnerEdge_cell_Dt = NULL;
double *MeshUnion::InnerEdge_cell_faceType = NULL;
double *MeshUnion::InnerEdge_cell_Fmask = NULL;
double *MeshUnion::InnerEdge_cell_FToV = NULL;
double *MeshUnion::InnerEdge_cell_invM = NULL;
double *MeshUnion::InnerEdge_cell_LAV = NULL;
double *MeshUnion::InnerEdge_cell_M = NULL;
double *MeshUnion::InnerEdge_cell_N = NULL;
double *MeshUnion::InnerEdge_cell_Nface = NULL;
double *MeshUnion::InnerEdge_cell_Nfp = NULL;
double *MeshUnion::InnerEdge_cell_Nfv = NULL;
double *MeshUnion::InnerEdge_cell_Np = NULL;
double *MeshUnion::InnerEdge_cell_Nq = NULL;
double *MeshUnion::InnerEdge_cell_Nv = NULL;
double *MeshUnion::InnerEdge_cell_r = NULL;
double *MeshUnion::InnerEdge_cell_rq = NULL;
double *MeshUnion::InnerEdge_cell_s = NULL;
double *MeshUnion::InnerEdge_cell_sq = NULL;
double *MeshUnion::InnerEdge_cell_t = NULL;
double *MeshUnion::InnerEdge_cell_TNfp = NULL;
double *MeshUnion::InnerEdge_cell_tq = NULL;
double *MeshUnion::InnerEdge_cell_type = NULL;
double *MeshUnion::InnerEdge_cell_V = NULL;
double *MeshUnion::InnerEdge_cell_Vq = NULL;
double *MeshUnion::InnerEdge_cell_vr = NULL;
double *MeshUnion::InnerEdge_cell_vs = NULL;
double *MeshUnion::InnerEdge_cell_vt = NULL;
double *MeshUnion::InnerEdge_cell_wq = NULL;
double *MeshUnion::InnerEdge_FToE = NULL;
double *MeshUnion::InnerEdge_FToF = NULL;
double *MeshUnion::InnerEdge_FToM = NULL;
double *MeshUnion::InnerEdge_FToN1 = NULL;
double *MeshUnion::InnerEdge_FToN2 = NULL;
double *MeshUnion::InnerEdge_FToV = NULL;
double *MeshUnion::InnerEdge_Js = NULL;
double *MeshUnion::InnerEdge_LAV = NULL;
double *MeshUnion::InnerEdge_M = NULL;
double *MeshUnion::InnerEdge_Ne = NULL;
double *MeshUnion::InnerEdge_Nfp = NULL;
double *MeshUnion::InnerEdge_nx = NULL;
double *MeshUnion::InnerEdge_ny = NULL;
double *MeshUnion::InnerEdge_nz = NULL;
double *MeshUnion::InnerEdge_r = NULL;
double *MeshUnion::J = NULL;
//double *MeshUnion::K = NULL;
double *MeshUnion::LAV = NULL;
//double *MeshUnion::Nv = NULL;
double *MeshUnion::rx = NULL;
double *MeshUnion::ry = NULL;
double *MeshUnion::rz = NULL;
double *MeshUnion::status = NULL;
double *MeshUnion::sx = NULL;
double *MeshUnion::sy = NULL;
double *MeshUnion::sz = NULL;
double *MeshUnion::tx = NULL;
double *MeshUnion::ty = NULL;
double *MeshUnion::type = NULL;
double *MeshUnion::tz = NULL;
double *MeshUnion::vx = NULL;
double *MeshUnion::vy = NULL;
double *MeshUnion::vz = NULL;
double *MeshUnion::x = NULL;
double *MeshUnion::xc = NULL;
double *MeshUnion::y = NULL;
double *MeshUnion::yc = NULL;
double *MeshUnion::z = NULL;
double *MeshUnion::zc = NULL;


MeshUnion::MeshUnion()
{
	ncdim_read();

	ncvar_read(BoundaryEdge_FToE, "BoundaryEdge_FToE", Ne_boundary, two);
	ncvar_read(BoundaryEdge_FToF, "BoundaryEdge_FToF", Ne_boundary, two);
	ncvar_read(BoundaryEdge_FToM, "BoundaryEdge_FToM", Ne_boundary, two);
	ncvar_read(BoundaryEdge_FToN1, "BoundaryEdge_FToN1", Ne_boundary, Nfp);
	ncvar_read(BoundaryEdge_FToN2, "BoundaryEdge_FToN2", Ne_boundary, Nfp);
	ncvar_read(BoundaryEdge_FToV, "BoundaryEdge_FToV", Ne_boundary, two);
	ncvar_read(BoundaryEdge_ftype, "BoundaryEdge_ftype", one, Ne_boundary);
	ncvar_read(BoundaryEdge_Js, "BoundaryEdge_Js", Ne_boundary, Nfp);
	ncvar_read(BoundaryEdge_LAV, "BoundaryEdge_LAV", Ne_boundary, one);
	ncvar_read(BoundaryEdge_M, "BoundaryEdge_M", Nfp, Nfp);
	ncvar_read(BoundaryEdge_Ne, "BoundaryEdge_Ne", one);
	ncvar_read(BoundaryEdge_Nfp, "BoundaryEdge_Nfp", one);
	ncvar_read(BoundaryEdge_nx, "BoundaryEdge_nx", Ne_boundary, Nfp);
	ncvar_read(BoundaryEdge_ny, "BoundaryEdge_ny", Ne_boundary, Nfp);
	ncvar_read(BoundaryEdge_nz, "BoundaryEdge_nz", Ne_boundary, Nfp);
	ncvar_read(BoundaryEdge_r, "BoundaryEdge_r", one, Nfp);
	ncvar_read(BoundaryEdge_xb, "BoundaryEdge_xb", Ne_boundary, Nfp);
	ncvar_read(BoundaryEdge_yb, "BoundaryEdge_yb", Ne_boundary, Nfp);
	ncvar_read(cell_Dr, "cell_Dr", Np, Np);
	ncvar_read(cell_Ds, "cell_Ds", Np, Np);
	ncvar_read(cell_Dt, "cell_Dt", Np, Np);
	ncvar_read(cell_EToV, "cell_EToV", cell_Nv, two);
	ncvar_read(cell_faceType, "cell_faceType", cell_Nv, one);
	ncvar_read(cell_Fmask, "cell_Fmask", cell_Nv, Nfp);
	ncvar_read(cell_invM, "cell_invM", Np, Np);
	ncvar_read(cell_LAV, "cell_LAV", one);
	ncvar_read(cell_M, "cell_M", Np, Np);
	ncvar_read(cell_N, "cell_N", one);
	ncvar_read(cell_Nface, "cell_Nface", one);
	ncvar_read(cell_Nfp, "cell_Nfp", one, cell_Nv);
	ncvar_read(cell_Nfv, "cell_Nfv", cell_Nv, one);
	ncvar_read(cell_Np, "cell_Np", one);
	//ncvar_read(cell_Nq, "cell_Nq", one);
	//ncvar_read(cell_Nv, "cell_Nv", one);
	ncvar_read(cell_r, "cell_r", one, Np);
	ncvar_read(cell_rq, "cell_rq", one, cell_Nq);
	ncvar_read(cell_s, "cell_s", one, Np);
	ncvar_read(cell_sq, "cell_sq", one, cell_Nq);
	ncvar_read(cell_t, "cell_t", one, Np);
	ncvar_read(cell_TNfp, "cell_TNfp", one);
	ncvar_read(cell_tq, "cell_tq", one, cell_Nq);
	ncvar_read(cell_type, "cell_type", one);
	ncvar_read(cell_V, "cell_V", Np, Np);
	ncvar_read(cell_Vq, "cell_Vq", Np, cell_Nq);
	ncvar_read(cell_vr, "cell_vr", one, cell_Nv);
	ncvar_read(cell_vs, "cell_vs", one, cell_Nv);
	ncvar_read(cell_vt, "cell_vt", one, cell_Nv);
	ncvar_read(cell_wq, "cell_wq", one, cell_Nq);
	ncvar_read(charLength, "charLength", K, one);
	ncvar_read(EToE, "EToE", K, cell_Nv);
	ncvar_read(EToF, "EToF", K, cell_Nv);
	ncvar_read(EToM, "EToM", K, cell_Nv);
	ncvar_read(EToR, "EToR", one, K);
	ncvar_read(EToV, "EToV", K, cell_Nv);
	ncvar_read(ind, "ind", one);
	ncvar_read(InnerEdge_cell_Dr, "InnerEdge_cell_Dr", Nfp, Nfp);
	ncvar_read(InnerEdge_cell_Ds, "InnerEdge_cell_Ds", Nfp, Nfp);
	ncvar_read(InnerEdge_cell_Dt, "InnerEdge_cell_Dt", Nfp, Nfp);
	ncvar_read(InnerEdge_cell_faceType,"InnerEdge_cell_faceType", one, two);
	ncvar_read(InnerEdge_cell_Fmask, "InnerEdge_cell_Fmask", two, one);
	ncvar_read(InnerEdge_cell_FToV, "InnerEdge_cell_FToV", two, one);
	ncvar_read(InnerEdge_cell_invM, "InnerEdge_cell_invM", Nfp, Nfp);
	ncvar_read(InnerEdge_cell_LAV, "InnerEdge_cell_LAV", one);
	ncvar_read(InnerEdge_cell_M, "InnerEdge_cell_M", Nfp, Nfp);
	ncvar_read(InnerEdge_cell_N, "InnerEdge_cell_N", one);
	ncvar_read(InnerEdge_cell_Nface, "InnerEdge_cell_Nface", one);
	ncvar_read(InnerEdge_cell_Nfp, "InnerEdge_cell_Nfp", one, two);
	ncvar_read(InnerEdge_cell_Nfv, "InnerEdge_cell_Nfv", one, two);
	ncvar_read(InnerEdge_cell_Np, "InnerEdge_cell_Np", one);
	ncvar_read(InnerEdge_cell_Nq, "InnerEdge_cell_Nq", one);
	ncvar_read(InnerEdge_cell_Nv, "InnerEdge_cell_Nv", one);
	ncvar_read(InnerEdge_cell_r, "InnerEdge_cell_r", one, Nfp);
	ncvar_read(InnerEdge_cell_rq, "InnerEdge_cell_rq", one, Nfp);
	ncvar_read(InnerEdge_cell_s, "InnerEdge_cell_s", one, Nfp);
	ncvar_read(InnerEdge_cell_sq, "InnerEdge_cell_sq", one, Nfp);
	ncvar_read(InnerEdge_cell_t, "InnerEdge_cell_t", one, Nfp);
	ncvar_read(InnerEdge_cell_TNfp, "InnerEdge_cell_TNfp", one);
	ncvar_read(InnerEdge_cell_tq, "InnerEdge_cell_tq", one, Nfp);
	ncvar_read(InnerEdge_cell_type, "InnerEdge_cell_type", one);
	ncvar_read(InnerEdge_cell_V, "InnerEdge_cell_V", Nfp, Nfp);
	ncvar_read(InnerEdge_cell_Vq, "InnerEdge_cell_Vq", Nfp, Nfp);
	ncvar_read(InnerEdge_cell_vr, "InnerEdge_cell_vr", one, two);
	ncvar_read(InnerEdge_cell_vs, "InnerEdge_cell_vs", one, two);
	ncvar_read(InnerEdge_cell_vt, "InnerEdge_cell_vt", one, two);
	ncvar_read(InnerEdge_cell_wq, "InnerEdge_cell_wq", one, Nfp);
	ncvar_read(InnerEdge_FToE, "InnerEdge_FToE", Ne_inner, two);
	ncvar_read(InnerEdge_FToF, "InnerEdge_FToF", Ne_inner, two);
	ncvar_read(InnerEdge_FToM, "InnerEdge_FToM", one);
	ncvar_read(InnerEdge_FToN1, "InnerEdge_FToN1", Ne_inner, Nfp);
	ncvar_read(InnerEdge_FToN2, "InnerEdge_FToN2", Ne_inner, Nfp);
	ncvar_read(InnerEdge_FToV, "InnerEdge_FToV", Ne_inner, two);
	ncvar_read(InnerEdge_Js, "InnerEdge_Js", Ne_inner, Nfp);
	ncvar_read(InnerEdge_LAV, "InnerEdge_LAV", Ne_inner, one);
	ncvar_read(InnerEdge_M, "InnerEdge_M", Nfp, Nfp);
	ncvar_read(InnerEdge_Ne, "InnerEdge_Ne", one);
	ncvar_read(InnerEdge_Nfp, "InnerEdge_Nfp", one);
	ncvar_read(InnerEdge_nx, "InnerEdge_nx", Ne_inner, Nfp);
	ncvar_read(InnerEdge_ny, "InnerEdge_ny", Ne_inner, Nfp);
	ncvar_read(InnerEdge_nz, "InnerEdge_nz", Ne_inner, Nfp);
	ncvar_read(InnerEdge_r, "InnerEdge_r", one, Nfp);
	ncvar_read(J, "J", K, Np);
	//ncvar_read(K, "K", one);
	ncvar_read(LAV, "LAV", K, one);
	//ncvar_read(Nv, "Nv", one);
	ncvar_read(rx, "rx", K, Np);
	ncvar_read(ry, "ry", K, Np);
	ncvar_read(rz, "rz", K, Np);
	ncvar_read(status, "status", K, one);
	ncvar_read(sx, "sx", K, Np);
	ncvar_read(sy, "sy", K, Np);
	ncvar_read(sz, "sz", K, Np);
	ncvar_read(tx, "tx", K, Np);
	ncvar_read(ty, "ty", K, Np);
	ncvar_read(type, "type", one);
	ncvar_read(tz, "tz", K, Np);
	ncvar_read(vx, "vx", one, Nv);
	ncvar_read(vy, "vy", one, Nv);
	ncvar_read(vz, "vz", one, Nv);
	ncvar_read(x, "x", K, Np);
	ncvar_read(xc, "xc", K, one);
	ncvar_read(y, "y", K, Np);
	ncvar_read(yc, "yc", K, one);
	ncvar_read(z, "z", K, Np);
	ncvar_read(zc, "zc", K, one);

}


MeshUnion::~MeshUnion()
{
}

void MeshUnion::ncdim_read()
{
	NcFile dataFile("meshUnion.nc", NcFile::read);

	NcVar K_v = dataFile.getVar("K");
	NcVar Nv_v = dataFile.getVar("Nv");
	NcVar Ne_inner_v = dataFile.getVar("InnerEdge_Ne");
	NcVar Ne_boundary_v = dataFile.getVar("BoundaryEdge_Ne");
	NcVar Nfp_v = dataFile.getVar("InnerEdge_Nfp");
	NcVar Np_v = dataFile.getVar("cell_Np");
	NcVar cell_Nv_v = dataFile.getVar("cell_Nv");
	NcVar cell_Nq_v = dataFile.getVar("cell_Nq");

	Ne_boundary_v.getVar(&Ne_boundary);
	K_v.getVar(&K);
	Nv_v.getVar(&Nv);
	Ne_inner_v.getVar(&Ne_inner);
	Ne_boundary_v.getVar(&Ne_boundary);
	Nfp_v.getVar(&Nfp);
	Np_v.getVar(&Np);
	cell_Nv_v.getVar(&cell_Nv);
	cell_Nq_v.getVar(&cell_Nq);
}

void MeshUnion::ncvar_read(double *&meshunion_data, std::string ncvarname, int &dim1, int &dim2)
{
	//meshunion_data = new double[Ne_boundary*two];
	meshunion_data = new double[dim1*dim2];
	NcFile dataFile("meshUnion.nc", NcFile::read);

	NcVar temp_v = dataFile.getVar(ncvarname);

	temp_v.getVar(meshunion_data);
}

void MeshUnion::ncvar_read(double *&meshunion_data, std::string ncvarname, int &dim1)
{
	meshunion_data = new double[dim1];
	NcFile dataFile("meshUnion.nc", NcFile::read);

	NcVar temp_v = dataFile.getVar(ncvarname);

	temp_v.getVar(meshunion_data);
};