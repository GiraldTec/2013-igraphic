#pragma once

#include "src/Obstacle.h"
#include "src/DrawablePolygon.h"

class Triangle : public Obstacle, public DrawablePolygon
{
private:

public:
	Triangle(void);
	Triangle(PV2D *c, GLdouble r);
	~Triangle(void);
	
	void collide(Ball *ball, GLdouble& tin, PV2D*& normalIn);
	void doNormals(void);
	void doVertex(void);
};

