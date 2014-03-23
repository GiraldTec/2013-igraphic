#include "Polygon.h"


Polygon::Polygon(void)
{
	center = NULL;
	vertex = NULL;
}

Polygon::Polygon(PV3D *c, int n, GLdouble radius)
{
	this->center = c;
	this->n_sides = n;
	this->radius = radius;
	this->calcula_vertices(this->center);
}

Polygon::~Polygon(void)
{
}

void Polygon::renderX(void){
	if(vertex!=NULL){

		//glColor3f(red,blue,green);
		glBegin(GL_POLYGON);
			for(unsigned i=0;i<vertex->size();i++){
				glVertex2d( vertex->at(i)->getX(), vertex->at(i)->getY() );
			}
		glEnd();
	}
}

void Polygon::calcula_vertices(PV3D* centroTemp){
	Pencil *p = new Pencil(centroTemp->clone(),0);
	
	//CaLculo del angulo en el que se divide la circunferencia
	GLdouble alfa=2*M_PI/n_sides;
	//Calculo tamaño del lado
	GLdouble tam=(radius*sin(alfa/2))*2;
	//Calculo del angulo de giro del lápiz
	GLdouble beta=(M_PI-alfa)/2;
	//Colocamos el lapiz a una distancia r del centro;
	p->forward(radius);
	p->turn(M_PI-beta);

	PV3D *aux_p;
	//CALCULO DE LOS VERTICES DEL POLIGONO;
	this->vertex = new vector<PV3D*>();
	for (int i=0; i<n_sides; i++){
		aux_p = p->getPos()->clone();
		vertex->push_back(aux_p);
		p->forward(tam);
		p->turn(M_PI-2*beta);	
	}
	aux_p = NULL;
}

void Polygon::setVertex(vector<PV3D*> *v){
	delete this->vertex;
	this->vertex = v;
}

void Polygon::setCenter(PV3D *p){
	delete this->center;
	this->center = p;
}

void Polygon::setRadius(GLdouble r){
	this->radius = r;
}


vector<PV3D*>* Polygon::getVertex(void){
	return this->vertex;
}

PV3D* Polygon::getCenter(void){
	return this->center;
}

GLdouble Polygon::getRadius(void){
	return this->radius;
}

