#pragma once

#include "Malla.h"
#include "Cube.h"

class Car
{
private:
	GLdouble x;
    GLdouble y;
    GLdouble z;
    int aproximacion;
    GLdouble radioRueda;
    GLdouble anchoRueda;

	std::vector<GLUquadric*> *wheels;
	std::vector<GLUquadric*> *covers;
    /*GLUquadric* rueda1;
    GLUquadric* rueda2;
    GLUquadric* rueda3;
    GLUquadric* rueda4;

    GLUquadric* tapa1;
    GLUquadric* tapa2;
    GLUquadric* tapa3;
    GLUquadric* tapa4;
	*/
    Cube* cubo1;
    Cube* cubo2;

public:
	Car(GLdouble x,GLdouble y,GLdouble z);
	~Car(void);

    void build();
    void draw(GLdouble acumCoche);
};

