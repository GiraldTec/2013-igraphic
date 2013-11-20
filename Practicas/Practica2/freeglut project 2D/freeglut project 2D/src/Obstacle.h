#pragma once

#include "Ball.h"
class Obstacle
{
private:
	int num_sides;
	std::vector<PV2D*> *vertex;
	GLdouble orientation;
	PV2D *center;
	Pencil *pencil;

public:
	Obstacle(void);
	~Obstacle(void);
	virtual void collide(Ball* ball)=0;
	virtual void calcula_vertices(void)=0;
	virtual void render(void) = 0;
};

