//Carlos Giraldo
//Raquel Peces
#include "Tablero.h"


Tablero::Tablero(void){

	// Tapete
	Cubo *field = new Cubo(5);
	field->obTraslate(0.0,2.5,0.0);
	field->obScale(140.0,5.0,270.0);
	field->setColor(0.0,1.0,0.0);
	addComponente(field);

	Cubo *aF= new Cubo(5);
	aF->obTraslate(-75.0,2.5,70.0);
	aF->obScale(10.0,5.0,130.0);
	aF->setColor(0.0,1.0,0.0);
	addComponente(aF);

	Cubo *bF= new Cubo(5);
	bF->obTraslate(-75.0,2.5,-70.0);
	bF->obScale(10.0,5.0,130.0);
	bF->setColor(0.0,1.0,0.0);
	addComponente(bF);

	Cubo *cF= new Cubo(5);
	cF->obTraslate(75.0,2.5,70.0);
	cF->obScale(10.0,5.0,130.0);
	cF->setColor(0.0,1.0,0.0);
	addComponente(cF);

	Cubo *dF= new Cubo(5);
	dF->obTraslate(75.0,2.5,-70.0);
	dF->obScale(10.0,5.0,130.0);
	dF->setColor(0.0,1.0,0.0);
	addComponente(dF);

	Cubo *eF= new Cubo(5);
	eF->obTraslate(0.0,2.5,-140.0);
	eF->obScale(140.0,5.0,10.0);
	eF->setColor(0.0,1.0,0.0);
	addComponente(eF);
	
	Cubo *fF= new Cubo(5);
	fF->obTraslate(0.0,2.5,140.0);
	fF->obScale(140.0,5.0,10.0);
	fF->setColor(0.0,1.0,0.0);
	addComponente(fF);

	// Madera
	Cubo *table = new Cubo(5);
	table->obTraslate(0.0,-12.5,0.0);
	table->obScale(140.0,25.0,270.0);
	table->setColor(0.55,0.42,0.14);
	addComponente(table);

	Cubo *aT= new Cubo(5);
	aT->obTraslate(-75.0,-2.5,70.0);
	aT->obScale(10.0,5.0,130.0);
	aT->setColor(0.55,0.42,0.14);
	addComponente(aT);

	Cubo *bT= new Cubo(5);
	bT->obTraslate(-75.0,-2.5,-70.0);
	bT->obScale(10.0,5.0,130.0);
	bT->setColor(0.55,0.42,0.14);
	addComponente(bT);

	Cubo *cT= new Cubo(5);
	cT->obTraslate(75.0,-2.5,70.0);
	cT->obScale(10.0,5.0,130.0);
	cT->setColor(0.55,0.42,0.14);
	addComponente(cT);

	Cubo *dT= new Cubo(5);
	dT->obTraslate(75.0,-2.5,-70.0);
	dT->obScale(10.0,5.0,130.0);
	dT->setColor(0.55,0.42,0.14);
	addComponente(dT);

	Cubo *eT= new Cubo(5);
	eT->obTraslate(0.0,-2.5,-140.0);
	eT->obScale(140.0,5.0,10.0);
	eT->setColor(0.55,0.42,0.14);
	addComponente(eT);
	
	Cubo *fT= new Cubo(5);
	fT->obTraslate(0.0,-2.5,140.0);
	fT->obScale(140.0,5.0,10.0);
	fT->setColor(0.55,0.42,0.14);
	addComponente(fT);


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

	BordeMesa *bE1 = new BordeMesa(10.0,2,true);
	bE1->obTraslate(-80.0,10.0,0.0);
	bE1->obRotate(180.0,1);
	addComponente(bE1);

	BordeMesa *bC2 = new BordeMesa(130.0,10);
	bC2->obTraslate(-80.0,10.0,70);
	bC2->obRotate(180.0,1);
	addComponente(bC2);

	BordeMesa *bD1 = new BordeMesa(130.0,10);
	bD1->obTraslate(80.0,10.0,-70.0);
	addComponente(bD1);

	BordeMesa *bE2 = new BordeMesa(10.0,2,true);
	bE2->obTraslate(80.0,10.0,0.0);
	addComponente(bE2);

	BordeMesa *bD2 = new BordeMesa(130.0,10);
	bD2->obTraslate(80.0,10.0,70.0);
	addComponente(bD2);

	BordeTronera *bT1 = new BordeTronera();
	bT1->obTraslate(-70.0,10.0,135.0);
	bT1->obRotate(-90.0,1);
	addComponente(bT1);

	BordeTronera *bT2 = new BordeTronera();
	bT2->obTraslate(-70.0,10.0,-135.0);
	bT2->obRotate(-180.0,1);
	addComponente(bT2);

	BordeTronera *bT3 = new BordeTronera();
	bT3->obTraslate(70.0,10.0,135.0);
	addComponente(bT3);
	
	BordeTronera *bT4 = new BordeTronera();
	bT4->obTraslate(70.0,10.0,-135.0);
	bT4->obRotate(90.0,1);
	addComponente(bT4);
	//*/

	obTraslate(0.0,25.0,0.0);
}


Tablero::~Tablero(void)
{
}
