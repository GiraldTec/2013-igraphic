#include "Malla.h"


Malla::Malla(void)
{
}


Malla::~Malla(void)
{
}

void Malla::dibuja(void){
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(3, 30, 30);
};