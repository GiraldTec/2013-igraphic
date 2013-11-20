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
	DrawablePolygon(PV2D *c,int n, GLdouble r);

	// Getters
	vector<PV2D*> * getVertex(void);  //TODO
	PV2D * getCenter(void); //TODO
	GLdouble getRadius(void); //TODO

	// Setters
	void setVertex(vector<PV2D*> *v);
	void setCenter(PV2D *p);
	void setRadius(GLdouble r);

	// Methods
	void calcula_vertices(void);
	void render(void);
};

