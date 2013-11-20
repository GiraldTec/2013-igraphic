#include "PV2D.h"


PV2D::PV2D(void)
{
	this->corX = 0;
	this->corY = 0;
}

PV2D* PV2D::clone()
{
	PV2D* aux = new PV2D();
	aux->setX(this->GetX());
	aux->setY(this->GetY());
	return aux;
}

PV2D::PV2D(GLdouble x, GLdouble y)
{
	this->corX = x;
	this->corY = y;
}

GLdouble PV2D::GetX()
{
	return this->corX;
}

GLdouble PV2D::GetY()
{
	return this->corY;
}

void PV2D::setX(GLdouble x)
{
	this->corX = x;
}

void PV2D::setY(GLdouble y)
{
	this->corY = y;
}

PV2D::~PV2D(void)
{
}

GLdouble PV2D::distance(PV2D* p){
	if(p!=NULL){
		//Teorema pitagoras: hipotenusa = raiz de suma cuadrados de los catetos
		return sqrt (pow(GetX()-p->GetX(),2)+pow(GetY()-p->GetY(),2));
	}else return 0;
}
