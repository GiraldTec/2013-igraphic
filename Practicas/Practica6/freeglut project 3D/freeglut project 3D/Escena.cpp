#include "Escena.h"


Escena::Escena(void){
	//Tablero *table = new Tablero();
	Cubo *cuadro = new Cubo(20,50,10);
	addComponente(cuadro);
}


Escena::~Escena(void)
{
}
