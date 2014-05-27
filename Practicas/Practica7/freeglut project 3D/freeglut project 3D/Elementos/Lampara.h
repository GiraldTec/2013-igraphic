//Carlos Giraldo
//Raquel Peces
#pragma once
#include "../ClasesMaestras/ObjetoCompuesto.h"
#include "../Figuras/Cilindro.h"
#include "../Figuras/Disco.h"
#include "../Figuras/Cubo.h"
#include "../Figuras/Esfera.h"
#include <iostream>
using namespace std;

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class Lampara	: public ObjetoCompuesto{

public:
	GLfloat focoA;
	void increaseA(void){
		focoA += 1.0;
	}
	void decreaseA(void){
		focoA -= 1.0;
	}
	Lampara(void);
	void dibuja(void){
		
		GLfloat focoP[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat dir[]={0.0,-1.0,0.0};

		cout << "blablabla" << endl;
		// LIGHT0
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
				// Foco de la lámpara
			//glEnable(GL_LIGHT0);
			glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, focoA);
			glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 4.0);
	

			GLfloat d[]={1.0,1.0,1.0,1.0};
			glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
			GLfloat a[]={0.3f,0.3f,0.3f,1.0};
			glLightfv(GL_LIGHT0, GL_AMBIENT, a); 

				
			//GLfloat *auxV = ta->multV4(0.0, 150.0, 0.0, 1.0);
			//GLfloat focoP[] = {auxV[0],auxV[1],auxV[2],auxV[3]};
			//cout << focoP[0]<<" " <<focoP[1]<<" " <<focoP[2]<<" " <<focoP[3]<<" " << endl;
			glLightfv(GL_LIGHT0, GL_POSITION, focoP);
				

			//auxV = ta->multV4(0.0,-1.0,0.0,0.0);
			//Lfloat dir[] = {auxV[0],auxV[1],auxV[2]};
			//cout << dir[0]<<" " <<dir[1]<<" " <<dir[2]<<" " <<endl;
			glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

			
			glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, focoA);
			
		glPopMatrix();

			ObjetoCompuesto::dibuja();
	};
	~Lampara(void);
};

