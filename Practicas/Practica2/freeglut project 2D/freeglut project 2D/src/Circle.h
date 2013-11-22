#pragma once
#include "drawablepolygon.h"
#include "Obstacle.h"
class Circle :	public DrawablePolygon , public Obstacle
{
private:


public:
	Circle(void);
	Circle(PV2D *c,GLdouble r);
	~Circle(void);
};

