#include "BordeTronera.h"


BordeTronera::BordeTronera(GLdouble largo,GLint stacks){
	Cilindro *cOut =  new Cilindro(7.0,7.0,largo,15,stacks);
	cOut->obTraslate(0.0,0.0,-largo/2);
	cOut->obTraslate(25.0,-2.0,0.0);
	addComponente(cOut);

	Cubo *bA = new Cubo(13,5,stacks);
	bA->obTraslate(12.5,-3.0,0.0);
	bA->obScale(25.0,18.0,largo);
	addComponente(bA);

	Cubo *bB = new Cubo(13,5,stacks);
	bB->obTraslate(7.5,-14.5,0.0);
	bB->obScale(15.0,5.0,largo);
	addComponente(bB);

}



BordeTronera::~BordeTronera(void)
{
}
