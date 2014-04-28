#include "Malla.h"


Malla::Malla(int nP, int nC, int nN){
	nPuntos=nP;
	nNormales=nN;
	nCaras=nC;

	this->puntos = new vector<PV3D*>(nPuntos);
	this->caras= new vector<Cara*>(nCaras);
	this->normales = new vector<PV3D*>(nNormales);

}


Malla::~Malla(void)
{
}
