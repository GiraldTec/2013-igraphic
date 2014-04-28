#pragma once
#include "../ClasesMaestras\ObjetoCompuesto.h"
#include "../Figuras\Esfera.h"
#include "../Figuras\Cilindro.h"
#include "../Figuras\Disco.h"
#include "../Figuras\Torus.h"
#include "../Figuras\Cubo.h"

class BordeMesa: public ObjetoCompuesto{
public:
	BordeMesa(GLdouble largo,GLint stacks);
	~BordeMesa(void);
};

