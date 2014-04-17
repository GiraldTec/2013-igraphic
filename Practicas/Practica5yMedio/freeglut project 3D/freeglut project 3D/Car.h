//Carlos Giraldo
//Raquel Peces
#pragma once

#include "Malla.h"
const GLdouble wheelInc = 15.0;
class Car
{
private:
    int nWheelFaces;
    GLdouble carSize, chassisSize, wheelRatius, wheelWith, wheelPosition;
	
public:
	Car(GLdouble s);
	~Car(void);

    void draw();
	void stepWheel();
};

