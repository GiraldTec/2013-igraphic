#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class Disco : public ObjetoCuadrico{
public:
	GLdouble innerRadius, outerRadius;
	GLint slices, rings;
	Disco(void);
	Disco(GLdouble i,GLdouble o,GLint s,GLint r);
	~Disco(void);

	void obQdibuja(){
		gluDisk(q, innerRadius, outerRadius, slices, rings);
	}
};

