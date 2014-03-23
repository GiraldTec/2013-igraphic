#include "PV3D.h"


PV3D::PV3D(void)
{
	this->corX = 0;
	this->corY = 0;
	this->corZ = 0;
}

PV3D::PV3D(GLdouble x, GLdouble y, GLdouble z)
{
	this->corX = x;
	this->corY = y;
	this->corZ = z;
}

GLdouble PV3D::getX()
{
	return corX;
}

GLdouble PV3D::getY()
{
	return corY;
}

GLdouble PV3D::getZ()
{
	return corZ;
}

void PV3D::setX(GLdouble x)
{
	this->corX = x;
}

void PV3D::setY(GLdouble y)
{
	this->corY = y;
}

void PV3D::setZ(GLdouble z)
{
	this->corZ = z;
}

PV3D* PV3D::clone(){
	return new PV3D(this->corX,this->corY,this->corZ);
}

PV3D* PV3D::addition(PV3D* p)
{
	return new PV3D(this->corX+p->getX(),this->corY+p->getY(),this->corZ+p->getZ());
}

PV3D* PV3D::subtraction(PV3D* p)
{
	return new PV3D(this->corX-p->getX(),this->corY-p->getY(),this->corZ-p->getZ());
}

void PV3D::normalize()
{
	GLdouble magnitude = this->magnitude();
	this->corX = this->corX/magnitude;
	this->corY = this->corY/magnitude;
	this->corZ = this->corZ/magnitude;
}

GLdouble PV3D::magnitude()
{
	GLdouble aux = pow(this->corX,2)+pow(this->corY,2)+pow(this->corZ,2);
	return sqrt(aux);
}

PV3D::~PV3D(void)
{
}
