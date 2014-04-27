#pragma once

#include "PV3D.h"

class Camara
{
private:
	PV3D *eye, *look, *up;
	PV3D *n, *v, *u;

public:
	Camara(PV3D* eye, PV3D* look, PV3D* up);
	~Camara(void);

	void roll(GLdouble alfa);
	void yaw(GLdouble alfa);
	void pitch(GLdouble alfa);
	
	void getCoordCam();
	void getMatriz();
};

