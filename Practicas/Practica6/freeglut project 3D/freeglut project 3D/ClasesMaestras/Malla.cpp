#include "Malla.h"


Malla::Malla(int nP, int nC, int nN){
	nPuntos=nP;
	nNormales=nN;
	nCaras=nC;

	this->puntos = new vector<PV3D*>(nPuntos);
	this->caras= new vector<Cara*>(nCaras);
	this->normales = new vector<PV3D*>(nNormales);

}


Malla::~Malla(void){
	delete puntos;
	delete caras;
	delete normales;
}


PV3D* Malla::doVectorNormalNewell(Cara* c){
	GLdouble x = 0;
	GLdouble y = 0;
	GLdouble z = 0;
	PV3D* currentV;
	PV3D* nextV;
	for (int i=0; i<c->getNumV(); i++){
		currentV = puntos->at(c->getVertexIndex(i));
		nextV = puntos->at(c->getVertexIndex((i+1) % c->getNumV()) );
		x += (currentV->getY()-nextV->getY())*(currentV->getZ()+nextV->getZ());
		y += (currentV->getZ()-nextV->getZ())*(currentV->getX()+nextV->getX());
		z += (currentV->getX()-nextV->getX())*(currentV->getY()+nextV->getY());
	}
	PV3D* aux = new PV3D(x,y,z);
	aux->normalize();
	return aux;
}