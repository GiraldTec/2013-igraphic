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
	bool collide(Ball *ball, GLdouble& tin, PV2D*& normalIn){
		bool retValue = false;
		retValue = this->getCenter()->distance(ball->getCenter()) < ball->getRadius()+this->getRadius();
		if(retValue){
		// TODO calcular la normal
		}
		return retValue;
	};

};

