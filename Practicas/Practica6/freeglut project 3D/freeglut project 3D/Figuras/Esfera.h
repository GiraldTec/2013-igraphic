#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class Esfera : public ObjetoCuadrico
{
public:
	Esfera(void);
	~Esfera(void);
	void dibuja(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			glutSolidSphere(1.0,15,15); // .. por ejemplo
		glPopMatrix();
	}
};

