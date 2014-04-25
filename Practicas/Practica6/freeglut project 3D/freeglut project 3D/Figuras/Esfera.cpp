#include "Esfera.h"


Esfera::Esfera(void){
	rad=0.5;
	slices=10;
	stacks=10;
}

Esfera::Esfera(GLdouble r,GLint sl, GLint st){
	rad=r;
	slices=sl;
	stacks=st;
}


Esfera::~Esfera(void)
{
}
