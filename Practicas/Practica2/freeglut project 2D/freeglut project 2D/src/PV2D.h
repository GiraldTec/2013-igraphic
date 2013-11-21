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
	GLdouble getX();
	GLdouble getY();
	void setX(GLdouble x);
	void setY(GLdouble y);
	GLdouble distance(PV2D* p);
	PV2D* clone();
	void reflection();
	PV2D* doNormal();
};
