#include "Tree.h"


Tree::Tree(GLdouble x, GLdouble y, GLdouble d)
{
	firstSquare(x,y,d);
}


Tree::~Tree(void)
{
	cout << "Se borra el arbol" << endl;
}

bool Tree::grow(void){
	return true;
}

bool Tree::decrease(void){
	return true;
}

void Tree::render(void){
	if(estructura != NULL){
		
	}
}

//void Tree::rightSquare()
//{
//}

//void Tree::leftSquare()
//{
//}

void Tree::firstSquare(GLdouble x, GLdouble y, GLdouble d)
{
	Point *aux_p = new Point(x,y);
	GLdouble pi = M_PI;
	pen = new Pencil(aux_p,pi);
	pen->forward(d/2);
	pen->turn(pi/2);
	pen->forward(d/2);
	//VERTICE 1
	Point *ver1 = pen->getPos();
	pen->setDir(0);
	pen->forward(d);
	//VERTICE 2
	Point *ver2 = pen->getPos();
	pen->turn(pi/2);
	pen->forward(d);
	//VERTICE 3
	Point *ver3 = pen->getPos();
	pen->turn(pi/2);
	pen->forward(d);
	//VERTICE 4
	Point *ver4 = pen->getPos();

	Square *s = new Square(ver1,ver2,ver3,ver4,d);

	estructura = new vector<vector<Square*>*>();
	vector<Square*> *aux_level = new vector<Square*>();
	aux_level->push_back(s);
	estructura->push_back(aux_level);

	ver1 = ver2 = ver3 = ver4 = aux_p = NULL;
	s = NULL;

}


