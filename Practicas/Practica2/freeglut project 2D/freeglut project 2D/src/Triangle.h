#pragma once

#include "Obstacle.h"
#include "DrawablePolygon.h"

class Triangle : public Obstacle, public DrawablePolygon
{
private:

public:
	Triangle(void);
	~Triangle(void);
	
	void collide(Ball *ball);
	void doNormals(void);
	void doVertex(void);
};

