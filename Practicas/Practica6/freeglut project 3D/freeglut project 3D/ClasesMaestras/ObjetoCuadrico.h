#pragma once
#include "Objeto3D.h"

class ObjetoCuadrico : public Objeto3D{
private:
	GLfloat red,green,blue;
public:
	GLUquadricObj* q;
	ObjetoCuadrico(void);
	~ObjetoCuadrico(void);

	void setColor(GLfloat r,GLfloat g, GLfloat b);
	void dibuja(void){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			glColor3f(red,green,blue);
			obQdibuja();
		glPopMatrix();
	}

	virtual void obQdibuja()=0;
};

