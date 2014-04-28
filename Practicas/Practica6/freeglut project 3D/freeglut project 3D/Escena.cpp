#include "Escena.h"


Escena::Escena(void){
	Tablero *table = new Tablero();
	table->obScale(0.06);
	addComponente(table);

	/*BordeMesa *b = new BordeMesa(140.0,30);
	b->obScale(0.06);
	addComponente(b);*/
}


Escena::~Escena(void)
{
}
