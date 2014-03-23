/***********************************
*	Carlos Gabriel Giraldo García
*	Raquel Peces Muñoz
*	Práctica 4
*
************************************/
#pragma once

#define _USE_MATH_DEFINES

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>

#include <iostream>
#include <math.h>

class PV3D
{
private:
	GLdouble corX;
	GLdouble corY;
	GLdouble corZ;

public:
	
	PV3D(void);
	~PV3D(void);
	PV3D(GLdouble x, GLdouble y, GLdouble z);
	GLdouble getX();
	void setX(GLdouble x);
	GLdouble getY();
	void setY(GLdouble y);
	GLdouble getZ();
	void setZ (GLdouble z);

	PV3D* clone();
	PV3D* addition(PV3D* v);
	PV3D* subtraction(PV3D* v);
	PV3D* normalize();
	GLdouble magnitude();
	
};

