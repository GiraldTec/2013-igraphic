#include "ObjetoCompuesto.h"


ObjetoCompuesto::ObjetoCompuesto(void){
	componentes=new vector<Objeto3D*>();
}


ObjetoCompuesto::~ObjetoCompuesto(void){
	delete componentes;
	componentes = NULL;
}

void ObjetoCompuesto::addComponente(Objeto3D *o){
	componentes->push_back(o);
}
