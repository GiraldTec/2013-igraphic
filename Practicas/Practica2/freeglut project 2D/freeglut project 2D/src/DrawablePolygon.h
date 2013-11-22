#pragma once

#include <vector>
#include <src/Pencil.h>
#include <src/PV2D.h>

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

	// Polygon colors
	GLdouble red, blue, green;
	
public:
	DrawablePolygon(void);
	~DrawablePolygon(void);
	DrawablePolygon(PV2D *c,int n, GLdouble radius, GLdouble o,GLdouble r, GLdouble g, GLdouble b);

	// Getters
	vector<PV2D*> * getVertex(void);  
	PV2D * getCenter(void); 
	GLdouble getRadius(void); 
	GLdouble getOrientation(void);

	// Setters
	void setVertex(vector<PV2D*> *v);
	void setCenter(PV2D *p);
	void setRadius(GLdouble r);
	void setOrientation(GLdouble o);

	// Methods
	void calcula_vertices(void);
	void render(void);
};

