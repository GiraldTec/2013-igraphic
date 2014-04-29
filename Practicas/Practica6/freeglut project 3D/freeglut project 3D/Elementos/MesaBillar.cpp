#include "MesaBillar.h"


MesaBillar::MesaBillar(void){
	//Tablero
	Tablero *table = new Tablero();
	table->obTraslate(0.0,20.0,0.0);
	addComponente(table);

	// Patas
	Pata *p1=new Pata();
	p1->obTraslate(-57.0,20.0,120.0);
	p1->obRotate(90.0,0);
	addComponente(p1);
	
	Pata *p2=new Pata();
	p2->obTraslate(-57.5,20.0,-120.0);
	p2->obRotate(90.0,0);
	addComponente(p2);

	Pata *p3=new Pata();
	p3->obTraslate(57.5,20.0,120.0);
	p3->obRotate(90.0,0);
	addComponente(p3);

	Pata *p4=new Pata();
	p4->obTraslate(57.5,20.0,-120.0);
	p4->obRotate(90.0,0);
	addComponente(p4);
}


MesaBillar::~MesaBillar(void)
{
}
