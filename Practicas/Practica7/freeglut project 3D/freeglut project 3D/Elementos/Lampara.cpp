//Carlos Giraldo
//Raquel Peces
#include "Lampara.h"


Lampara::Lampara(void){

	// Base
	Cubo *base = new Cubo(5);
	base->obTraslate(0.0,0.0,2.5);
	base->obScale(30.0,30.0,5.0);
	base->setColor(1.0,1.0,1.0);
	addComponente(base);

	// Tubo
	Cilindro *a=new Cilindro(1.5,1.5,20.0,15,10);
	a->obTraslate(0.0,0.0,5.0);
	a->setColor(1.0,1.0,1.0);
	addComponente(a);

	// Cono
	Disco *d1=new Disco(1.5,7.5,15,2);
	d1->obTraslate(0.0,0.0,25.0);
	d1->obRotate(180.0,1);
	d1->setColor(1.0,1.0,1.0);
	addComponente(d1);

	Cilindro *b=new Cilindro(7.5,7.5,5.0,15,3);
	b->obTraslate(0.0,0.0,25.0);
	b->setColor(1.0,1.0,1.0);
	addComponente(b);

	Disco *d2=new Disco(0.0,7.5,15,2);
	d2->obTraslate(0.0,0.0,30.0);
	d2->setColor(1.0,1.0,1.0);
	addComponente(d2);

	Cilindro *c1=new Cilindro(7.5,30.0,15.0,15,5);
	c1->obTraslate(0.0,0.0,30.0);
	c1->setColor(1.0,1.0,1.0);
	addComponente(c1);

}


Lampara::~Lampara(void)
{
}
