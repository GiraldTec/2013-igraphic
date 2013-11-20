#include "Triangle.h"


Triangle::Triangle(void)
{
}


Triangle::~Triangle(void)
{
}

Triangle::Triangle(vector<PV2D*> *v){
	this->vertex = v;
	doNormals();
}

Triangle::Triangle(PV2D* center){
	this->center = center;
	doVertex();
	doNormals();
}

Triangle::Triangle(PV2D* p1, PV2D* p2, PV2D* p3){
	this->vertex->push_back(p1);
	this->vertex->push_back(p2);
	this->vertex->push_back(p3);
	doNormals();
}
	
void Triangle::render(void){
	cout << "hago un render de mi triangulo" << endl;
	
	glBegin ( GL_TRIANGLES ) ;
		glVertex2d( vertex->at(1)->GetX(), vertex->at(1)->GetY() );
		glVertex2d( vertex->at(2)->GetX(), vertex->at(2)->GetY() );
		glVertex2d( vertex->at(3)->GetX(), vertex->at(3)->GetY() );
	glEnd () ;
}

void Triangle::collide(Ball *ball) {

}

void Triangle::doNormals(){
	//Calculo de las normales de mi triangulo

}

void Triangle::doVertex(){
	pencil = new Pencil(center->clone(),0);
	//Calculo de los vertices a partir del centro (circuncentro o punto donde se cruzan las medianas)
	GLdouble alfa=2*PI/3;
	//Calculo tamaño del lado
	GLdouble tam=(radius*sin(alfa/2))*2;
	//Calculo del angulo de giro del lápiz
	GLdouble beta=(PI-alfa)/2;
	//Colocamos el lapiz a una distancia r del centro;
	pencil->forward(radius);
	pencil->turn(PI-beta);

	vertex = new vector<PV2D*>();
	for (int i=0; i<3; i++){
		PV2D *aux_p = pencil->getPos()->clone();
		vertex->push_back(aux_p);
		pencil->forward(tam);
		pencil->turn(beta);	
	}

}

