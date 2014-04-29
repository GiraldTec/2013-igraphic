#include "TrianguloBolas.h"


TrianguloBolas::TrianguloBolas(void)
{
	Bola *b1 = new Bola(1.0,0.84,0.0);
	b1->obTraslate(-10.0,0.0,0.0);
	addComponente(b1);

	Bola *b2 = new Bola(0.11,0.56,1.0);
	b2->obTraslate(10.0,0.0,-10.0);
	addComponente(b2);

	Bola *b3 = new Bola(1.0,0.0,0.0);
	b3->obTraslate(-5.0,0.0,-5.0);
	addComponente(b3);

	Bola *b4 = new Bola(0.62,0.12,0.94);
	b4->obTraslate(-10.0,0.0,-10.0);
	addComponente(b4);

	Bola *b5 = new Bola(1.0,0.64,0.0);
	b5->obTraslate(-20.0,0.0,-10.0);
	addComponente(b5);

	Bola *b6 = new Bola(0.19,0.8,0.19);
	b6->obTraslate(15.0,0.0,-5.0);
	addComponente(b6);

	Bola *b7 = new Bola(0.64,0.16,0.16);
	b7->obTraslate(5.0,0.0,5.0);
	addComponente(b7);

	Bola *b8 = new Bola(0.0,0.0,0.0);
	b8->obTraslate(0.0,0.0,0.0);
	addComponente(b8);

	Bola *b9 = new Bola(0.85,0.64,0.12);
	b9->obTraslate(0.0,0.0,10.0);
	addComponente(b9);

	Bola *b10 = new Bola(0.0,0.80,0.81);
	b10->obTraslate(5.0,0.0,-5.0);
	addComponente(b10);

	Bola *b11 = new Bola(0.98,0.5,0.44);
	b11->obTraslate(20.0,0.0,-10.0);
	addComponente(b11);

	Bola *b12 = new Bola(0.55,0.21,0.55);
	b1->obTraslate(-5.0,0.0,5.0);
	addComponente(b12);

	Bola *b13 = new Bola(1.0,0.27,0.0);
	b13->obTraslate(0.0,0.0,-10.0);
	addComponente(b13);

	Bola *b14 = new Bola(0.56,0.93,0.56);
	b14->obTraslate(-15.0,0.0,-5.0);
	addComponente(b14);

	Bola *b15 = new Bola(0.82,0.41,0.11);
	b15->obTraslate(10.0,0.0,0.0);
	addComponente(b15);
}


TrianguloBolas::~TrianguloBolas(void)
{
}
