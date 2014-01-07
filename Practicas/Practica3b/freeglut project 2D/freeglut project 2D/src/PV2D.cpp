//Carlos Giraldo
//Raquel Peces
#include "PV2D.h"


PV2D::PV2D(void)
{
	this->corX = 0;
	this->corY = 0;
}

PV2D* PV2D::clone()
{
	PV2D* aux = new PV2D();
	aux->setX(this->getX());
	aux->setY(this->getY());
	return aux;
}

PV2D::PV2D(GLdouble x, GLdouble y)
{
	this->corX = x;
	this->corY = y;
}

PV2D::PV2D(PV2D* a,PV2D* b)
{
	this->corX = b->getX() - a->getX();
	this->corY = b->getY() - a->getY();
}

GLdouble PV2D::getX()
{
	return this->corX;
}

GLdouble PV2D::getY()
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
		return sqrt (pow(getX()-p->getX(),2)+pow(getY()-p->getY(),2));
	}else return 0;
}

PV2D* PV2D::doNormal(){
	return new PV2D (-corY,corX);
}

void PV2D::reflection(PV2D* normal){
	GLdouble a =calculateA(normal);
	PV2D* an = normal->factor(2*a);
	PV2D* auxVector = substract(an);

	this->setX(auxVector->getX());
	this->setY(auxVector->getY());
}

PV2D* PV2D::factor(GLdouble g){
	return new PV2D(corX*g, corY*g);
}

PV2D* PV2D::substract(PV2D* vector){
	return new PV2D(corX - vector->getX(),corY - vector->getY());
}

PV2D* PV2D::add(PV2D* vector){
	return new PV2D(corX+vector->getX(),corY+vector->getY());
}

GLdouble PV2D::scalarProduct(PV2D* vector){
	return ((corX*vector->getX())+(corY*vector->getY()));
}

GLdouble PV2D::calculateA(PV2D* normal){
	GLdouble vn = scalarProduct(normal);
	GLdouble nn = normal->scalarProduct(normal);
	return vn/nn;
}

GLdouble PV2D::calculateMod(void){
	return sqrt (pow(this->corX,2) + pow(this->corY,2));
}

PV2D* PV2D::normalize(void){
	GLdouble mod=this->calculateMod();
	return new PV2D(this->corX/mod,this->corY/mod);
}




