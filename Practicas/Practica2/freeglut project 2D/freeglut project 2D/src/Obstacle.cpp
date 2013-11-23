#include "Obstacle.h"


Obstacle::Obstacle(void)
{
}


Obstacle::~Obstacle(void)
{
}

Obstacle::Obstacle(PV2D *c,int n, GLdouble radius, GLdouble o,GLdouble r, GLdouble g, GLdouble b):
	DrawablePolygon(c,n,radius,o,r,g,b){
}