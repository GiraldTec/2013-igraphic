#pragma once

#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <iostream>


typedef GLubyte colorRGBA[3];
typedef GLubyte colorY[3];


class Pixmap
{
	 private:

		unsigned int nCols;
		unsigned int nRows;
		colorRGBA* rgbMap;
		colorY* bwMap;
		bool isbw;

    GLdouble matrizGauss[9];
public:
	Pixmap(void);
	~Pixmap(void);
	bool loadFromBufer(int width, int height, GLfloat x, GLfloat y);
	bool drawMatrix(void);
};

