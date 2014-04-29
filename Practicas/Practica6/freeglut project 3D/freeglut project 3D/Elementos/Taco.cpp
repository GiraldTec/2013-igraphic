#include "Taco.h"


Taco::Taco(void)
{
	Cilindro *a=new Cilindro(3.0,2.8,20.0,15,4);
	a->setColor(0.0,0.0,0.0);
	addComponente(a);

	Cilindro *b=new Cilindro(2.8,2.5,40.0,15,8);
	b->obTraslate(0.0,0.0,20.0);
	b->setColor(0.64,0.16,0.16);
	addComponente(b);

	Cilindro *c=new Cilindro(2.5,2.0,65.0,15,12);
	c->obTraslate(0.0,0.0,60.0);
	c->setColor(0.82,0.41,0.11);
	addComponente(c);

	Cilindro *d=new Cilindro(2.0,1.5,10.0,15,3);
	d->obTraslate(0.0,0.0,125.0);
	d->setColor(1.0,1.0,1.0);
	addComponente(d);

	Cilindro *e=new Cilindro(1.5,1.0,5.0,15,2);
	e->obTraslate(0.0,0.0,135.0);
	e->setColor(0.0,0.0,1.0);
	addComponente(e);
}


Taco::~Taco(void)
{
}
