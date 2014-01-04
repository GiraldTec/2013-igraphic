//Carlos Giraldo
//Raquel Peces
#pragma once
#include "DrawablePolygon.h"
class Ball : public DrawablePolygon
{
private:
	PV2D* vector;
	GLdouble dir;
	PV2D* v_dir;
	
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

		renderX();
		glColor3f(0,0,0);
		glBegin(GL_LINE);
			glVertex2d(getCenter()->getX(), getCenter()->getY());
			glVertex2d(getVertex()->at(0)->getX(),getVertex()->at(0)->getY());
		glEnd();

		glPopMatrix();

	}
	PV2D* getVector(void);
	void initBall();
	void calculateDir();
};

