#pragma once

#include "src/Obstacle.h"
#include "src/DrawablePolygon.h"

class Triangle : public Obstacle, public DrawablePolygon
{
private:

public:
	Triangle(void);
	Triangle(PV2D *c, GLdouble r, GLdouble o);
	~Triangle(void);
	
	bool collide(Ball *ball, GLdouble& tin, PV2D*& normalIn){

		return false;
	};
	void doNormals(void);
	void doVertex(void);
};

