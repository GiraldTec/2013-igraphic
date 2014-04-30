//Carlos Giraldo
//Raquel Peces
#include "ObjetoCuadrico.h"


ObjetoCuadrico::ObjetoCuadrico(void){
	q=gluNewQuadric();  // TODO mejorar eficiencia
	red=green=blue=0.5;
}


ObjetoCuadrico::~ObjetoCuadrico(void){
	gluDeleteQuadric(q);
}

void ObjetoCuadrico::setColor(GLfloat r,GLfloat g, GLfloat b){
	red = r;
	green=g;
	blue =b;
}
