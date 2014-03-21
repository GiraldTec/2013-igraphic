#include "PV3D.h"


PV3D::PV3D(void)
{
	this->coorX = 0;
	this->coorY = 0;
	this->coorZ = 0;
}

PV3D::PV3D(double x, double y, double z)
{
	this->coorX = x;
	this->coorY = y;
	this->coorZ = z;
}

double PV3D::getX()
{
	return coorX;
}

double PV3D::getY()
{
	return coorY;
}

double PV3D::getZ()
{
	return coorZ;
}

void PV3D::setX(double x)
{
	this->coorX = x;
}

void PV3D::setY(double y)
{
	this->coorY = y;
}

void PV3D::setZ(double z)
{
	this->coorZ = z;
}

PV3D* PV3D::clone(){
	return new PV3D(this->coorX,this->coorY,this->coorZ);
}

PV3D* PV3D::addition(PV3D* p)
{
	return new PV3D(this->coorX+p->getX(),this->coorY+p->getY(),this->coorZ+p->getZ());
}

PV3D* PV3D::subtraction(PV3D* p)
{
	return new PV3D(this->coorX-p->getX(),this->coorY-p->getY(),this->coorZ-p->getZ());
}

PV3D::~PV3D(void)
{
}
