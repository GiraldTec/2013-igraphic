#pragma once
#include "drawablepolygon.h"
#include "Obstacle.h"
class Circle :	public DrawablePolygon , public Obstacle
{
private:
	int nsides;
	GLdouble radius;
	std::vector<PV2D*> *vertex;
	PV2D* center;

public:
	Circle(void);
	~Circle(void);

	
	void render(void);
	void collide(Ball *ball);
};
