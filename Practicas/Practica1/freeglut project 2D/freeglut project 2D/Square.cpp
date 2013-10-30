#include "Square.h"


Square::Square(void)
{
	this->ver1 = new Point;
	this->ver2 = new Point;
	this->ver3 = new Point;
	this->ver4 = new Point;
}

Square::Square(Point *p1, Point *p2, Point *p3, Point *p4, GLdouble d)
{
	this->ver1 = p1;
	this->ver2 = p2;
	this->ver3 = p3;
	this->ver4 = p4;
	this->side = d;
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

GLdouble Square::getSide()
{
	return side;
}

void Square::render()
{
	glBegin(GL_QUADS);
		glVertex2d( ver1->GetX(), ver1->GetY() );
		glVertex2d( ver2->GetX(), ver2->GetY() );
		glVertex2d( ver3->GetX(), ver3->GetY() );
		glVertex2d( ver4->GetX(), ver4->GetY() );
    glEnd();
}

Square::~Square(void)
{
}
