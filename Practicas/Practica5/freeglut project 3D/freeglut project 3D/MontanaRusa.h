//Carlos Giraldo
//Raquel Peces#pragma once
#include "Malla.h"
#include "Car.h"
#include "Poligon.h"

class MontanaRusa : public Malla{
private:
    int NP;
    int NQ;
    GLfloat tam;
    Car* car;
    GLfloat carPos;

public:
	MontanaRusa(int NP,int NQ,GLfloat tam);
	~MontanaRusa(void);

    void build();

    GLfloat functionX(GLfloat val);
	GLfloat functionY(GLfloat val);
    GLfloat functionZ(GLfloat val);

    GLfloat fDerivateX(GLfloat val);
    GLfloat fDerivateY(GLfloat val);
	GLfloat fDerivateZ(GLfloat val);

    GLfloat sDerivateX(GLfloat val);
    GLfloat sDerivateY(GLfloat val);
    GLfloat sDerivateZ(GLfloat val);

    PV3D* function(GLfloat val);

    PV3D* fDerivate(GLfloat val);
    PV3D* sDerivate(GLfloat val);

    int nextVertex(int val);

	void draw(bool relleno,bool dibujaNormales);

    void carStep(GLfloat step);

};

