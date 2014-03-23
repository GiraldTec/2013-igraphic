#pragma once
#include "VerticeNormal.h"

class Cara
{
private:
	int numVertices;
	VerticeNormal** arrayVN;

public:
	Cara(void);
	Cara(int numVertices, VerticeNormal** arrayVN);
	~Cara(void){};

	int getNumVertices(){return numVertices;};
	int getIndiceNormalK(int i);
	int getIndiceVerticeK(int i);
};

