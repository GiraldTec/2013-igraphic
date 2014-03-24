#pragma once
#include "VerticeNormal.h"

#include <vector>
#include <iostream>

using namespace std;

class Cara
{
private:
	int numV;// Numero de Vertices de la cara

	std::vector<VerticeNormal*> *indicesVN;

public:
	Cara(int nV);
	int getNumV();
	int getNormalIndex(int i);
	int getVertexIndex(int i);
	void setIndicesVN(vector<VerticeNormal*> *array);
	~Cara(void);
};

