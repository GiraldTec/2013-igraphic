#pragma once

#include "../ClasesMaestras/Malla.h"

/*
	Un panel es una superficie con ancho*alto caras.
	Por defecto está centrado en 
*/

class PanelAuxiliar:public Malla{
private:
	int ancho,alto, nCaras, nPuntos, nNormales;
	vector<PV3D*> *puntos;
	vector<PV3D*> *normales;
	vector<Cara*> *caras;

public:
	PanelAuxiliar(GLint ancho,GLint alto);
	~PanelAuxiliar(void);

	void buildCaras(void);
	void buildPuntos(void);
	void buildNormales(void);

	void rotateX(GLfloat angle);
	void rotateY(GLfloat angle);
	void rotateZ(GLfloat angle);
	

	vector<PV3D*> getPuntos(void);
	vector<PV3D*> getNormales(void);
	vector<Cara*> getCaras(void);
};

