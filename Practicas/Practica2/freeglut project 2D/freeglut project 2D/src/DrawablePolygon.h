#pragma once

#include <vector>
#include <src/Pencil.h>

class DrawablePolygon
{
private:
	int n_sides;
	PV2D *center;
	GLdouble orientation;
	GLdouble radius;

	std::vector<PV2D*> *vertex;
	std::vector<PV2D*> *normales;
	bool draw_normals;
	
public:
	DrawablePolygon(void);
	~DrawablePolygon(void);
	DrawablePolygon(PV2D *c,int n, GLdouble r, bool d);
	void calcula_vertices(void);
	void render(void);
};

