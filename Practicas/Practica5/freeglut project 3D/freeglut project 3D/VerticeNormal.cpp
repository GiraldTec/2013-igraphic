//Carlos Giraldo
//Raquel Peces
#include "VerticeNormal.h"

VerticeNormal::VerticeNormal(int v, int n){
	this->indexV = v;
	this->indexN = n;
}
VerticeNormal::~VerticeNormal(void){}
//------------------------------------
int VerticeNormal::getNormal(){
	return indexN;
}
int VerticeNormal::getVertex(){
	return indexV;
}