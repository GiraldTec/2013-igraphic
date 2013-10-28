#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class Scene
{
public:
	Scene(void);
	~Scene(void);
	void render(GLdouble xTriangle,GLdouble yTriangle,GLdouble triangleWidth,GLdouble triangleHeight);
};

