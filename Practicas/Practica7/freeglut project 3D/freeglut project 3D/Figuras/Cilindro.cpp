//Carlos Giraldo
//Raquel Peces
#include "Cilindro.h"


Cilindro::Cilindro(void){
	baseRadius = 0.5;
	topRadius = 0.5;
	height = 1.0;
	slices = 10;
	stacks = 10;
}

Cilindro::Cilindro(GLdouble b,GLdouble t,GLdouble h,GLint sl,GLint st){
	baseRadius = b;
	topRadius = t;
	height = h;
	slices = sl;
	stacks = st;
}

Cilindro::~Cilindro(void)
{
}
