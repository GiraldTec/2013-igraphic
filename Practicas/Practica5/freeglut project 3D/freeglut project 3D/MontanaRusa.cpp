#include "MontanaRusa.h"


MontanaRusa::MontanaRusa(void){
}


MontanaRusa::~MontanaRusa(void)
{
}

GLdouble MontanaRusa::functionX(GLdouble t)
{
	return 3*cos(t);
}

GLdouble MontanaRusa::functionY(GLdouble t)
{
	return 2*cos(t*1.5);
}

GLdouble MontanaRusa::functionZ(GLdouble t)
{
	return 3*sin(t);
}