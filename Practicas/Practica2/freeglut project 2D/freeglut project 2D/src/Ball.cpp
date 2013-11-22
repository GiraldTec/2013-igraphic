#include "Ball.h"


Ball::Ball(void)
{
}


Ball::~Ball(void)
{
}

Ball::Ball(PV2D *c, GLdouble r):DrawablePolygon(c,20,r,0,1,0,0){
	// TODO ¿qué más le metemos a la pelota?
	this->vector = new PV2D(10,0);
}

void Ball::forward(GLdouble t){
	//Metodo para avanzar una pelota, el incremento de t veces el vector de la pelota
	GLdouble incX = t*vector->getX();
	GLdouble incY = t*vector->getY();
	for (int i=0; i<getVertex()->size(); i++){
		getVertex()->at(i)->setX(getVertex()->at(i)->getX() + incX);
		getVertex()->at(i)->setY(getVertex()->at(i)->getY() + incY);
	}
	PV2D *aux_point = new PV2D(getCenter()->getX() + incX, getCenter()->getY() + incY);
	setCenter(aux_point);
}

void Ball::bounce(PV2D* normal){
	//Metodo que calcula el rebote de la pelota, hay que hacer la reflexion del vector
	//Se calcula a partir de la normal
	vector->reflection(normal);
}

void Ball::initBall(){
}




