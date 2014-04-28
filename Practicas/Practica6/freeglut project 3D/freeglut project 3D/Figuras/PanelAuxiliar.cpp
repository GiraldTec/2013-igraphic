#include "PanelAuxiliar.h"

PanelAuxiliar::PanelAuxiliar(GLint ancho, GLint alto):Malla((ancho+1)*(alto+1),ancho*alto,ancho*alto){
	
	this->ancho = ancho;
	this->alto = alto;

	build();
}


PanelAuxiliar::~PanelAuxiliar(void){
	if(puntos!=NULL)delete puntos;
	if(caras!=NULL)delete caras;
	if(normales!=NULL)delete normales;
}

void PanelAuxiliar::buildPuntos(){
	GLdouble xInicial=-0.5;
	GLdouble yInicial=0.5;
	GLdouble aumentoX = 1.0/ancho;
	GLdouble aumentoY = -1.0/alto;

	for(int i=0;i<alto+1;i++){
		for(int j=0;j<ancho+1;j++){
			int despl=i*(ancho+1)+j;
			puntos->at(despl) = new PV3D(xInicial+j*aumentoX,yInicial+i*aumentoY,0.0);
		}
	}
}

void PanelAuxiliar::buildCaras(){
	for(int k=0;k<caras->size();k++){
		caras->at(k)= new Cara(4);
        vector<VerticeNormal*>* auxNs= new vector<VerticeNormal*>(4);
		/*	a -- b
			c -- d	*/
		int a = (k/ancho)*(ancho+1)+(k%ancho);
		int b = a+1;
		int c = a+ancho+1;
		int d = c+1;

		auxNs->at(0)=new VerticeNormal(a,k);
        auxNs->at(1)=new VerticeNormal(b,k);
        auxNs->at(2)=new VerticeNormal(c,k);
        auxNs->at(3)=new VerticeNormal(d,k);
        
        caras->at(k)->setIndicesVN(auxNs); 
	}
}

void PanelAuxiliar::buildNormales(){
	for(int i=0;i<this->nCaras;i++){
				normales->at(i)= this->doVectorNormalNewell(caras->at(i));
		}
}

void PanelAuxiliar::rotateX(GLfloat angle){
	for(int i=0;i<nPuntos;i++){
		puntos->at(i)->rotateX(angle);
	}
}
void PanelAuxiliar::rotateY(GLfloat angle){
	for(int i=0;i<nPuntos;i++){
		puntos->at(i)->rotateY(angle);
	}
}
void PanelAuxiliar::rotateZ(GLfloat angle){
	for(int i=0;i<nPuntos;i++){
		puntos->at(i)->rotateZ(angle);
	}
}