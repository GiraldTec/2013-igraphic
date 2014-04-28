#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class Torus : public ObjetoCuadrico{
public:
	GLdouble innerRadius, outerRadius;
	GLint sides, rings;
	Torus(void);
	Torus(GLdouble i,GLdouble o,GLint s,GLint r);
	~Torus(void);
	void obQdibuja(){
		glutSolidTorus(innerRadius, outerRadius, sides, rings);
	}
};

