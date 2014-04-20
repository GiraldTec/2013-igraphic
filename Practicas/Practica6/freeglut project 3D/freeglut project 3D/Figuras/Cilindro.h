#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class Cilindro : public ObjetoCuadrico
{
public:
	Cilindro(void);
	~Cilindro(void);

	void dibuja(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			glutSolidCylinder(0.5,1.0,15,15);
		glPopMatrix();
	}
};

