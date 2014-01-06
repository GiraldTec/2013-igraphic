//Carlos Giraldo
//Raquel Peces

#include "Elipse.h"

Elipse::Elipse(void)
{
}

Elipse::Elipse(PV2D *c, GLdouble pX, GLdouble pY):Obstacle(c,20,1,0,1,1,0)
{

	calcula_vertices(new PV2D());
	propX = pX;
	propY = pY;
	/*glPushMatrix();
		glTranslatef(c->getX(),c->getY(),0);
		//glRotatef(angle,ax,ay,az);
		glScalef(100,50,0);
		glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-c->getX(), -c->getY(), 0);
		//glRotatef(-angle, ax, ay, az);
		glScalef(1/100,1/50,0);
		glGetFloatv(GL_MODELVIEW_MATRIX, inv_matrix);
	glPopMatrix();*/
}


Elipse::~Elipse(void)
{
}

PV2D* Elipse::multMatriz(GLfloat* matriz, PV2D* punt, int tipo){
	PV2D* aux = new PV2D();
	GLfloat corX = (((*(matriz+0))*(punt->getX()))+((*(matriz+4))*(punt->getY()))+((*(matriz+12))*(tipo)));
	GLfloat corY = (((*(matriz+1))*(punt->getX()))+((*(matriz+5))*(punt->getY()))+((*(matriz+13))*(tipo)));
	//corY = corY+punt->getY();
	aux->setX(corX);
	aux->setY(corY);
	cout << *(matriz+0) << " " << *(matriz+4) << " " << *(matriz+8) << " " << *(matriz+12) << " "  << *(matriz+1) << " " << *(matriz+5) << " " << *(matriz+9) << " " << *(matriz+13) <<  endl;
	cout << "Cordenadas viejas: " << punt->getX() << "   " << punt->getY() << endl;
	cout << "Cordenadas nuevas: " << corX << "   " << corY << endl;
	return aux;
}

PV2D* Elipse::multMatrizT(GLfloat* matriz, PV2D* punt, int tipo){
	PV2D* aux = new PV2D();
	GLfloat corX = (((*(matriz+0))*(punt->getX()))+((*(matriz+1))*(punt->getY()))+((*(matriz+3))*(tipo)));
	GLfloat corY = (((*(matriz+4))*(punt->getX()))+((*(matriz+5))*(punt->getY()))+((*(matriz+7))*(tipo)));
	//corY = corY+punt->getY();
	aux->setX(corX);
	aux->setY(corY);
	//cout << *(matriz+0) << " " << *(matriz+4) << " " << *(matriz+8) << " " << *(matriz+12) << " "  << *(matriz+1) << " " << *(matriz+5) << " " << *(matriz+9) << " " << *(matriz+13) <<  endl;
	//cout << "Cordenadas viejas: " << punt->getX() << "   " << punt->getY() << endl;
	//cout << "Cordenadas nuevas: " << corX << "   " << corY << endl;
	return aux;
}
