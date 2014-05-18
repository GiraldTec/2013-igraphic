//Carlos Giraldo
//Raquel Peces
#pragma once
#include "../ClasesMaestras/ObjetoCompuesto.h"
#include "../Figuras/Esfera.h"

class Bola : public ObjetoCompuesto
{
public:
	Bola(void);
	Bola(GLdouble r, GLdouble g, GLdouble b);
	~Bola(void);
};

