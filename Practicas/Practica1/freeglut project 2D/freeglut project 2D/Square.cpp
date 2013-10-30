#include "Square.h"


Square::Square(void)
{
	this->ver1 = new Point;
	this->ver2 = new Point;
	this->ver3 = new Point;
	this->ver4 = new Point;
}

Square::Square(Point *p1, Point *p2, Point *p3, Point *p4)
{
	this->ver1 = p1;
	this->ver2 = p2;
	this->ver3 = p3;
	this->ver4 = p4;
}

Point* Square::getPoint1()
{
	return this->ver1;
}

Point* Square::getPoint2()
{
	return this->ver2;
}
Point* Square::getPoint3()
{
	return this->ver3;
}
Point* Square::getPoint4()
{
	return this->ver4;
}

Square::~Square(void)
{
}
