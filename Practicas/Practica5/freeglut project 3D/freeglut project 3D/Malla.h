#pragma once
#include "PV3D.h"
#include "Cara.h"

#include <vector>
#include <iostream>

class Malla
{
public:
	int numVertices;
	int numCaras;
	int numNormales;
	
	std::vector<PV3D*> *vertices;
	std::vector<PV3D*> *normales;
	std::vector<Cara*> *caras;

	Malla(void);
	~Malla(void);
};

