#include "Malla.h"


Malla::Malla(int nV, int nF, int nN)
{
	this->numVertex = nV;
	this->numFaces = nF;
	this->numNormals = nN;

	this->vertex = new vector<PV3D*>();  
	this->faces = new vector<Cara*>();
	this->normals = new vector<PV3D*>();
}


Malla::~Malla(void)
{

}

PV3D* Malla::doVectorNormalNewell(Cara* c)
{
	GLdouble x = 0;
	GLdouble y = 0;
	GLdouble z = 0;
	PV3D* currentV;
	PV3D* nextV;
	for (int i=0; i<c->getNumV(); i++){
		currentV = vertex->at(c->getVertexIndex(i));
		nextV = vertex->at(c->getVertexIndex(i+1) % c->getNumV());
		x += (currentV->getY()-nextV->getY())*(currentV->getZ()+nextV->getZ());
		y += (currentV->getZ()-nextV->getZ())*(currentV->getX()+nextV->getX());
		z += (currentV->getX()-nextV->getX())*(currentV->getY()+nextV->getY());
	}
	PV3D* aux = new PV3D(x,y,z);
	return aux->normalize();
}
