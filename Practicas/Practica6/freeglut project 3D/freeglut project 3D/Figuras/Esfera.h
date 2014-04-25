#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class Esfera : public ObjetoCuadrico{
public:
	GLdouble rad;
	GLint slices;
	GLint stacks;;
	Esfera(void);
	Esfera(GLdouble r,GLint sl, GLint st);
	~Esfera(void);
	void dibuja(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			gluSphere(q,rad,slices,stacks);
		glPopMatrix();
	}
};

