#pragma once
#include "TAfin.h"
class Objeto3D
{
public:
	TAfin *ta;

	Objeto3D(void);
	~Objeto3D(void);

	void init(GLfloat sX,GLfloat sY,GLfloat sZ,GLfloat pX,GLfloat pY,GLfloat pZ,GLfloat aX,GLfloat aY,GLfloat aZ);  // ScaleXYZ PosXYZ AngXYZ
	
	virtual void dibuja()=0;
};

