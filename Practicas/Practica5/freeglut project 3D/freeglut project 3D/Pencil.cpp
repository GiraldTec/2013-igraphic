//Carlos Giraldo
//Raquel Peces
#include "Pencil.h"


Pencil::Pencil(void)
{
	this->pos = new PV3D();
	dir = 0;
}

Pencil::Pencil(PV3D *p, GLdouble d)
{
	this->pos = p;
	this->dir = d;
}

void Pencil::setPos(PV3D *p)
{
	this->pos = p;
}

void Pencil::setDir(GLdouble d)
{
	this->dir = d;
}

GLdouble Pencil::getDir()
{
	return this->dir;
}

PV3D* Pencil::getPos()
{
	return this->pos;
}

void Pencil::turn(GLdouble d)
{
	GLdouble aux = this->dir + d;
	//aux = aux % 360;
	this->dir = aux;
}

void Pencil::forward(GLdouble d)
{
	//Seno(a)=opuesto/hipotenusa => opuesto = seno(a)*hipotenusa
	GLdouble y = this->pos->getY() + (sin(this->dir)*d);

	//Coseno(a)=contiguo/hipotenusa => contiguo = coseno(a)*hipotenusa
	GLdouble x = this->pos->getX() + (cos(this->dir)*d);

	this->pos->setX(x);
	this->pos->setY(y);
}


Pencil::~Pencil(void)
{
}
