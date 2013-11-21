#pragma once

#include "Ball.h"
class Obstacle
{
private:

public:
	Obstacle(void);
	~Obstacle(void);
	virtual void collide(Ball *ball, GLdouble& tin, PV2D*& normalIn)=0;
};

