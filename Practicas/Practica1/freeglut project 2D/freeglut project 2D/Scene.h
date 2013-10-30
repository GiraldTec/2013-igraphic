#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

#include <iostream>
using namespace std;

#include <Tree.h>

class Scene
{
public:

	
	// Scene visible area size
	GLdouble xLeft, xRight, yBot, yTop;

	// Scene variables
	GLdouble xTriangle, yTriangle;
	GLdouble triangleWidth, triangleHeight;

	// Scene colors
	GLfloat red, blue, green;
	
	// Tree
	Tree* arbol;

	Scene(void);
	~Scene(void);
	void render(void);
	void cam_right(void);
	void cam_left(void);
	void cam_up(void);
	void cam_down(void);
	void cam_in(void);
	void cam_out(void);
	bool mouse_input(GLdouble x, GLdouble y);
	bool reset(void);
	bool tree_grow(void);
	bool tree_drecrease(void);
};

