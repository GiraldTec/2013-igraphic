//Carlos Giraldo
//Raquel Peces
#pragma once
#include "../ClasesMaestras/Objeto3D.h"

class Torus : public Objeto3D{
private:
	GLfloat red,green,blue;
public:
	GLdouble innerRadius, outerRadius;
	GLint sides, rings;
	Torus(void);
	Torus(GLdouble i,GLdouble o,GLint s,GLint r);
	~Torus(void);
	void setColor(GLfloat r,GLfloat g, GLfloat b);
	void dibuja(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			glColor3f(red,green,blue);
			glutSolidTorus(innerRadius, outerRadius, sides, rings);
		glPopMatrix();
	}
};

