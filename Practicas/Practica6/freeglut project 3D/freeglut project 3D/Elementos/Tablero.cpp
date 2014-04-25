#include "Tablero.h"


Tablero::Tablero(void){
	Tronera* a=new Tronera();
	a->obTraslate(-1.5,0.0,2.0);
	addComponente(a);
	Tronera* b=new Tronera();
	b->obTraslate(-1.5,0.0,0.0);
	addComponente(b);
	Tronera* c=new Tronera();
	c->obTraslate(-1.5,0.0,-2.0);
	addComponente(c);
	Tronera* d=new Tronera();
	d->obTraslate(1.5,0.0,2.0);
	addComponente(d);
	Tronera* e=new Tronera();
	e->obTraslate(1.5,0.0,0.0);
	addComponente(e);
	Tronera* f=new Tronera();
	f->obTraslate(1.5,0.0,-2.0);
	addComponente(f);
}


Tablero::~Tablero(void)
{
}
