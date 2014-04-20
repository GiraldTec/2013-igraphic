#include "Objeto3D.h"


Objeto3D::Objeto3D(void)
{
}


Objeto3D::~Objeto3D(void)
{
}

void Objeto3D::init(GLfloat sX,GLfloat sY,GLfloat sZ,GLfloat pX,GLfloat pY,GLfloat pZ,GLfloat aX,GLfloat aY,GLfloat aZ){  // ScaleXYZ PosXYZ AngXYZ
	ta = new TAfin(sX,sY,sZ,pX,pY,pZ,aX,aY,aZ);
}