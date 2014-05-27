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
	GLfloat focoA;
	Lampara *lamp;
	Lampara* getLamp(void);
	void dibuja(void){
		
		cout << "blablabla" << endl;
			// LIGHT0

				// Foco de la lámpara
			//glEnable(GL_LIGHT0);
			//glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, focoA);
			glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 4.0);
	

			GLfloat d[]={1.0,1.0,1.0,1.0};
			glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
			GLfloat a[]={0.3f,0.3f,0.3f,1.0};
			glLightfv(GL_LIGHT0, GL_AMBIENT, a); 

			//GLfloat focoP[] = {0.0, 9.0, 0.0, 1.0};
			GLfloat *auxV = ta->multV4(0.0, 150.0, 0.0, 1.0);
			GLfloat focoP[] = {auxV[0],auxV[1],auxV[2],auxV[3]};
			cout << focoP[0]<<" " <<focoP[1]<<" " <<focoP[2]<<" " <<focoP[3]<<" " << endl;
			glLightfv(GL_LIGHT0, GL_POSITION, focoP);
			//GLfloat dir[]={0.0,-1.0,0.0};

			auxV = ta->multV4(0.0,-1.0,0.0,0.0);
			GLfloat dir[] = {auxV[0],auxV[1],auxV[2]};
			cout << dir[0]<<" " <<dir[1]<<" " <<dir[2]<<" " <<endl;
			glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

			
			glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, focoA);
			
			

			ObjetoCompuesto::dibuja();
	};
		void increaseA(void){
		focoA += 1.0;
	}
	void decreaseA(void){
		focoA -= 1.0;
	}
	Escena(void);
	~Escena(void);
};

