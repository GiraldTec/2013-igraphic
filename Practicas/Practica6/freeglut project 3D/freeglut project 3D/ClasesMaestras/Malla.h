#pragma once
#include "Objeto3D.h"
#include "../PV3D.h"
#include "../Cara.h"

#include <vector>
using namespace std;

class Malla : public Objeto3D
{
private:
	//TODO color
	int nCaras, nPuntos, nNormales;
	std::vector<PV3D*> *puntos;
	std::vector<PV3D*> *normales;
	std::vector<Cara*> *caras;

public:
	
	Malla(int nV, int nF, int nN); 
	~Malla(void);

	virtual void build(void) = 0;

	void dibuja(void){
		// TODO recorrer vector de caras y pintar
	}

};

