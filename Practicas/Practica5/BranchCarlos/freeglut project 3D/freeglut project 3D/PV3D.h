#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

#include <cmath>

#include "Cara.h"

class PV3D
{

private:
	GLfloat x, y, z;
	int pv; // 0: vector 1: punto
	PV3D *t, *b, *n;
public:
	PV3D(void);
	PV3D(GLfloat x, GLfloat y, GLfloat z, int pv);
	~PV3D(void){};

	GLfloat getX(){return x;};
	GLfloat getY(){return y;};
	GLfloat getZ(){return z;};
	int getPV(){return pv;};
	void setX(GLfloat x){this->x = x;};
	void setY(GLfloat y){this->y = y;};
	void setZ(GLfloat z){this->z = z;};
	void setPV(int pv){this->pv = pv;};
	PV3D* getT(){return t;};
	PV3D* getB(){return b;};
	PV3D* getN(){return n;};

	GLfloat module(PV3D* v);
	PV3D* normaliza();
	PV3D* clona();
	GLfloat productoEscalar(PV3D* v);
	PV3D* productoVectorial(PV3D* v);
	PV3D* calculaValorFormula(float t);
	PV3D* calculaValorPrimDerivada(float t);
	PV3D* calculaValorSegDerivada(float t);
	PV3D* calculaT(PV3D* c);
	PV3D* calculaB(PV3D* c, PV3D* cc);
	PV3D* calculaN();
};