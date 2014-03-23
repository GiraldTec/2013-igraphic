#include "Cara.h"


Cara::Cara(void)
{
}

Cara::Cara(int numVertices, VerticeNormal** arrayVN){
	this->numVertices = numVertices;
	this->arrayVN = arrayVN;
}

int Cara::getIndiceNormalK(int i){
	return arrayVN[i]->getIndiceNormal();
}

int Cara::getIndiceVerticeK(int i){
	return arrayVN[i]->getIndiceVertice();
}