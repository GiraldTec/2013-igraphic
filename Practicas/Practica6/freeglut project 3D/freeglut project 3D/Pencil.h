//Carlos Giraldo
//Raquel Peces
#pragma once

#include "PV3D.h"
#include <iostream>
using namespace std;

class Pencil
{
private:
	PV3D *pos;
	GLdouble dir;

public:
	Pencil(void);
	~Pencil(void);
	Pencil(PV3D *p, GLdouble dir);
	void setPos(PV3D *p);
	void setDir(GLdouble d);
	GLdouble getDir();
	PV3D* getPos();
	void turn(GLdouble a);
	void forward(GLdouble d);
};

