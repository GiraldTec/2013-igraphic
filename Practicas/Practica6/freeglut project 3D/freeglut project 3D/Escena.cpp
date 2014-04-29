#include "Escena.h"


Escena::Escena(void){
	Tablero *table = new Tablero();
	table->obScale(0.06);
	addComponente(table);

	/*BordeTronera *b = new BordeTronera();
	b->obScale(0.06);
	addComponente(b);*/
}


Escena::~Escena(void)
{
}
