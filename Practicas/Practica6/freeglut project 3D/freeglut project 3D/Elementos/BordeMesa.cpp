//Carlos Giraldo
//Raquel Peces
#include "BordeMesa.h"


BordeMesa::BordeMesa(GLdouble largo,GLint stacks,bool tronera){

	if(!tronera){
		Cilindro *cIn =  new Cilindro(5.0,5.0,largo,10,stacks);
		cIn->obTraslate(0.0,0.0,-largo/2);
		cIn->setColor(0.0,1.0,0.0);
		addComponente(cIn);

		DiscoParcial *dP1 = new DiscoParcial(0.0,5.0,10,3,180.0,180.0);
		dP1->obTraslate(0.0,0.0,-largo/2);
		dP1->setColor(0.0,1.0,0.0);
		addComponente(dP1);

		DiscoParcial *dP2 = new DiscoParcial(0.0,5.0,10,3,180.0,180.0);
		dP2->obTraslate(0.0,0.0,largo/2);
		dP2->setColor(0.0,1.0,0.0);
		addComponente(dP2);
	}

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
	
	cOut->setColor(0.0,0.0,0.0);
	bA->setColor(0.55,0.42,0.14);
	bB->setColor(0.55,0.42,0.14);
}


BordeMesa::~BordeMesa(void)
{
}
