//Carlos Giraldo
//Raquel Peces
#include "Bola.h"

Bola::Bola(GLdouble r, GLdouble g, GLdouble b)
{
	Esfera *c=new Esfera(5.0,15,10);
	c->setColor(r,g,b);
	addComponente(c);
}


Bola::~Bola(void)
{
}
