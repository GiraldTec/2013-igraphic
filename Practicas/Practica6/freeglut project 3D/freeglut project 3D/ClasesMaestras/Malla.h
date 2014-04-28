#pragma once
#include "Objeto3D.h"
#include "../PV3D.h"
#include "../Cara.h"

#include <vector>
using namespace std;

class Malla : public Objeto3D
{
protected:
	//TODO color
	int nCaras, nPuntos, nNormales;
	vector<PV3D*> *puntos;
	vector<PV3D*> *normales;
	vector<Cara*> *caras;

public:
	
	Malla(int nV, int nF, int nN); 
	~Malla(void);

	virtual void build(void) = 0;
	PV3D* doVectorNormalNewell(Cara* c);

	void dibuja(void){
		for (int i=0; i<this->nCaras; i++){
           glLineWidth(1.0);
           glColor3f(0,0,0);
				glBegin(GL_POLYGON);
                
				for (int j=0; j<caras->at(i)->getNumV();j++){
					int iN=caras->at(i)->getNormalIndex(j);
					int iV=caras->at(i)->getVertexIndex(j);
					GLfloat nX = normales->at(iN)->getX();
					GLfloat nY = normales->at(iN)->getY();
					GLfloat nZ = normales->at(iN)->getZ();
					glNormal3f(nX,nY,nZ);
					//Si hubiera coordenadas de textura, aqui se suministrarian
					//las coordenadas de textura del vertice j con glTexCoor2f(c);
					GLfloat vX = puntos->at(iV)->getX();
					GLfloat vY = puntos->at(iV)->getY();
					GLfloat vZ = puntos->at(iV)->getZ();
					glVertex3f(vX,vY,vZ);
					}
                glEnd();
		}
	}

};

