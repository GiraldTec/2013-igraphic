#pragma once
#include "Malla.h"
//#include "Coche.h"
#include "Polygon.h"

class MontanaRusa : public Malla{
private:
    GLfloat R;
    GLfloat r;
    GLfloat d;
    int NP;
    int NQ;
    GLfloat tam;
    GLfloat nVueltas;
    //Coche* coche;
    GLfloat acumCoche;

public:
	MontanaRusa(GLfloat R,GLfloat r,GLfloat d,int NP,int NQ,GLfloat tam);
	~MontanaRusa(void);

    void construye();

    GLfloat funcionX(GLfloat val);
	GLfloat funcionY(GLfloat val);
    GLfloat funcionZ(GLfloat val);

    GLfloat primeraDerivadaX(GLfloat val);
    GLfloat primeraDerivadaZ(GLfloat val);

    GLfloat segundaDerivadaX(GLfloat val);
    GLfloat segundaDerivadaZ(GLfloat val);

    PV3D* funcion(GLfloat val);

    PV3D* primeraDerivada(GLfloat val);
    PV3D* segundaDerivada(GLfloat val);

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

