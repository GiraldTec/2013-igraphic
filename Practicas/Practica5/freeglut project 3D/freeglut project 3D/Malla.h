#pragma once
#include "PV3D.h"
#include "Cara.h"

#include <vector>
#include <iostream>

class Malla
{
private:
	int numVertex;
	int numFaces;
	int numNormals;
	
	std::vector<PV3D*> *vertex;
	std::vector<PV3D*> *normals;
	std::vector<Cara*> *faces;
	
public:

	Malla(int nV, int nF, int nN);
	~Malla(void);

	PV3D* doVectorNormalNewell(Cara* c);
};

