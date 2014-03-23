#include "Malla.h"

Malla::Malla(void){
	this->numVertices = 0;
	this->numNormales = 0;
	this->numCaras = 0;
	this->vertice = new PV3D*[1];
	this->normal = new PV3D*[numCaras];
	this->cara = new Cara*[numCaras];
}

Malla::~Malla(void)
{
}

void Malla::dibuja(){
	for(int i = 0; i < numCaras; i++){
		glLineWidth(1.0);
		glBegin(GL_POLYGON);
		for(int j = 0; j < cara[i]->getNumVertices(); j++){
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}
}


PV3D* Malla::vectorNormalNewell(Cara c){
	PV3D* n = new PV3D();
	for(int i=0; i<c.getNumVertices(); i++){
		PV3D* vertActual = vertice[c.getIndiceVerticeK(i)];
		PV3D* vertSig = vertice[c.getIndiceVerticeK(i+1 % c.getNumVertices())];

		n->setX(n->getX() + (vertActual->getY() - vertSig->getY() * vertActual->getZ() + vertSig->getZ()));
		n->setY(n->getY() + (vertActual->getZ() - vertSig->getZ() * vertActual->getX() + vertSig->getX()));
		n->setZ(n->getZ() + (vertActual->getX() - vertSig->getX() * vertActual->getY() + vertSig->getY()));
	}
	return n->normaliza();
}

void Malla::hazMallaSuperficie(){
	//Dimensiones de la superficie TODO: inicializarlas
	GLdouble uMin, uMax, vMin, vMax;
	//Número de divisiones TODO: inicializarlas
	int nU, nV;
	//Incrementos
	GLdouble incU = (uMax - uMin)/(nU-1);
	GLdouble incV = (vMax - vMin)/(nV-1);

	//Tamaños de los arrays
	numVertices = nU*nV;
	numNormales = numVertices;
	numCaras = (nU-1)*(nV-1);
	//Creación de los arrays
	vertice = new PV3D*[numVertices];
	normal = new PV3D*[numNormales];
	cara = new Cara*[numCaras];

	for(int i=0, u=uMin; i<nU; i++, u+=incU)
		for(int j=0, v=vMin; j<nV; j++, v+=incV){
			int indiceVertice = i*nV + j;
			//Coordenadas del vértice y de la normal (indiceVertice)-ésimo
			vertice[indiceVertice] = new PV3D(x,y,z,1); //TODO: x,y,z
			normal[indiceVertice] = new PV3D(x,y,z,0); //TODO: x,y,z
			normal[indiceVertice]->normaliza();
			//Construcción de caras cuadrangulares
			if (i>0 && j>0){
				int indiceCara = (i-1)*(nV-1) + (j-1);
				VerticeNormal** vn = new VerticeNormal*[4];
				vn[0] = new VerticeNormal(indiceVertice, indiceVertice);
				vn[1] = new VerticeNormal(indiceVertice-nV, indiceVertice-nV);
				vn[2] = new VerticeNormal(indiceVertice-nV-1, indiceVertice-nV-1);
				vn[3] = new VerticeNormal(indiceVertice-1, indiceVertice-1);
				cara[indiceCara] = new Cara(4, vn);
			}
		}
}