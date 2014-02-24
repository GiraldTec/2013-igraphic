#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <Lectora/TextureLoader.h>


typedef GLubyte colorRGBA[3];
typedef GLubyte colorY[3];


class Pixmap
{
	 public:

		unsigned int nCols;
		unsigned int nRows;
		colorRGBA* rgbMap;
		colorY* bwMap;
		bool isbw;

public:
	Pixmap(void);
	~Pixmap(void);
	bool loadFromFile(const char* filepath);
	void fillRGBMap(unsigned char *data, int dp);
	bool loadFromBufer(const int width,const int height, GLint x, GLint y);
	bool drawMatrix(GLint x, GLint y);
	void rotate(GLdouble angle, GLdouble cX, GLdouble cY);
	GLdouble bilinearInterpolation(GLdouble x, GLdouble y, int channel);
	void difference(Pixmap* pm);
	void weightedAverage(double k, Pixmap*pm);
	bool gaussianBlur(void);
};

