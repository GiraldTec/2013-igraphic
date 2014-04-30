//Carlos Giraldo
//Raquel Peces
#pragma once
#include "../ClasesMaestras/ObjetoCuadrico.h"

class DiscoParcial: public ObjetoCuadrico{
public:
	GLdouble innerRadius, outerRadius,startAngle,sweepAngle;
	GLint slices, rings;
	DiscoParcial(void);
	DiscoParcial(GLdouble i,GLdouble o,GLint s,GLint r,GLdouble sA,GLdouble sW);
	~DiscoParcial(void);
	void obQdibuja(){
		gluPartialDisk(q, innerRadius, outerRadius, slices, rings,startAngle,sweepAngle);
	}
};

