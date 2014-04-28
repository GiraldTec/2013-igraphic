#include "Tablero.h"


Tablero::Tablero(void){
	Cubo *field = new Cubo(5);
	field->obScale(140.0,10.0,270.0);
	addComponente(field);

	Cubo *a= new Cubo(5);
	a->obTraslate(-75.0,0.0,70.0);
	a->obScale(10.0,10.0,130.0);
	addComponente(a);

	Cubo *b= new Cubo(5);
	b->obTraslate(-75.0,0.0,-70.0);
	b->obScale(10.0,10.0,130.0);
	addComponente(b);

	Cubo *c= new Cubo(5);
	c->obTraslate(75.0,0.0,70.0);
	c->obScale(10.0,10.0,130.0);
	addComponente(c);

	Cubo *d= new Cubo(5);
	d->obTraslate(75.0,0.0,-70.0);
	d->obScale(10.0,10.0,130.0);
	addComponente(d);

	Cubo *e= new Cubo(5);
	e->obTraslate(0.0,0.0,-140.0);
	e->obScale(140.0,10.0,10.0);
	addComponente(e);
	
	Cubo *f= new Cubo(5);
	f->obTraslate(0.0,0.0,140.0);
	f->obScale(140.0,10.0,10.0);
	addComponente(f);
	// TRONERAS
	Tronera *t1 = new Tronera();
	t1->obTraslate(-75.0,0.0,140.0);
	t1->obScale(10.0);
	t1->obRotate(135.0,1);
	t1->obTraslate(0.0,-1.5,0.0);
	addComponente(t1);

	Tronera *t2 = new Tronera();
	t2->obTraslate(-75.0,0.0,0.0);
	t2->obScale(10.0);
	t2->obRotate(90.0,1);
	t2->obTraslate(0.0,-1.5,0.0);
	addComponente(t2);

	Tronera *t3 = new Tronera();
	t3->obTraslate(-75.0,0.0,-140.0);
	t3->obScale(10.0);
	t3->obRotate(45.0,1);
	t3->obTraslate(0.0,-1.5,0.0);
	addComponente(t3);

	Tronera *t4 = new Tronera();
	t4->obTraslate(75.0,0.0,140.0);
	t4->obScale(10.0);
	t4->obRotate(-135.0,1);
	t4->obTraslate(0.0,-1.5,0.0);
	addComponente(t4);

	Tronera *t5 = new Tronera();
	t5->obTraslate(75.0,0.0,0.0);
	t5->obScale(10.0);
	t5->obRotate(-90.0,1);
	t5->obTraslate(0.0,-1.5,0.0);
	addComponente(t5);

	Tronera *t6 = new Tronera();
	t6->obTraslate(75.0,0.0,-140.0);
	t6->obScale(10.0);
	t6->obRotate(-45.0,1);
	t6->obTraslate(0.0,-1.5,0.0);
	addComponente(t6);

	// Bordes de la mesa

	BordeMesa *bA = new BordeMesa(140.0,10);
	bA->obTraslate(0.0,10.0,-145.0);
	bA->obRotate(90.0,1);
	addComponente(bA);

	BordeMesa *bB = new BordeMesa(140.0,10);
	bB->obTraslate(0.0,10.0,145.0);
	bB->obRotate(-90.0,1);
	addComponente(bB);

	BordeMesa *bC1 = new BordeMesa(130.0,10);
	bC1->obTraslate(-80.0,10.0,-70);
	bC1->obRotate(180.0,1);
	addComponente(bC1);

	BordeTronera *bT1 = new BordeTronera(10.0,2);
	bT1->obTraslate(-80.0,10.0,0.0);
	bT1->obRotate(180.0,1);
	addComponente(bT1);

	BordeMesa *bC2 = new BordeMesa(130.0,10);
	bC2->obTraslate(-80.0,10.0,70);
	bC2->obRotate(180.0,1);
	addComponente(bC2);

	BordeMesa *bD1 = new BordeMesa(130.0,10);
	bD1->obTraslate(80.0,10.0,-70.0);
	addComponente(bD1);

	BordeTronera *bT2 = new BordeTronera(10.0,2);
	bT2->obTraslate(80.0,10.0,0.0);
	addComponente(bT2);

	BordeMesa *bD2 = new BordeMesa(130.0,10);
	bD2->obTraslate(80.0,10.0,70.0);
	addComponente(bD2);
}


Tablero::~Tablero(void)
{
}
