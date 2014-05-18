//Carlos Giraldo
//Raquel Peces
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
	med->obRotate(180.0,1);
	addComponente(med);

	Disco *bot = new Disco(0.0,0.5,20,3);
	bot->obRotate(-90.0,0);
	addComponente(bot);

	red->setColor(0.0,0.0,0.0);
	sup->setColor(0.0,1.0,0.0);
	med->setColor(0.55,0.42,0.14);  // Sienna
	bot->setColor(0.0,0.0,0.0);

}


Tronera::~Tronera(void)
{
}
