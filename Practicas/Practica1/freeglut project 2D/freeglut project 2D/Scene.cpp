#include "Scene.h"



Scene::Scene(void)
{
}


Scene::~Scene(void)
{
}


void Scene::render(GLdouble xTriangle,GLdouble yTriangle,GLdouble triangleWidth,GLdouble triangleHeight)
{
	glBegin(GL_QUADS);
	glVertex2d( xTriangle, yTriangle );
    glVertex2d( xTriangle + triangleWidth, yTriangle );
    glVertex2d( xTriangle + triangleWidth, yTriangle + triangleHeight );
	glVertex2d( xTriangle, yTriangle + triangleHeight );
    glEnd();
}
