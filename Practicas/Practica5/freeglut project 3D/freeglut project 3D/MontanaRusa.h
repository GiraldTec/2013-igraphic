#pragma once
#include "Malla.h"

class MontanaRusa : public Malla
{
private:
	int NP;
	int NQ;

public:
	MontanaRusa(void);
	~MontanaRusa(void);

	GLdouble functionX(GLdouble t);
	GLdouble functionY(GLdouble t);
	GLdouble functionZ(GLdouble t);
};

