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

	// TODO new de los vectores
}


Cubo::~Cubo(void){ // TODO delete de los vectores
}

void Cubo::build(void){
	GLdouble wideX,wideY,wideZ;
	wideX = 1.0/xDiv;	wideY = 1.0/yDiv;	wideZ = 1.0/zDiv;
	// Empezamos con los puntos de la cara que se encuentra con Z negativa
	for(unsigned i=0;i<=yDiv;i++){
		for(unsigned j=0;j<=xDiv;j++){
			unsigned acum=i*(xDiv+1)+j;
			puntos->at(acum)=new PV3D(0.5-j*wideX,0.5-i*wideY,-0.5);
		}
	}

	/*for(int i=1;i<zDiv;i++){  // los anillos interiores

	}*/


	// Acabamos con los puntos de la cara que se encuentra con Z positiva
	for(unsigned i=0;i<=yDiv;i++){
		for(unsigned j=0;j<=xDiv;j++){
			unsigned acum=i*(xDiv+1)+j;
			puntos->at(acum)=new PV3D(0.5-j*wideX,0.5-i*wideY,-0.5);
		}
	}
}
