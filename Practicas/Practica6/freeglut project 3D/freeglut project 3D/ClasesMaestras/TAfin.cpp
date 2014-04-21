#include "TAfin.h"


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


TAfin::~TAfin(void){}

GLfloat* TAfin::getM(){
	return m;
}