#include "Circle.h"


Circle::Circle(void)
{
}

Circle::Circle(PV2D *c,GLdouble r):Obstacle(c,20,r,0,0,1,0)
{
}


Circle::~Circle(void)
{
}
