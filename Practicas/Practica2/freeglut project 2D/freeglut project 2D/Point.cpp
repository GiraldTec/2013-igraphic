#include "Point.h"


Point::Point(void)
{
	this->corX = 0;
	this->corY = 0;
}

Point* Point::clone()
{
	Point* aux = new Point();
	aux->setX(this->GetX());
	aux->setY(this->GetY());
	return aux;
}

Point::Point(GLdouble x, GLdouble y)
{
	this->corX = x;
	this->corY = y;
}

GLdouble Point::GetX()
{
	return this->corX;
}

GLdouble Point::GetY()
{
	return this->corY;
}

void Point::setX(GLdouble x)
{
	this->corX = x;
}

void Point::setY(GLdouble y)
{
	this->corY = y;
}

Point::~Point(void)
{
}

GLdouble Point::distance(Point* p){
	if(p!=NULL){
		//Teorema pitagoras: hipotenusa = raiz de suma cuadrados de los catetos
		return sqrt (pow(GetX()-p->GetX(),2)+pow(GetY()-p->GetY(),2));
	}else return 0;
}
