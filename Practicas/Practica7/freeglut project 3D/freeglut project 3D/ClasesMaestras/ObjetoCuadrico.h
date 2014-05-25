//Carlos Giraldo
//Raquel Peces
#pragma once
#include "Objeto3D.h"

class ObjetoCuadrico : public Objeto3D{
private:
	GLfloat red,green,blue;
	bool isInside;
public:
	GLUquadricObj* q;
	ObjetoCuadrico(void);
	~ObjetoCuadrico(void);

	void setColor(GLfloat r,GLfloat g, GLfloat b);
	void setInside(void);
	void dibuja(void){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			glColor3f(red,green,blue);
			if(isInside) gluQuadricOrientation(q,GLU_INSIDE);
			obQdibuja();
		glPopMatrix();
	}

	virtual void obQdibuja()=0;
};

