#include "Tronera.h"


Tronera::Tronera(void){	
	Cilindro *red=new Cilindro(0.5,0.5,2.0,20,30);
	red->obRotate(-90.0,0);
	addComponente(red);

	Disco *sup = new Disco(0.5,0.7,20,3);
	sup->obRotate(-90.0,0);
	sup->obTraslate(0.0,0.0,2.0);
	addComponente(sup);

	Disco *med = new Disco(0.5,0.7,20,3);
	med->obRotate(-90.0,0);
	med->obTraslate(0.0,0.0,1.0);
	addComponente(med);

	Disco *bot = new Disco(0.0,0.5,20,3);
	bot->obRotate(-90.0,0);
	addComponente(bot);

	/*Torus *borde = new Torus(0.5,1.1,10,10);
	borde->obRotate(-90.0,0);
	borde->obTraslate(0.0,0.0,2.0);
	borde->obRotate(45.0,0);
	addComponente(borde);*/
}


Tronera::~Tronera(void)
{
}
