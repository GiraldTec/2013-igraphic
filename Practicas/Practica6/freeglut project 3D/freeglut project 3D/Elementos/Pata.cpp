//Carlos Giraldo
//Raquel Peces
 #include "Pata.h"


Pata::Pata(void){
	Cilindro *a=new Cilindro(12.5,10.0,10.0,15,10);
	a->setColor(0.55,0.42,0.14);
	addComponente(a);

	Disco *i=new Disco(8.0,10.0,15,2);
	i->obTraslate(0.0,0.0,10.0);
	i->setColor(0.55,0.42,0.14);
	addComponente(i);
	
	Cilindro *b=new Cilindro(8.0,4.5,20.0,15,10);
	b->obTraslate(0.0,0.0,10.0);
	b->setColor(0.55,0.42,0.14);
	addComponente(b);

	Esfera *c=new Esfera(1.0,15,10);
	c->obTraslate(0.0,0.0,35.0);
	c->obScale(5.0,5.0,8.0);
	c->setColor(0.55,0.42,0.14);
	addComponente(c);
	
	Cilindro *d=new Cilindro(5.0,7.5,7.5,15,5);
	d->obTraslate(0.0,0.0,35.0);
	d->setColor(0.55,0.42,0.14);
	addComponente(d);
	
	Cilindro *e=new Cilindro(7.5,5.0,7.5,15,5);
	e->obTraslate(0.0,0.0,42.5);
	e->setColor(0.55,0.42,0.14);
	addComponente(e);

	Cilindro *f=new Cilindro(5.0,3.0,15.0,15,10);
	f->obTraslate(0.0,0.0,50.0);
	f->setColor(0.55,0.42,0.14);
	addComponente(f);

	Cilindro *g=new Cilindro(3.0,5.5,10.0,15,5);
	g->obTraslate(0.0,0.0,65.0);
	g->setColor(0.55,0.42,0.14);
	addComponente(g);

	Cubo *h=new Cubo(3);
	h->obTraslate(0.0,0.0,77.5);
	h->obScale(15.0,15.0,5.0);
	h->setColor(0.0,0.0,0.0);
	addComponente(h);

}


Pata::~Pata(void)
{
}
