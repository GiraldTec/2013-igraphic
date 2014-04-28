#pragma once
#include "../ClasesMaestras\ObjetoCompuesto.h"
#include "../Figuras\Esfera.h"
#include "../Figuras\Cilindro.h"
#include "../Figuras\Disco.h"
#include "../Figuras\Torus.h"
#include "../Figuras\Cubo.h"


class BordeTronera: public ObjetoCompuesto{
public:
	BordeTronera(GLdouble largo,GLint stacks);
	~BordeTronera(void);
};

