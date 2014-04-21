#include "Cubo.h"


Cubo::Cubo(int n)  //TODO tb el color :Malla(r,g,b);
{
	nDiv = n;
	nCaras = n*n*6;
	nPuntos = (n-1)*(n-1)*6+n*4*2+(n-1)*4;

	// TODO new de los vectores
}


Cubo::~Cubo(void){ // TODO delete de los vectores
}
