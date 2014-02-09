//Carlos Giraldo
//Raquel Peces

#include "Elipse.h"

Elipse::Elipse(void)
{
}

Elipse::Elipse(PV2D *c, GLdouble pX, GLdouble pY):Obstacle(c,20,1,0,1,1,0)
{
	calcula_vertices(new PV2D());
	propX = pX;
	propY = pY;
}


Elipse::~Elipse(void)
{
}