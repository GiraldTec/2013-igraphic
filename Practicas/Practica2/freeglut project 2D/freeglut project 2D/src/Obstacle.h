#pragma once

#include "Ball.h"
class Obstacle
{
public:
	Obstacle(void);
	~Obstacle(void);
	virtual void collide(Ball* ball)=0;
};

