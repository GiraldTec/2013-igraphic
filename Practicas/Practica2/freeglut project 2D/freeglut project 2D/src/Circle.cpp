#include "Circle.h"


Circle::Circle(void)
{
}

Circle::Circle(PV2D *c,GLdouble r):DrawablePolygon(c,20,r,0,0,1,0)
{
}


Circle::~Circle(void)
{
}
