#pragma once

#include <vector>
#include <src/Pencil.h>

class DrawablePolygon
{
private:
	int num_sides;
	std::vector<PV2D*> *vertex;
	GLdouble orientation;
	PV2D *center;
	Pencil *pencil;

public:
	DrawablePolygon(void);
	~DrawablePolygon(void);
	DrawablePolygon(PV2D *c,int n, GLdouble a);
	virtual void calcula_vertices(void)=0;
	virtual void render(void) = 0;
};

