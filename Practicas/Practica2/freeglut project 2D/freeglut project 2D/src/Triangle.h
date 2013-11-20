#pragma once

#include "Obstacle.h"
class Triangle : public Obstacle
{
private:
	std::vector<PV2D*> *vertex;
	std::vector<PV2D*> *normal;
	Pencil* pencil;
	PV2D* center;

public:
	Triangle(void);
	~Triangle(void);
	Triangle(vector<PV2D*> *v);
	Triangle(PV2D* p1, PV2D* p2, PV2D* p3);
	
	void render(void){ cout << "hago un render de mi triangulo" << endl;}
	void collide(Ball *ball) {}
	void doNormals(void);
	void doVertex(void);
};

