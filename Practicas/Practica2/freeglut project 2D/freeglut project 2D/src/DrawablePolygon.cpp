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



DrawablePolygon::DrawablePolygon(PV2D *c, int n, GLdouble r)
{
	this->center = c;
	this->n_sides = n;
	this->radius = r;
	this->orientation = 0.0;
	this->draw_normals = false;
}


void DrawablePolygon::render(void){
	if(vertex!=NULL){
		glBegin(GL_POLYGON);
			for(unsigned i=0;i<vertex->size();i++){
				glVertex2d( vertex->at(i)->GetX(), vertex->at(i)->GetY() );
			}
		glEnd();
	}
}

void DrawablePolygon::calcula_vertices(void){
	Pencil *p = new Pencil(this->center,this->orientation);
	//TODO
}

void DrawablePolygon::setVertex(vector<PV2D*> *v){
	delete this->vertex;
	this->vertex = v;
}
void DrawablePolygon::setCenter(PV2D *p){
	delete this->center;
	this->center = p;
}
void DrawablePolygon::setRadius(GLdouble r){
	this->radius = r;
}