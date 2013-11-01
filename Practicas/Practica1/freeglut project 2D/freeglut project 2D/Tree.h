#pragma once

#include <vector>

#include <Square.h>
#include <Pencil.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;

class Tree
{
private:
	std::vector<vector<Square*>*> *estructura;
	Pencil *pen;
	GLdouble angle;
	//std::vector<Level*> niveles;

public:
	Tree(GLdouble x, GLdouble y, GLdouble d);
	~Tree(void);
	bool grow(void);
	bool decrease(void);
	bool set_angle(GLdouble a);
	GLdouble get_angle(void);
	void init(void);
	void render(void);
	void recalculate(void);
	void firstSquare(GLdouble x, GLdouble y, GLdouble d);
	Square* rightSquare(Square *base, GLdouble angle);
	Square* leftSquare(Square *base, GLdouble angle);
};

