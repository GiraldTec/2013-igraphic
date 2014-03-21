#include "VerticeNormal.h"


VerticeNormal::VerticeNormal(int v, int n)
{
	this->indexV = v;
	this->indexN = n;
}

int VerticeNormal::getNormal()
{
	return indexN;
}

int VerticeNormal::getVertex()
{
	return indexV;
}

VerticeNormal::~VerticeNormal(void)
{
}
