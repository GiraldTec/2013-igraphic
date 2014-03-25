#pragma once

#include <array>

class Matriz
{
public:
	int filas, columnas;
	double* data;
	Matriz(int f, int c){
		filas = f;
		columnas = c;
		data = NULL;	
	};
	~Matriz(void){
		delete data;
	};

	void setData(double* d, int size){
		data = new double[size];
		for(int i=0; i<size; i++){
			data[i] = d[i];
		}	
	}

	void suma(Matriz* oM);
	void resta(Matriz* oM);
	void productoM(Matriz* oM);
	void producto(double d);
};