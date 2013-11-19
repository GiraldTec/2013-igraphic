#pragma once

#include <vector>
#include <src/Pencil.h>

class DrawablePolygon
{
private:
	int num_faces;
	std::vector<Point*> *vertices;
	GLdouble orientation;
	Point *centro;
	Pencil *lapiz;
public:
	DrawablePolygon(void);
	~DrawablePolygon(void);
	DrawablePolygon(Point *c,int n, GLdouble a);
	virtual void calcula_vertices(void)=0;
	virtual void render(void) = 0;
};

