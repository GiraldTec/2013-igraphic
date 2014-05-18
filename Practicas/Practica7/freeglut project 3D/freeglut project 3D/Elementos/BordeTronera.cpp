//Carlos Giraldo
//Raquel Peces
#include "BordeTronera.h"


BordeTronera::BordeTronera(void){
	Cilindro *cOut1 =  new Cilindro(7.0,7.0,22.5,15,10);
	cOut1->obTraslate(35.0,-2.0,0.0);
	cOut1->setColor(0.0,0.0,0.0);
	addComponente(cOut1);

	Cilindro *cOut2 =  new Cilindro(7.0,7.0,22.5,15,10);
	cOut2->obTraslate(0.0,-2.0,35.0);
	cOut2->obRotate(90.0,1);
	cOut2->setColor(0.0,0.0,0.0);
	addComponente(cOut2);

	Torus *t=new Torus(7.0,12.5,15,15);
	t->obTraslate(22.5,-2.0,22.5);
	t->obRotate(90.0,0);
	t->setColor(0.0,0.0,0.0);
	addComponente(t);

	Cubo *bA = new Cubo(6,5,7);
	bA->obTraslate(22.5,-3.0,11.25);
	bA->obScale(25.0,18.0,22.5);
	bA->setColor(0.55,0.42,0.14);
	addComponente(bA);

	Cubo *bB = new Cubo(4,5,3);
	bB->obTraslate(5.0,-3.0,16.25);
	bB->obScale(10.0,18.0,12.5);
	bB->setColor(0.55,0.42,0.14);
	addComponente(bB);
	
	Cubo *bC = new Cubo(7,5,3);
	bC->obTraslate(11.25,-3.0,28.75);
	bC->obScale(22.5,18.0,12.5);
	bC->setColor(0.55,0.42,0.14);
	addComponente(bC);

	Cilindro *esq= new Cilindro(12.5,12.5,18.0,15,2);
	esq->obTraslate(22.5,-12.0,22.5);
	esq->obRotate(-90.0,0);
	esq->setColor(0.55,0.42,0.14);
	addComponente(esq);

	DiscoParcial *d1= new DiscoParcial(0.0,12.5,15,5,90.0,90.0);
	d1->obTraslate(22.5,-12.0,22.5);
	d1->obRotate(-90.0,0);
	d1->obTraslate(0.0,0.0,18.0);
	d1->setColor(0.55,0.42,0.14);
	addComponente(d1);

	DiscoParcial *d2= new DiscoParcial(0.0,12.5,15,5,180.0,90.0);
	d2->obTraslate(22.5,-12.0,22.5);
	d2->obRotate(-90.0,0);
	d2->obRotate(-180.0,1);
	d2->setColor(0.55,0.42,0.14);
	addComponente(d2);

	Cubo *bD = new Cubo(2,2,5);
	bD->obTraslate(17.5,-14.5,12.5);
	bD->obScale(15.0,5.0,25.0);
	bD->setColor(0.55,0.42,0.14);
	addComponente(bD);

	Cubo *bE = new Cubo(2,2,3);
	bE->obTraslate(5.0,-14.5,17.5);
	bE->obScale(10.0,5.0,15.0);
	bE->setColor(0.55,0.42,0.14);
	addComponente(bE);

}



BordeTronera::~BordeTronera(void)
{
}
