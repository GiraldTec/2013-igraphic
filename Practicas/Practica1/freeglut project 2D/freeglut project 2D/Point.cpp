#include "Point.h"


Point::Point(void)
{
	this->corX = 0;
	this->corY = 0;
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
