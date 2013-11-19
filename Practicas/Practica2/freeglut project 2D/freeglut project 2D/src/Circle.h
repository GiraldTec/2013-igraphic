#pragma once
#include "drawablepolygon.h"
#include "Obstacle.h"
class Circle :	public DrawablePolygon , public Obstacle
{
public:
	Circle(void);
	~Circle(void);

	
	void render(void){ cout << "hago un render de mi triangulo" << endl;}
	void collide(Ball *ball) {}
};

