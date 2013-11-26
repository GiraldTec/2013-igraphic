#include "Obstacle.h"


Obstacle::Obstacle(void)
{
}


Obstacle::~Obstacle(void)
{
}

Obstacle::Obstacle(PV2D *c,int n, GLdouble radius, GLdouble o,GLfloat r, GLfloat g, GLfloat b):
	DrawablePolygon(c,n,radius,o,r,g,b){
}