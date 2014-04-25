#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class Disco : public ObjetoCuadrico
{
public:
	GLdouble innerRadius, outerRadius;
	GLint slices, rings;
	Disco(void);
	Disco(GLdouble i,GLdouble o,GLint s,GLint r);
	~Disco(void);

	void dibuja(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			gluDisk(q, innerRadius, outerRadius, slices, rings);
		glPopMatrix();
	}
};

