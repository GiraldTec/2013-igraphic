#include "Escena.h"


Escena::Escena(void){
	MesaBillar *mesa = new MesaBillar();
	mesa->obScale(0.06);
	addComponente(mesa);
	//Bolas
	//Taco
	Taco *taco = new Taco();
	taco->obScale(0.08);
	taco->obTraslate(0.0,60.0,0.0);
	taco->obRotate(45.0,-1);
	addComponente(taco);
	// CuboPequeño para la tiza
	Tiza *tiza = new Tiza();
	tiza->obScale(0.1);
	tiza->obTraslate(80.0,60.0,10.0);
	addComponente(tiza);
}


Escena::~Escena(void)
{
}
