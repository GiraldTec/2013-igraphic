//Carlos Giraldo
//Raquel Peces
#include "src/Scene.h"
#include "src/Triangle.h"
#include "src/Ball.h"

Scene::Scene(void)
{
	
	// Scene visible area size
	xLeft= 0.0, xRight= 930.0, yBot= -250.0, yTop= 750.0;

	// Tamaños estandar
	tam_triang_border = 260.0;
	
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
	int i=0;
	while(objectsToDraw->at(i)!=myball){i++;}
	objectsToDraw->erase(objectsToDraw->begin()+i);
	delete myball;
	myball = NULL;
	return true;
}

void Scene::initScene(){

	objectsToDraw = new vector<DrawablePolygon*>();

	// Izquierda down/up
	objectsToDraw->push_back(new Triangle(new PV2D(0.0,5.0), tam_triang_border,M_PI*0.5)); 
	objectsToDraw->push_back(new Triangle(new PV2D(0.0,495.0), tam_triang_border,M_PI*1.5)); 

	// Derecha down/up
	objectsToDraw->push_back(new Triangle(new PV2D(860.0,5.0), tam_triang_border,M_PI*0.5)); 
	objectsToDraw->push_back(new Triangle(new PV2D(860.0,495.0), tam_triang_border,M_PI*1.5)); 

	//Centro down/up
	objectsToDraw->push_back(new Triangle(new PV2D(430.0,-240.0), tam_triang_border,M_PI*1.5)); 
	objectsToDraw->push_back(new Triangle(new PV2D(430.0,740.0), tam_triang_border,M_PI*0.5)); 
	
	//estrella centro
	objectsToDraw->push_back(new Triangle(new PV2D(440.0,250.0), 80,M_PI*0.5)); 
	objectsToDraw->push_back(new Triangle(new PV2D(440.0,250.0), 80,M_PI*1.5)); 

	// 3 Circulos 
	objectsToDraw->push_back(new Circle(new PV2D(660.0,250.0), 60));
	objectsToDraw->push_back(new Circle(new PV2D(240.0,150.0), 50));
	objectsToDraw->push_back(new Circle(new PV2D(500.0,400.0), 70));

	//3 triangulos
	objectsToDraw->push_back(new Triangle(new PV2D(100.0,250.0), 50,M_PI*1)); 
	objectsToDraw->push_back(new Triangle(new PV2D(240.0,550.0), 60,M_PI*1.2)); 
	objectsToDraw->push_back(new Triangle(new PV2D(300.0,100.0), 80,M_PI*1.5)); 


	myball = NULL;
}

bool Scene::step(void){
	if(myball!=NULL){
		GLdouble tInGlobal = 1000.0, tInLocal;
		PV2D *nGlobal=NULL, *nLocal=NULL;
		//bool b =((Obstacle*)objectsToDraw->at(0))->collide(myball,tInGlobal,nGlobal);
		for(unsigned i=0;i<objectsToDraw->size();i++){
			if(objectsToDraw->at(i)!=myball){
				if(((Obstacle*)objectsToDraw->at(i))->collide(myball,tInLocal,nLocal)){
					if((tInLocal>0)&&(tInLocal<tInGlobal)){
						tInGlobal = tInLocal;
						nGlobal = nLocal;
					}
				}
			}
		}
		//cout << tInGlobal << endl;
		if((tInGlobal>0.01)&&(tInGlobal < 1)){
			//tInGlobal /= myball->getVector()->calculateMod();
			myball->forward(tInGlobal);
			cout << tInGlobal << endl;
			cout << myball->getVector()->getX() << "  " << myball->getVector()->getY() << endl;
			cout << nGlobal->getX() << "  " << nGlobal->getY() << endl;
			myball->bounce(nGlobal);
			cout << myball->getVector()->getX() << "  " << myball->getVector()->getY() << endl;
		}else{
			myball->forward(1);
		}
		//cout << myball->getVector()->getX() << "  " << myball->getVector()->getY() << endl;
		return true;
	}
	return false;
}


bool Scene::mouse_input(GLdouble x, GLdouble y)
{
	if (myball == NULL){
		myball = new Ball(new PV2D(x,y),20.0);
		objectsToDraw->push_back(myball);
		return true;
	}else return false;
}