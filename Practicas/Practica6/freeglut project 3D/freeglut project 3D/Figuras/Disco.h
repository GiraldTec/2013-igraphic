#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class Disco : public ObjetoCuadrico
{
public:
	Disco(void);
	~Disco(void);

	void dibuja(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			// TODO poner el disco
		glPopMatrix();
	}
};

