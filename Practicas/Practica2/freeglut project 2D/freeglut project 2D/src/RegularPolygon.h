#pragma once


#include <src/Pencil.h>
#include <src/Drawable.h>



class RegularPolygon : public Drawable
{
private:
	int num_faces;
	std::vector<Point*> *vertices;
	GLdouble orientation;
	Point *centro;
	Pencil *lapiz;
public:
	RegularPolygon(void);
	~RegularPolygon(void);
	RegularPolygon(Point *c,int n, GLdouble a);
	void calcula_vertices(void);
	
	void render(void){ cout << "hago un render de mi poligonito" << endl;}
};

