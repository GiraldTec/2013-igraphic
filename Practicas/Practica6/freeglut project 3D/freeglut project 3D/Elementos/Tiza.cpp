#include "Tiza.h"


Tiza::Tiza(void)
{
	Cubo *a=new Cubo(3);
	a->obScale(2.0,1.8,2.0);
	a->setColor(1.0,1.0,1.0);
	addComponente(a);

	Cubo *b=new Cubo(3);
	b->obTraslate(0.0,1.8,0.0);
	b->obScale(2.0,0.2,2.0);
	b->setColor(0.0,0.0,1.0);
	addComponente(b);
}


Tiza::~Tiza(void)
{
}
