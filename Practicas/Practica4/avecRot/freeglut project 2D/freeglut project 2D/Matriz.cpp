#include "Matriz.h"


void Matriz::suma(Matriz* oM)
{
	double *auxD = new double[filas*columnas];
	for (int i = 0; i < filas*columnas; i++) {
      auxD[i] = data[i] + oM->data[i];
    }
	delete data;
	data = auxD;
}

void Matriz::resta(Matriz* oM)
{
	double *auxD = new double[filas*columnas];
	for (int i = 0; i < filas*columnas; i++) {
      auxD[i] -= oM->data[i];
    }
	delete data;
	data = auxD;
}

void Matriz::productoM(Matriz* oM){ // Mi matriz de NxM con otra de MxÑ
	int auxC = oM->columnas;
	double *auxD = new double[filas*auxC];
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < auxC; j++) {
			double dato = 0;
			for(int m = 0; m < oM->filas ; m++){
				dato += data[i*columnas+m]*oM->data[m*auxC+j];
			}
			auxD[i*auxC+j]=dato;
		}
	}

	delete data;
	columnas = auxC;
	data = auxD;
}
void Matriz::producto(double d){ 
	double *auxD = new double[filas*columnas];
	for (int i = 0; i<filas*columnas ; i++){
		auxD[i] = data[i]*d;
	}
	delete data;
	data = auxD;
}