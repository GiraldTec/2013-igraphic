#include "Ball.h"


Ball::Ball(void)
{
}


Ball::~Ball(void)
{
}

Ball::Ball(PV2D* c, PV2D* v, GLdouble r){
	this->center = c;
	this->vector = v;
	this->radius = r;
	nSides = 13;
	initBall();
}

void Ball::forward(GLdouble t){
	//Metodo para avanzar una pelota, el incremento de t veces el vector de la pelota
	GLdouble incX = t*vector->GetX();
	GLdouble incY = t*vector->GetY();
	for (int i=0; i<vertex->size(); i++){
		vertex->at(i)->setX(vertex->at(i)->GetX() + incX);
		vertex->at(i)->setY(vertex->at(i)->GetY() + incY);
	}
	center->setX(center->GetX + incX);
	center->setY(center->GetY + incY);
}

void Ball::bounce(PV2D* normal){
	//Metodo que calcula el rebote de la pelota, hay que hacer la reflexion del vector
	//Se calcula a partir de la normal
	vector->reflection(normal);
}

void Ball::render(){
	//Renderización de la pelota
	glBegin (GL_POLYGON);
	for (int i=0;i<nSides;i++){
		glVertex2d( vertex->at(i)->GetX(), vertex->at(i)->GetY() );
	}
	glEnd();
}

void Ball::initBall(){
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

}




