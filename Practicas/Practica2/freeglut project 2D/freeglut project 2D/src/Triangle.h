#pragma once
#include "DrawablePolygon.h"
#include "Obstacle.h"
class Triangle : public DrawablePolygon , public Obstacle
{
private:
	std::vector<Point*> *vertices;
public:
	Triangle(void);
	~Triangle(void);
	Triangle(vector<Point*> *v);
	

	void render(void){ cout << "hago un render de mi triangulo" << endl;}
	void collide(Ball *ball) {}
};

