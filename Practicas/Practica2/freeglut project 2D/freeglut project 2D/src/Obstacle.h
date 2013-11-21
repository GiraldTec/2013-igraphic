#pragma once

#include "Ball.h"
class Obstacle
{
private:

public:
	Obstacle(void);
	~Obstacle(void);

	virtual bool collide(Ball* ball, GLdouble& tIn, PV2D*& normalIn)=0;

};

