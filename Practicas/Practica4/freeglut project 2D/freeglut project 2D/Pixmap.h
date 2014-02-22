#pragma once
#include <gl/GL.h>
#include <GL/gl.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>


typedef GLubyte colorRGBA[3];
typedef GLubyte colorY[3];


class Pixmap
{
	 private:

		unsigned int nCols;
		unsigned int nRows;
		colorRGBA* rgbMap;
		colorY* bwMap;
		bool isbw = false;

    GLdouble matrizGauss[9];
public:
	Pixmap(void);
	~Pixmap(void);
};

