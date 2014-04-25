#include "Cubo.h"


Cubo::Cubo(int x,int y,int z):
		Malla(2*(x+1)*(z+1)+(y-1)*(2*(x+z)),
				(x*y+x*z+y*z)*2,
					2*(x+1)*(z+1)+(y-1)*(2*(x+z)))  //TODO tb el color
{
	xDiv=x; 
	yDiv=y;
	zDiv=z;  // (Tapas Inf&Sup)+(Anillos interiores)

	// TODO new de los vectores
}


Cubo::~Cubo(void){ // TODO delete de los vectores
}

void Cubo::build(void){

}
