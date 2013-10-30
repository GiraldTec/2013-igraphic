#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>

class Point
{

private:
	GLdouble corX;
	GLdouble corY;

public:
	Point(void);
	~Point(void);
	Point(GLdouble x, GLdouble y);
	GLdouble GetX();
	GLdouble GetY();
	void setX(GLdouble x);
	void setY(GLdouble y);
};

