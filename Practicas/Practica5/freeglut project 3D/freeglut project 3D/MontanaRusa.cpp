#include "MontanaRusa.h"


MontanaRusa::MontanaRusa(void){
}


MontanaRusa::~MontanaRusa(void)
{
}

GLfloat MontanaRusa::functionX(GLfloat t)
{
	return 3*cos(t);
}

GLfloat MontanaRusa::functionY(GLfloat t)
{
	return 2*cos(t*1.5);
}

GLfloat MontanaRusa::functionZ(GLfloat t)
{
	return 3*sin(t);
}