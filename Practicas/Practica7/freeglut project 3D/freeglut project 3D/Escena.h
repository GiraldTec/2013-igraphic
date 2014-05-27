//Carlos Giraldo
//Raquel Peces
#pragma once

#include "Elementos\MesaBillar.h"
#include "Elementos\TrianguloBolas.h"
#include "Elementos\Taco.h"
#include "Elementos\Tiza.h"
#include "Elementos\Bola.h"
#include "Elementos\Lampara.h"

class Escena : public ObjetoCompuesto
{
public:
	Lampara *lamp;
	Lampara* getLamp(void);

	Escena(void);
	~Escena(void);
};

