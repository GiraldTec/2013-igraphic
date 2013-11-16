#pragma once

#include <src/Point.h>
#include <iostream>
using namespace std;

class Pencil
{
private:
	Point *pos;
	GLdouble dir;

public:
	Pencil(void);
	~Pencil(void);
	Pencil(Point *p, GLdouble dir);
	void setPos(Point *p);
	void setDir(GLdouble d);
	GLdouble getDir();
	Point* getPos();
	void turn(GLdouble a);
	void forward(GLdouble d);
};

