//Carlos Giraldo
//Raquel Peces

#include "Elipse.h"

Elipse::Elipse(void)
{
}

Elipse::Elipse(PV2D *c):Obstacle(c,20,100,0,1,1,0)
{
}


Elipse::~Elipse(void)
{
}

PV2D* Elipse::multMatriz(GLfloat* matriz, PV2D* punt){
	PV2D* aux = new PV2D();
	GLfloat corX = (((*(matriz+0))*(punt->getX()))+((*(matriz+1))*(punt->getY())));
	GLfloat corY = (((*(matriz+4))*(punt->getX()))+((*(matriz+5))*(punt->getY())));
	aux->setX(corX);
	aux->setY(corY);
	return aux;
}
