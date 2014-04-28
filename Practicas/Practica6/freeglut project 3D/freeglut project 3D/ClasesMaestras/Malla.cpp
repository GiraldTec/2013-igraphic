#include "Malla.h"


Malla::Malla(int nP, int nC, int nN){
	nPuntos=nP;
	nNormales=nN;
	nCaras=nC;

	this->puntos = new vector<PV3D*>(nPuntos);
	this->caras= new vector<Cara*>(nCaras);
	this->normales = new vector<PV3D*>(nNormales);

}


Malla::~Malla(void)
{
}

PV3D* Malla::doVectorNormalNewell(Cara* c){
	GLdouble x = 0;
	GLdouble y = 0;
	GLdouble z = 0;
	PV3D* currentV;
	PV3D* nextV;
	for (int i=0; i<c->getNumV(); i++){
		currentV = puntos->at(c->getVertexIndex(i));
		nextV = puntos->at(c->getVertexIndex((i+1) % c->getNumV()) );
		x += (currentV->getY()-nextV->getY())*(currentV->getZ()+nextV->getZ());
		y += (currentV->getZ()-nextV->getZ())*(currentV->getX()+nextV->getX());
		z += (currentV->getX()-nextV->getX())*(currentV->getY()+nextV->getY());
	}
	PV3D* aux = new PV3D(x,y,z);
	aux->normalize();
	return aux;
}

void Malla::dibuja(void){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(ta->getM());
		for (int i=0; i<this->nCaras; i++){
			glLineWidth(1.0);
			glColor3f(0.5,0.5,0.5);
				glBegin(GL_POLYGON);
                
				for (int j=0; j<caras->at(i)->getNumV();j++){
					int iN=caras->at(i)->getNormalIndex(j);
					int iV=caras->at(i)->getVertexIndex(j);
					GLfloat nX = normales->at(iN)->getX();
					GLfloat nY = normales->at(iN)->getY();
					GLfloat nZ = normales->at(iN)->getZ();
					glNormal3f(nX,nY,nZ);
					//Si hubiera coordenadas de textura, aqui se suministrarian
					//las coordenadas de textura del vertice j con glTexCoor2f(c);
					GLfloat vX = puntos->at(iV)->getX();
					GLfloat vY = puntos->at(iV)->getY();
					GLfloat vZ = puntos->at(iV)->getZ();
					glVertex3f(vX,vY,vZ);
					}
				glEnd();
		}
	glPopMatrix();
}