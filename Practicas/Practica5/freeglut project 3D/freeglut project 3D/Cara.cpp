#include "Cara.h"


Cara::Cara(int nV)
{
	this->numV = nV;
	this->indicesVN = new vector<VerticeNormal*>(numV);
}

int Cara::getNumV()
{
	return numV;
}

int Cara::getNormalIndex(int i)
{
	return indicesVN->at(i)->getNormal();
}

int Cara::getVertexIndex(int i)
{
	return indicesVN->at(i)->getVertex();
}

void Cara::setIndicesVN(vector<VerticeNormal*> *array)
{
	this->indicesVN = array;
}

Cara::~Cara(void)
{
}
