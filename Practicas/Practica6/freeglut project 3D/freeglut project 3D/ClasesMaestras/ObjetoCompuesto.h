#pragma once
#include "Objeto3D.h"

#include <vector>
using namespace std;

class ObjetoCompuesto : public Objeto3D
{
private:
	int numHijos;
	std::vector<Objeto3D*> *componentes;

public:
	ObjetoCompuesto(void);
	~ObjetoCompuesto(void);

	void addComponente(Objeto3D *o);

	void dibuja(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(ta->getM());
			for(unsigned i=0;i<componentes->size();i++){
				componentes->at(i)->dibuja();
			}
		glPopMatrix();
	}
};
