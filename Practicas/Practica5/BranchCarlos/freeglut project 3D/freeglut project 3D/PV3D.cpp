#include "PV3D.h"


PV3D::PV3D(void)
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->pv = 1;
}

PV3D::PV3D(GLfloat x, GLfloat y, GLfloat z, int pv)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->pv = pv;
}

GLfloat PV3D::module(PV3D* v){
	return sqrt(pow(v->getX(), 2) + pow(v->getY(), 2) + pow(v->getZ(), 2));
}

PV3D* PV3D::normaliza(){
	// Same direction but module = 1
	PV3D* newV = new PV3D();
	GLfloat moduleVector = module(this);

	newV->setX((1 / moduleVector) * this->getX());
	newV->setY((1 / moduleVector) * this->getY());
	newV->setZ((1 / moduleVector) * this->getZ());
	newV->setPV(0); //vector

	return newV;
}

PV3D* PV3D::clona(){
	PV3D* newV = new PV3D();
	//TODO
	return newV;
}

GLfloat PV3D::productoEscalar(PV3D* v){
	return (this->getX() * v->getX()) + (this->getY() * v->getY() + this->getZ() * v->getZ());
}

PV3D* PV3D::productoVectorial(PV3D* v){
	GLfloat x = this->getY()*v->getZ() - this->getZ()*v->getY();
	GLfloat y = this->getZ()*v->getX() - this->getX()*v->getZ();
	GLfloat z = this->getX()*v->getY() - this->getY()*v->getX();

	return new PV3D(x,y,z,1);
}

PV3D* PV3D::calculaValorFormula(float t){
	GLfloat x = 3 * cos(t);
	GLfloat y = 2 * cos(1.5 * t);
	GLfloat z = 3 * sin(t);
	return new PV3D(x,y,z,1);
}
PV3D* PV3D::calculaValorPrimDerivada(float t){
	GLfloat x = -3 * sin(t);
	GLfloat y = -3 * sin(1.5 * t);
	GLfloat z = 3 * cos(t);
	return new PV3D(x,y,z,1);
}
PV3D* PV3D::calculaValorSegDerivada(float t){
	GLfloat x = -3 * cos(t);
	GLfloat y = -4.5 * cos(1.5 * t);
	GLfloat z = -3 * sin(t);
	return new PV3D(x,y,z,1);
}

PV3D* PV3D::calculaT(PV3D* c){
	t = c->normaliza();
	return t;
}

PV3D* PV3D::calculaB(PV3D* c, PV3D* cc){
	b = c->productoVectorial(cc)->normaliza();
	return b;
}
PV3D* PV3D::calculaN(){
	n = getB()->productoVectorial(getT());
	return n;
}