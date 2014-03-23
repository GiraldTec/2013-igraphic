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

	GLfloat functionX(GLfloat t);
	GLfloat functionY(GLfloat t);
	GLfloat functionZ(GLfloat t);
};

