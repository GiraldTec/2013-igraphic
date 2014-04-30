//Carlos Giraldo
//Raquel Peces
#include "TAfin.h"


TAfin::TAfin(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		m = new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

TAfin::~TAfin(void){
	delete m;
	m=NULL;
}

GLfloat* TAfin::getM(){
	return m;
}


void TAfin::taTraslate(GLfloat tX,GLfloat tY,GLfloat tZ){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(m);
		glTranslatef(tX,tY,tZ);
		glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

void TAfin::taScale(GLfloat sX,GLfloat sY,GLfloat sZ){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(m);
		glScalef(sX,sY,sZ);
		glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

void TAfin::taRotate(GLfloat a,GLfloat x,GLfloat y,GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(m);
		glRotatef(a,x,y,z);
		glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

//Deprecated
TAfin::TAfin(GLfloat sX,GLfloat sY,GLfloat sZ,GLfloat pX,GLfloat pY,GLfloat pZ,GLfloat aX,GLfloat aY,GLfloat aZ){  // ScaleXYZ PosXYZ AngXYZ
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScalef(sX,sY,sZ);
		glRotatef(aX,1.0,0.0,0.0); // Esta parte hay que arreglarla de alguna manera
		glRotatef(aY,0.0,1.0,0.0);
		glRotatef(aZ,0.0,0.0,1.0);
		glTranslatef(pX,pY,pZ);
		m = new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}