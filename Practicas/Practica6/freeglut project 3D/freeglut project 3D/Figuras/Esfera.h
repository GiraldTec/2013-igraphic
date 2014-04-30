//Carlos Giraldo
//Raquel Peces
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
	void obQdibuja(){
		gluSphere(q,rad,slices,stacks);
	}
};

