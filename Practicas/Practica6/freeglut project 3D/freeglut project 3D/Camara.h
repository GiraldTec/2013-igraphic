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
	void desplazar(GLdouble x, GLdouble y, GLdouble z);
	void ortogonal();
	void perspectiva();
	void oblicua();
	void recorridoEje(GLdouble x, GLdouble y, GLdouble z);
	void giraX(GLdouble alfa);
	void giraY(GLdouble alfa);
	void giraZ(GLdouble alfa);
	void lateral();
	void cenital();
	void frontal();
	void esquina();
	
	void getCoordCam();
	void getMatriz();
	void fijarCam();
};

