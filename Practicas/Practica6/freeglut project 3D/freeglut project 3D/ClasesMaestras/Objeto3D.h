#pragma once
#include "TAfin.h"
class Objeto3D
{
public:
	TAfin *ta;

	Objeto3D(void);
	~Objeto3D(void);

	void obTraslate(GLfloat tX,GLfloat tY,GLfloat tZ);				
	void obScale(GLfloat s);		
	void obScale(GLfloat sX,GLfloat sY,GLfloat sZ);					
	void obRotate(GLfloat angle, int axis);		//0==X,1==Y,-1==Z	

	virtual void dibuja()=0;
	

	// Deprecated
	void init(GLfloat sX,GLfloat sY,GLfloat sZ,GLfloat pX,GLfloat pY,GLfloat pZ,GLfloat aX,GLfloat aY,GLfloat aZ);  // ScaleXYZ PosXYZ AngXYZ
};

