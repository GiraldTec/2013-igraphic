#include "Scene.h"



Scene::Scene(void)
{
	
	// Scene visible area size
	xLeft= 0.0, xRight= 500.0, yBot= 0.0, yTop= 500.0;

	// Scene variables
	xTriangle= 0.0, yTriangle= 0.0;
	triangleWidth= 100.0, triangleHeight= 50.0;

	// Scene colors
	red=1.0, blue=0.0, green=0.0;

	// Whether there is a tree in the scene
	arbol = NULL;
}


Scene::~Scene(void)
{
	if (arbol!=NULL) {delete arbol;	arbol = NULL;}

	cout << "se borra la escena" << endl;
}


void Scene::render()
{
	//arbol->render();
	
	blue = 1.0;
	glColor3f(red,blue,green);

	glBegin(GL_QUADS);
		glVertex2d( xTriangle, yTriangle );
		glVertex2d( xTriangle + triangleWidth, yTriangle );
		glVertex2d( xTriangle + triangleWidth, yTriangle + triangleHeight );
		glVertex2d( xTriangle, yTriangle + triangleHeight );
    glEnd();

	blue = 0.0;
	glColor3f(red,blue,green);

	glBegin ( GL_TRIANGLES ) ;
		glVertex2d( xTriangle, yTriangle );
		glVertex2d( xTriangle + triangleWidth, yTriangle );
		glVertex2d( xTriangle + triangleWidth, yTriangle + triangleHeight );
	glEnd () ; 
}


void Scene::cam_right(void)
{
	xRight += 10.0;
	xLeft += 10.0;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft, xRight, yBot, yTop);
}


void Scene::cam_left(void)
{
	xRight -= 10.0;
	xLeft -= 10.0;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft, xRight, yBot, yTop);
}


void Scene::cam_up(void)
{
	yTop += 10.0;
	yBot += 10.0;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft, xRight, yBot, yTop);
}


void Scene::cam_down(void)
{
	yTop -= 10.0;
	yBot -= 10.0;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft, xRight, yBot, yTop);
}


void Scene::cam_in(void)
{
	if((yTop-yBot<10)||(xRight-xLeft<20)){}
	else{
		yTop -= 5.0;
		yBot += 5.0;
		xRight -= 10.0;
		xLeft += 10.0;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xLeft, xRight, yBot, yTop);
	}
}


void Scene::cam_out(void)
{
	yTop += 5.0;
	yBot -= 5.0;
	xRight += 10.0;
	xLeft -= 10.0;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft, xRight, yBot, yTop);
}


bool Scene::mouse_input(GLdouble x, GLdouble y)
{
	if (arbol != NULL) return false;
	//TODO buscar si hay cuadrado cerca
	//arbol.searchSquare(x, y);
	else {
		arbol = new Tree(x, y);
		return true;
	}
}

bool Scene::reset(void)
{
	if (arbol == NULL) return false;
	else{
		delete arbol;
		arbol = NULL;
		return true;
	}
}

bool Scene::tree_grow(void){
	if (arbol == NULL) return false;
	return arbol->grow();
}

bool Scene::tree_drecrease(void){
	if (arbol == NULL) return false;
	return arbol->decrease();
}