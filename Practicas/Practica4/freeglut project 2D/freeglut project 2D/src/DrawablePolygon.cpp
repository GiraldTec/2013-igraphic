//Carlos Giraldo
//Raquel Peces
#include "DrawablePolygon.h"


DrawablePolygon::DrawablePolygon(void)
{
	center = NULL;
	vertex = NULL;
	//normales = NULL;
}


DrawablePolygon::~DrawablePolygon(void)
{
}



DrawablePolygon::DrawablePolygon(PV2D *c, int n, GLdouble radius, GLdouble o, GLfloat r, GLfloat g, GLfloat b)
{
	this->center = c;
	this->n_sides = n;
	this->radius = radius;
	this->orientation = o;
	this->draw_normals = false;
	this->red = r;
	this->green = g;
	this->blue = b;
	this->calcula_vertices(this->center);
}


void DrawablePolygon::renderX(void){
	if(vertex!=NULL){

		glColor3f(red,blue,green);
		glBegin(GL_POLYGON);
			for(unsigned i=0;i<vertex->size();i++){
				glVertex2d( vertex->at(i)->getX(), vertex->at(i)->getY() );
			}
		glEnd();
	}
}

void DrawablePolygon::calcula_vertices(PV2D* centroTemp){
	Pencil *p = new Pencil(centroTemp->clone(),this->orientation);
	
	//CaLculo del angulo en el que se divide la circunferencia
	GLdouble alfa=2*M_PI/n_sides;
	//Calculo tamaño del lado
	GLdouble tam=(radius*sin(alfa/2))*2;
	//Calculo del angulo de giro del lápiz
	GLdouble beta=(M_PI-alfa)/2;
	//Colocamos el lapiz a una distancia r del centro;
	p->forward(radius);
	p->turn(M_PI-beta);

	PV2D *aux_p;
	//CALCULO DE LOS VERTICES DEL POLIGONO;
	this->vertex = new vector<PV2D*>();
	for (int i=0; i<n_sides; i++){
		aux_p = p->getPos()->clone();
		vertex->push_back(aux_p);
		p->forward(tam);
		p->turn(M_PI-2*beta);	
	}
	aux_p = NULL;
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
	this->calcula_vertices(this->center);
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