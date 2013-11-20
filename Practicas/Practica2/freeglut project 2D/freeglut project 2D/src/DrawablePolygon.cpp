#include "DrawablePolygon.h"


DrawablePolygon::DrawablePolygon(void)
{
	center = NULL;
	vertex = NULL;
	normales = NULL;
}


DrawablePolygon::~DrawablePolygon(void)
{
}



DrawablePolygon::DrawablePolygon(PV2D *c, int n, GLdouble r, bool d)
{
	this->center = c;
	this->n_sides = n;
	this->radius = r;
	this->orientation = 0.0;
	this->draw_normals = d;
}


void DrawablePolygon::render(void){
	if(vertex!=NULL){
		glBegin(GL_POLYGON);
			PV2D *pointA = vertex->at(0);
			glVertex2d( pointA->GetX(), pointA->GetY() );
			for(int i=1;i<vertex->size();i++){
				pointA = vertex->at(i);
				glVertex2d( pointA->GetX(), pointA->GetY() );
			}
		glEnd();
	}
}

void DrawablePolygon::calcula_vertices(void){
	Pencil *p = new Pencil(this->center,this->orientation);
	//TODO
}