#include "Disco.h"


Disco::Disco(void){
	innerRadius=0.5;
	outerRadius=1.0;
	slices=10;
	rings=5;
}

Disco::Disco(GLdouble i,GLdouble o,GLint s,GLint r){
	innerRadius=i;
	outerRadius=o;
	slices=s;
	rings=r;
}

Disco::~Disco(void)
{
}
