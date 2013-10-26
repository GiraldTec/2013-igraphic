#pragma once

#include "point.h"

class square
{
public:
	square(void);
	~square(void);
	//Definicion de los cuatro vertices
	point corner1;
	point corner2;
	point corner3;
	point corner4;

	int width;

	//Metodos

	void drawSquare();
};

