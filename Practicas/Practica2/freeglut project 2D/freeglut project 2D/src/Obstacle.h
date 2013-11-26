//Carlos Giraldo
//Raquel Peces
#pragma once

#include "Ball.h"
#include "DrawablePolygon.h"
class Obstacle : public DrawablePolygon
{
private:

public:
	Obstacle(void);
	~Obstacle(void);
	Obstacle(PV2D *c,int n, GLdouble radius, GLdouble o,GLfloat r, GLfloat g, GLfloat b);
	virtual bool collide(Ball* ball, GLdouble& tIn, PV2D*& normalIn)=0;

};

