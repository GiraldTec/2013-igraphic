#pragma once

#include "PV3D.h"
#include "Pencil.h"

#include <vector>

class Polygon
{
private:
	int n_sides;
	PV3D* center;
	GLdouble radius;
	std::vector<PV3D*> *vertex;

public:
	Polygon(void);
	Polygon(PV3D *c,int n, GLdouble radius);
	~Polygon(void);

	vector<PV3D*> * getVertex(void);  
	void setVertex(vector<PV3D*> *v);
	PV3D * getCenter(void);
	void setCenter(PV3D *p);
	GLdouble getRadius(void);
	void setRadius(GLdouble r);

	void calcula_vertices(PV3D* centroTemp);
	void renderX(void);


};

