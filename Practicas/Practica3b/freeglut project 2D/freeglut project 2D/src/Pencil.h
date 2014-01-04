//Carlos Giraldo
//Raquel Peces
#pragma once

#include <src/PV2D.h>
#include <iostream>
using namespace std;

class Pencil
{
private:
	PV2D *pos;
	GLdouble dir;

public:
	Pencil(void);
	~Pencil(void);
	Pencil(PV2D *p, GLdouble dir);
	void setPos(PV2D *p);
	void setDir(GLdouble d);
	GLdouble getDir();
	PV2D* getPos();
	void turn(GLdouble a);
	void forward(GLdouble d);
};

