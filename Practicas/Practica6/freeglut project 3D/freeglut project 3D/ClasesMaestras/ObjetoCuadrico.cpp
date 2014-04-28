#include "ObjetoCuadrico.h"


ObjetoCuadrico::ObjetoCuadrico(void){
	q=gluNewQuadric();  // TODO mejorar eficiencia
	red=green=blue=0.5;
}


ObjetoCuadrico::~ObjetoCuadrico(void){
	gluDeleteQuadric(q);
}
