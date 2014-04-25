#include "Objeto3D.h"


Objeto3D::Objeto3D(void)
{
	ta = new TAfin();
}


Objeto3D::~Objeto3D(void)
{
	delete ta;
	ta=NULL;
}

void Objeto3D::obTraslate(GLfloat tX,GLfloat tY,GLfloat tZ){
	ta->taTraslate(tX,tY,tZ);
}

void Objeto3D::obScale(GLfloat s){
	ta->taScale(s,s,s);
}

void Objeto3D::obScale(GLfloat sX,GLfloat sY,GLfloat sZ){
	ta->taScale(sX,sY,sZ);
}

void Objeto3D::obRotate(GLfloat angle, int axis){
	if (axis<0){		ta->taRotate(angle,0.0,0.0,1.0); return;}	// <0 ~ Z
	if (axis==0){	ta->taRotate(angle,1.0,0.0,0.0); return;}	// =0 ~ X
	if (axis>0){		ta->taRotate(angle,0.0,1.0,0.0); return;}	// >0 ~ Y
}

//DEPRECATED
void Objeto3D::init(GLfloat sX,GLfloat sY,GLfloat sZ,GLfloat pX,GLfloat pY,GLfloat pZ,GLfloat aX,GLfloat aY,GLfloat aZ){  // ScaleXYZ PosXYZ AngXYZ
	ta = new TAfin(sX,sY,sZ,pX,pY,pZ,aX,aY,aZ);
}