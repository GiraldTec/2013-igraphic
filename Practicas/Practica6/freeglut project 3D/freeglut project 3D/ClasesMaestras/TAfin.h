#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>

class TAfin
{
private:
	GLfloat *m;
public:
	TAfin(GLfloat sX,GLfloat sY,GLfloat sZ,GLfloat pX,GLfloat pY,GLfloat pZ,GLfloat aX,GLfloat aY,GLfloat aZ);  // ScaleXYZ PosXYZ AngXYZ
	~TAfin(void);

	GLfloat* getM();
};

