#pragma once

#include "Malla.h"

class Cube : public Malla
{
private:
	GLdouble x;
    GLdouble y;
    GLdouble z;


public:
	Cube(GLdouble x, GLdouble y, GLdouble z);
	~Cube(void);

	void build();
};

