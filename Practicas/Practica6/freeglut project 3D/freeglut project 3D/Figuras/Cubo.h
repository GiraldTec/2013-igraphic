#pragma once
#include "../ClasesMaestras/Malla.h"


// La idea es que es un cubo centrado en el origen y de lado 1, se pueden especificar sus divisiones
// La idea es que el cubo se forma con la adhesión de 6 PanelesAuxiliares
class Cubo : public Malla
{
private:
	int xDiv, yDiv, zDiv;

public:
	Cubo(int d);
	Cubo(int x,int y,int z);
	~Cubo(void);

	void build(void);
};

