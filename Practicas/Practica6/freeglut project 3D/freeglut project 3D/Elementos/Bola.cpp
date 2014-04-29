#include "Bola.h"

Bola::Bola(){}

Bola::Bola(GLdouble r, GLdouble g, GLdouble b)
{
	Esfera *c=new Esfera(1.0,15,10);
	c->obTraslate(0.0,0.0,0.0);
	c->obScale(5.0,5.0,8.0);
	c->setColor(r,g,b);
	addComponente(c);
}


Bola::~Bola(void)
{
}
