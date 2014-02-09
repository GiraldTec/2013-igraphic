#pragma once

#include "Point.h"

class Square
{
private:
		Point *ver1;
		Point *ver2;
		Point *ver3;
		Point *ver4;
		GLdouble side;
		bool selec;
		GLfloat red, blue, green;

public:
	Square(void);
	Square(Point *p1, Point *p2, Point *p3, Point *p4, GLdouble d);

	~Square(void);

	void render();

	void setSelec(bool b);
	Point* getPoint1();
	Point* getPoint2();
	Point* getPoint3();
	Point* getPoint4();
	GLdouble getSide();
	Point* getClosestCorner(Point* p);
};

