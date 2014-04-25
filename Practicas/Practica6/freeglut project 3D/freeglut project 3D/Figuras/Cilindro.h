#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class Cilindro : public ObjetoCuadrico{
public:
	GLdouble baseRadius,topRadius,height;
	GLint slices,stacks;
	Cilindro(void);
	Cilindro(GLdouble b,GLdouble t,GLdouble h,GLint sl,GLint st);
	~Cilindro(void);

	void dibuja(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			gluCylinder(q, baseRadius, topRadius, height, slices, stacks);
		glPopMatrix();
	}
};

