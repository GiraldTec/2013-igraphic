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

	//Inicializar la escena
	initScene();



}


Scene::~Scene(void)
{
	cout << "se borra la escena" << endl;
}


void Scene::render()
{
	for (unsigned i=0;i<objectsToDraw->size(); i++){
		objectsToDraw->at(i)->render();
	}

	/*
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
	glEnd () ; */
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

bool Scene::reset(void)
{
	// TODO
	return false;
}

void Scene::initScene(){

	objectsToDraw = new vector<DrawablePolygon*>();
/*
	//Primero añadimo los triangulos que forman los bordes
	objectsToDraw->push_back(new Triangle(new PV2D(xRight, yTop), new PV2D(xLeft, yTop), new PV2D(xRight, yTop-50)); //Arriba
	objectsToDraw->push_back(new Triangle(new PV2D(xRight, yTop), new PV2D(xRight, yBot), new PV2D(xRight-50, yTop)); //Derecha
	objectsToDraw->push_back(new Triangle(new PV2D(xLeft, yBot), new PV2D(xRight, yBot), new PV2D(xLeft, yBot+50)); //Abajo
	objectsToDraw->push_back(new Triangle(new PV2D(xLeft, yTop), new PV2D(xLeft, yBot), new PV2D(xLeft+50, yTop)); //Izquierda
	*/
	//Añadimos los obstaculos
	//Cuatro de cada, radio random, centro defininido
	/*randomize();

	objectsToDraw->push_back(new Triangle(new PV2D(50,43),random(10));
	objectsToDraw->push_back(new Triangle(new PV2D(100,12),random(10));
	objectsToDraw->push_back(new Triangle(new PV2D(30,100),random(10));
	objectsToDraw->push_back(new Triangle(new PV2D(300,20),random(10));
	objectsToDraw->push_back(new Circle(new PV2D(245,45),random(10));
	objectsToDraw->push_back(new Circle(new PV2D(45,300),random(10));
	objectsToDraw->push_back(new Circle(new PV2D(90,150),random(10));
	objectsToDraw->push_back(new Circle(new PV2D(180,20),random(10));
	*/
	//Creamos la pelota
	//myBall = new Ball(new PV2D(random(10),random(10)),new PV2D(random(10),random(10)),random(20));
}
/*
void Scene::step(void){
	//ball->step();
}
void Scene::step(void){
	//TODO
	//eliminar pelota!!!! (NO ES NECESARIO REPINTAR LA ESCENA ENTERA, NO??)
	//Comprobar si la pelota golpea
	//if no golpea => myBall->forward(1);
	//if golpea
		//Calcular distancia que puede recorrer
		//myBall->forward(x);
		//myBall->bounce();
	//Dibujar la pelota de nuevo
}
*/