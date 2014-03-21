/***********************************
*	Carlos Gabriel Giraldo García
*	Raquel Peces Muñoz
*	Práctica 4
*
************************************/
#pragma once


#include <math.h>

class PV3D
{
private:
	double coorX;
	double coorY;
	double coorZ;

public:
	
	PV3D(void);
	~PV3D(void);
	PV3D(double x, double y, double z);
	double getX();
	void setX(double x);
	double getY();
	void setY(double y);
	double getZ();
	void setZ (double z);

	PV3D* clone();
	PV3D* addition(PV3D* v);
	PV3D* subtraction(PV3D* v);
	
};

