#include "SWEAbstract2d.h"

double SWEAbstract2d::gra = 9.8;
double SWEAbstract2d::hmin = 0.05;

SWEAbstract2d::SWEAbstract2d() :Nfield(7), Nvar(3)
{
}


SWEAbstract2d::~SWEAbstract2d()
{
}

void SWEAbstract2d::EvaluateSurfFlux(MeshUnion *mesh, double *nx, double *ny, double *fm, InnerEdge *edge)
{
	surfluxSolver_evaluate(hmin,gra,nx,ny,fm,mesh,edge)
};
