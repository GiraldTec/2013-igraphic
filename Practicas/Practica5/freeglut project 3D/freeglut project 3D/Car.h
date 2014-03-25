//Carlos Giraldo
//Raquel Peces
#pragma once

#include "Malla.h"

class Car
{
private:
    int nWheelFaces;
    GLdouble carSize, chassisSize, wheelRatius, wheelWith;
public:
	Car(GLdouble s);
	~Car(void);

    void draw();
};

