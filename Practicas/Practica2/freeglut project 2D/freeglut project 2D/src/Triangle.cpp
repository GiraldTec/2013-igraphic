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
	//Calculo de los vertices a partir del centro (circuncentro o punto donde se cruzan las medianas)
	pencil = new Pencil(center);

}

