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
}


Escena::~Escena(void)
{
}
