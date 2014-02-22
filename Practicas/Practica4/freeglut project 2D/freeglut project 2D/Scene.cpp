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
	if (arbol != NULL)
		arbol->render();
	
	blue = 1.0;
	glColor3f(red,blue,green);

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
	GLdouble ratio = (xRight-xLeft)/(yTop-yBot);
	GLdouble x_des = 3;
	GLdouble y_des = x_des/ratio;

	if((yTop-yBot<10)||(xRight-xLeft<20)){}
	else{
		yTop -= y_des;
		yBot += y_des;
		xRight -= x_des;
		xLeft += x_des;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xLeft, xRight, yBot, yTop);
	}
}


void Scene::cam_out(void)
{
	GLdouble ratio = (xRight-xLeft)/(yTop-yBot);
	GLdouble x_des = 3;
	GLdouble y_des = x_des/ratio;
	
	yTop += y_des;
	yBot -= y_des;
	xRight += x_des;
	xLeft -= x_des;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft, xRight, yBot, yTop);
}


bool Scene::mouse_input(GLdouble x, GLdouble y)
{
	if (arbol != NULL){
		arbol->searchSquare(x, y);	
		return true;
	}else {
			cout << "Introduce un tamaño para el cuadrado: ";
			GLdouble lado;
			cin >> lado;
			arbol = new Tree(x, y, lado);
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

bool Scene::read_angle(void){
	bool got_angle=false;
	GLdouble angle;  // en grados
	if(arbol!=NULL){
		while(!got_angle){
			cout << "Inserte el ángulo deseado en grados (formato [XX.XX])" << endl;
			cin >> angle;
			got_angle = arbol->set_angle(angle);
		}
	}
	return got_angle;
}