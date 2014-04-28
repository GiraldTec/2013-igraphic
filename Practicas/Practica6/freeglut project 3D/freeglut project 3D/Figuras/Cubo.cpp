#include "Cubo.h"

Cubo::Cubo(int d):
		Malla(2*(d+1)*(d+1)+(d-1)*(2*(d+d)),
				(d*d+d*d+d*d)*2,
					2*(d+1)*(d+1)+(d-1)*(2*(d+d))){  //TODO tb el color
	xDiv=d; 
	yDiv=d;
	zDiv=d;  // (Tapas Inf&Sup)+(Anillos interiores)

	build();
}

Cubo::Cubo(int x,int y,int z):
		Malla(2*(x+1)*(z+1)+(y-1)*(2*(x+z)),
				(x*y+x*z+y*z)*2,
					2*(x+1)*(z+1)+(y-1)*(2*(x+z))){  //TODO tb el color
	xDiv=x; 
	yDiv=y;
	zDiv=z;  // (Tapas Inf&Sup)+(Anillos interiores)

	build();
}


Cubo::~Cubo(void){ // TODO delete de los vectores
}

void Cubo::build(void){
	// La idea es : 
	//	1º se crea la cara de atrás del cubo
	//	2º se crean las caras que la forman
	//	se pasa a la malla del cubo los puntos y las caras
	//	se hace un nuevo panel auxiliar, se hacen las caras que forman el anillo
}
