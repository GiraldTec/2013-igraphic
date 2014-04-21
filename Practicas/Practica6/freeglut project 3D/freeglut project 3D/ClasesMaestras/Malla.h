#pragma once
#include "Objeto3D.h"

class Malla : public Objeto3D
{
private:
	//TODO color
	//TODO vector con caras
	//TODO vector con puntos
	//TODO vector con normales/puntos ??
public:
	int nCaras, nPuntos;
	Malla(void); 
	~Malla(void);

	virtual void calculaPuntos(void)=0;
	virtual void calculaCaras(void)=0;

	void dibuja(void){
		// TODO recorrer vector de caras y pintar
	}

};

