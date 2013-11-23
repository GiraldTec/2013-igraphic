#include "Triangle.h"


Triangle::Triangle(void)
{
}


Triangle::Triangle(PV2D *c, GLdouble r,GLdouble o):Obstacle(c,3,r,o,0,0,1)
{
}

Triangle::~Triangle(void)
{
}

void Triangle::doNormals(){
	//Calculo de las normales de mi triangulo

}
/*  Esto se debe hacer generico en 
void Triangle::doVertex(){
	pencil = new Pencil(center->clone(),0);
	//Calculo de los vertices a partir del centro (circuncentro o punto donde se cruzan las medianas)
	GLdouble alfa=2*PI/3;
	//Calculo tamaño del lado
	GLdouble tam=(radius*sin(alfa/2))*2;
	//Calculo del angulo de giro del lápiz
	GLdouble beta=(PI-alfa)/2;
	//Colocamos el lapiz a una distancia r del centro;
	pencil->forward(radius);
	pencil->turn(PI-beta);

	vertex = new vector<PV2D*>();
	for (int i=0; i<3; i++){
		PV2D *aux_p = pencil->getPos()->clone();
		vertex->push_back(aux_p);
		pencil->forward(tam);
		pencil->turn(beta);	
	}

}
*/

