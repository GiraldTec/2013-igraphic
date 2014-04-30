//Carlos Giraldo
//Raquel Peces
#pragma once
#include "../ClasesMaestras\ObjetoCompuesto.h"
#include "../Figuras\Esfera.h"
#include "../Figuras\Cilindro.h"
#include "../Figuras\Disco.h"
#include "../Figuras\DiscoParcial.h"
#include "../Figuras\Torus.h"
#include "../Figuras\Cubo.h"


class BordeTronera: public ObjetoCompuesto{
public:
	BordeTronera(void);
	~BordeTronera(void);
};

