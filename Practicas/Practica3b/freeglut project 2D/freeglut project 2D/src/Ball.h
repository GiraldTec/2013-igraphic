//Carlos Giraldo
//Raquel Peces
#pragma once
#include "DrawablePolygon.h"
class Ball : public DrawablePolygon
{
private:
	PV2D* vector;
	GLfloat mTraslación[16];
	GLfloat angulo;
	
public:
	Ball(void);
	~Ball(void);
	Ball(PV2D *c, GLdouble r);

	void forward(GLdouble t);
	void bounce(PV2D* n);
	void render(void){ 
		cout << "hago un render de mi pelotita" << endl;

		glPushMatrix();

		// Aplicamos las transformaciones necesarias de la pelota
		glTranslatef(this->getCenter()->getX(),this->getCenter()->getY(),0);
		glScalef(20,20,0);
		glRotated(angulo,0,0,1);

		renderX(); //la pelota se pinta
		
		glColor3f(0.0,0.0,0.0);
		glLineWidth(5.0);
		glBegin(GL_LINES);
			glVertex2d(0.0,0.0);
			glVertex2d(1.0,0.0);
		glEnd();

		glPopMatrix();

	}
	PV2D* getVector(void);
	void initBall();
};

