#include "ObjetoCuadrico.h"


ObjetoCuadrico::ObjetoCuadrico(void){
	q=gluNewQuadric();  // TODO mejorar eficiencia
}


ObjetoCuadrico::~ObjetoCuadrico(void){
	gluDeleteQuadric(q);
}
