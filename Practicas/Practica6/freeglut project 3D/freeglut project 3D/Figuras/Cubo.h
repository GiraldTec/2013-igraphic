#pragma once
#include "../ClasesMaestras/Malla.h"

class Cubo : public Malla
{
private:
	int xDiv, yDiv, zDiv;

public:
	Cubo(int x,int y,int z);
	~Cubo(void);

	void build(void);
};

