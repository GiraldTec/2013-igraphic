#pragma once
#include "Malla.h"
#include "Car.h"
#include "Poligon.h"

class MontanaRusa : public Malla{
private:
    GLfloat R;
    GLfloat r;
    GLfloat d;
    int NP;
    int NQ;
    GLfloat tam;
    GLfloat nVueltas;
    Car* car;
    GLfloat acumCoche;

public:
	MontanaRusa(GLfloat R,GLfloat r,GLfloat d,int NP,int NQ,GLfloat tam);
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

    int sucesor(int val);
    GLfloat degToRad(GLfloat deg);
    GLfloat calculaVueltas();
    void dibuja(bool relleno,bool dibujaNormales);
    void dibujaCoche();
    void addAcum(GLfloat cantidad);
    int mcd(int a, int b);

	GLdouble functionX(GLdouble t);
	GLdouble functionY(GLdouble t);
	GLdouble functionZ(GLdouble t);
};

