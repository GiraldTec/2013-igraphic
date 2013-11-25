#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>


#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;

class PV2D
{

private:
	GLdouble corX;
	GLdouble corY;

public:
	PV2D(void);
	~PV2D(void);
	PV2D(GLdouble x, GLdouble y);
	PV2D(PV2D* a,PV2D* b);
	GLdouble getX();
	GLdouble getY();
	void setX(GLdouble x);
	void setY(GLdouble y);
	GLdouble distance(PV2D* p);
	PV2D* clone();
	void reflection(PV2D* normal);
	GLdouble scalarProduct(PV2D* vector);
	GLdouble calculateA(PV2D* normal);
	PV2D* factor(GLdouble f);
	PV2D* substract(PV2D* v);
	PV2D* add(PV2D* v);
	PV2D* doNormal();
	GLdouble calculateMod(void);
	PV2D* normalize(void);
};
