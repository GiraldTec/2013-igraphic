#pragma once
#include "Objeto3D.h"

class ObjetoCuadrico : public Objeto3D{
public:
	GLUquadricObj* q;
	ObjetoCuadrico(void);
	~ObjetoCuadrico(void);

	// TODO setColor(...
};

