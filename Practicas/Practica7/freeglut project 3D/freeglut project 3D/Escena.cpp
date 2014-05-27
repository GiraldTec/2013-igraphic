//Carlos Giraldo
//Raquel Peces
#include "Escena.h"


Escena::Escena(void){
			//Lampara
	
	lamp=new Lampara();
	lamp->obTraslate(0.0,150.0,0.0);
	addComponente(lamp);
	//Mesa
	MesaBillar *mesa = new MesaBillar();
	addComponente(mesa);
	//Bola Blanca
	Bola *bola = new Bola(1.0,1.0,1.0);
	bola->obTraslate(0.0,55.0,50.0);
	addComponente(bola);
	//Taco
	Taco *taco = new Taco();
	taco->obTraslate(-20.0,80.0,140.0);
	taco->obRotate(180.0,0);
	addComponente(taco);
	// CuboPequeño para la tiza
	Tiza *tiza = new Tiza();
	tiza->obTraslate(80.0,60.0,10.0);
	addComponente(tiza);	
	//Triangulo bolas
	TrianguloBolas *triangulo = new TrianguloBolas();
	triangulo->obTraslate(0.0,55.0,0.0);
	addComponente(triangulo);


}

Lampara* Escena::getLamp(void){
	return lamp;
}

Escena::~Escena(void)
{
}
