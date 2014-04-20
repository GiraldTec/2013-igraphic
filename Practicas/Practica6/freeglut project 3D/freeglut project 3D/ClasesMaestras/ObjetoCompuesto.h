#pragma once
#include "Objeto3D.h"

class ObjetoCompuesto : public Objeto3D
{
private:
	int numHijos;
	Objeto3D **componentes;

public:
	ObjetoCompuesto(void);
	~ObjetoCompuesto(void);

	void addComponente(Objeto3D *c);

	void dibuja(){
		// TODO postmultiplicar matriz propia

		// Bucle dibujar hijos
	}
};
