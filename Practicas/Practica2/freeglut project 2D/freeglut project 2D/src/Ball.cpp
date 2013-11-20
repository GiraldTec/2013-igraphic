#include "Ball.h"


Ball::Ball(void)
{
}


Ball::~Ball(void)
{
}

Ball::Ball(PV2D *c,int n, GLdouble r):DrawablePolygon(c,n,r){
	// TODO ¿qué más le metemos a la pelota?
}

void Ball::forward(GLdouble t){
	/* TODO ---> Como todo se tiene que hacer tocando los atributos privados de DrawablePolygon hay que usar geters y seters
	//Metodo para avanzar una pelota, el incremento de t veces el vector de la pelota
	GLdouble incX = t*vector->GetX();
	GLdouble incY = t*vector->GetY();
	for (int i=0; i<vertex->size(); i++){
		vertex->at(i)->setX(vertex->at(i)->GetX() + incX);
		vertex->at(i)->setY(vertex->at(i)->GetY() + incY);
	}
	center->setX(center->GetX + incX);
	center->setY(center->GetY + incY);
	*/
}

void Ball::bounce(PV2D* normal){
	//Metodo que calcula el rebote de la pelota, hay que hacer la reflexion del vector
	//Se calcula a partir de la normal
	//vector->reflection(normal);
}

void Ball::initBall(){
	/*
	TODO hacer genérico en drawable polygon
	pencil = new Pencil(center->clone());
	//Calculo de los n lados que simularán la pelota
	//Caluclo del angulo en el que se divide la circunferencia
	GLdouble alfa=2*PI/nSides;
	//Calculo tamaño del lado
	GLdouble tam=(radius*sin(alfa/2))*2;
	//Calculo del angulo de giro del lápiz
	GLdouble beta=(PI-alfa)/2;
	//Colocamos el lapiz a una distancia r del centro;
	pencil->forward(radius);
	pencil->turn(PI-beta);
	
	//CALCULO DE LOS VERTICES DE LA PELOTA;
	vertex = new vector<PV2D*>();
	for (int i=0; i<nSides; i++){
		PV2D *aux_p = pencil->getPos()->clone();
		vertex->push_back(aux_p);
		pencil->forward(tam);
		pencil->turn(beta);	
	}
	*/
}




