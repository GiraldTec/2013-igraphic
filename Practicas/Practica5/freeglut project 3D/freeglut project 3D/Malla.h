#pragma once
#include "PV3D.h"
#include "Cara.h"

#include <vector>
#include <iostream>

using namespace std;

class Malla
{
protected:
	int numVertex;
	int numFaces;
	int numNormals;
	
	std::vector<PV3D*> *vertex;
	std::vector<PV3D*> *normals;
	std::vector<Cara*> *faces;
	
public:
	Malla();
	Malla(int nV, int nF, int nN);
	~Malla(void);
	virtual void draw(bool fill, bool drawN);
	virtual void build() = 0;
	PV3D* doVectorNormalNewell(Cara* c);
};

