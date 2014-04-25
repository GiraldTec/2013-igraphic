#include "Escena.h"


Escena::Escena(void){
	Tablero *table = new Tablero();
	addComponente(table);
}


Escena::~Escena(void)
{
}
