#include "Escena.h"


Escena::Escena(void){
	MesaBillar *mesa = new MesaBillar();
	mesa->obScale(0.06);
	addComponente(mesa);
	//Bolas
	//Taco
	// CuboPequeño para la tiza
}


Escena::~Escena(void)
{
}
