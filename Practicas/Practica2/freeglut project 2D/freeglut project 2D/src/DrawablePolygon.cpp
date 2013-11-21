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

	this->calcula_vertices();
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
	Pencil *p = new Pencil(this->center->clone(),this->orientation);
	
	//CaLculo del angulo en el que se divide la circunferencia
	GLdouble alfa=2*M_PI/n_sides;
	//Calculo tamaño del lado
	GLdouble tam=(radius*sin(alfa/2))*2;
	//Calculo del angulo de giro del lápiz
	GLdouble beta=(M_PI-alfa)/2;
	//Colocamos el lapiz a una distancia r del centro;
	p->forward(radius);
	p->turn(M_PI-beta);

	//CALCULO DE LOS VERTICES DEL POLIGONO;
	this->vertex = new vector<PV2D*>();
	for (int i=0; i<n_sides; i++){
		PV2D *aux_p = p->getPos()->clone();
		vertex->push_back(aux_p);
		p->forward(tam);
		p->turn(beta);	
	}
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
void DrawablePolygon::setOrientation(GLdouble o){
	this->orientation = o;
}

vector<PV2D*>* DrawablePolygon::getVertex(void){
	return this->vertex;
}
PV2D* DrawablePolygon::getCenter(void){
	return this->center;
}
GLdouble DrawablePolygon::getRadius(void){
	return this->radius;
}
GLdouble DrawablePolygon::getOrientation(void){
	return this->orientation;
}