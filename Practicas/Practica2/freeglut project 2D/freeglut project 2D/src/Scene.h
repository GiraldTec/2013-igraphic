#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include <vector>
 
#include "Obstacle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Ball.h"

#include <iostream>
using namespace std;

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

	//Vector con todos los obstaculos (incluidos los bordes de la pantalla)
	vector<Obstacle*> *obstacles;
	// Pelota
	Ball* myball;

//	Pelota ball;

	Scene(void);
	~Scene(void);
	void render(void);
	void cam_right(void);
	void cam_left(void);
	void cam_up(void);
	void cam_down(void);
	void cam_in(void);
	void cam_out(void);
	void step(void);
	bool reset(void);

	void initScene(void);
};

