//Carlos Giraldo
//Raquel Peces
#pragma once
#include "../ClasesMaestras/ObjetoCompuesto.h"
#include "../Figuras/Cilindro.h"
#include "../Figuras/Disco.h"
#include "../Figuras/Cubo.h"
#include "../Figuras/Esfera.h"
#include <iostream>
using namespace std;

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>


class Lampara	: public ObjetoCompuesto{

public:

	Lampara(void);

	~Lampara(void);
};

