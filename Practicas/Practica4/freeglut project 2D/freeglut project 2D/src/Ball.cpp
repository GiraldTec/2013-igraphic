//Carlos Giraldo
//Raquel Peces
#include "Ball.h"


Ball::Ball(void)
{
}


Ball::~Ball(void)
{
}

Ball::Ball(PV2D *c, GLdouble r):DrawablePolygon(c,20,1,0,1,0,0){
	// bola centrada en el origen
	this->calcula_vertices(new PV2D(0.0,0.0));
	this->vector = new PV2D(0,10); // velocidad por defecto
	angulo =0;
	sHorario = false;
}

void Ball::forward(GLdouble t){
	//Metodo para avanzar una pelota, el incremento de t veces el vector de la pelota
	GLdouble incX = t*vector->getX();
	GLdouble incY = t*vector->getY();
	PV2D *aux_point = new PV2D(getCenter()->getX() + incX, getCenter()->getY() + incY);
	if(t<1) sHorario = !sHorario;
	if(!sHorario) {angulo += 5; if(angulo>360)angulo -= 360;}
	else {angulo -= 5; if(angulo<0)angulo += 360;}
	
	
	setCenter(aux_point);
}

void Ball::bounce(PV2D* normal){
	//Metodo que calcula el rebote de la pelota, hay que hacer la reflexion del vector
	//Se calcula a partir de la normal
	vector->reflection(normal);
}

void Ball::initBall(void){
}

PV2D* Ball::getVector(void){
	return this->vector;
}




