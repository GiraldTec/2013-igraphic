//Carlos Giraldo
//Raquel Peces
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
	TAfin();
	~TAfin(void);

	void taTraslate(GLfloat tX,GLfloat tY,GLfloat tZ);//TODO
	void taScale(GLfloat sX,GLfloat sY,GLfloat sZ);//TODO
	void taRotate(GLfloat a,GLfloat x,GLfloat y,GLfloat z); //TODO
	
	GLfloat* multV4(GLfloat x,GLfloat y,GLfloat z,GLfloat w);

	GLfloat* getM();

	//Deprecated
	TAfin(GLfloat sX,GLfloat sY,GLfloat sZ,GLfloat pX,GLfloat pY,GLfloat pZ,GLfloat aX,GLfloat aY,GLfloat aZ);  // ScaleXYZ PosXYZ AngXYZ
};

