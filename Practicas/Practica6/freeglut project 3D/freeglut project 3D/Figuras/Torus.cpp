#include "Torus.h"


Torus::Torus(void){
	innerRadius=0.5;
	outerRadius=1.0;
	sides=10;
	rings=15;
}

Torus::Torus(GLdouble i,GLdouble o,GLint s,GLint r){
	innerRadius=i;
	outerRadius=o;
	sides=s;
	rings=r;
}


Torus::~Torus(void)
{
}
