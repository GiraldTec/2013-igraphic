#include "Tree.h"


Tree::Tree(GLdouble x, GLdouble y, GLdouble d)
{
	firstSquare(x,y,d);
}


Tree::~Tree(void)
{
	estructura = NULL;
	pen = NULL;
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
		for (unsigned i=0; i<estructura->size(); i++){
			vector<Square*> *aux_level = estructura->at(i);
			for (unsigned j=0; j<aux_level->size(); j++){
				aux_level->at(j)->render();
			}
		}
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
	cout << pen->getPos()->GetX() << pen->getPos()->GetY() << endl;
	pen->turn(pi/2);
	pen->forward(d/2);
	cout <<  pen->getPos()->GetX() << pen->getPos()->GetY() << endl;
	//VERTICE 1
	Point *ver1 = pen->getPos()->clone();
	pen->setDir(0);
	pen->forward(d);
	cout << ver1->GetX() << " " << ver1->GetY() << endl;
	//VERTICE 2
	Point *ver2 = pen->getPos()->clone();
	pen->turn(pi/2);
	pen->forward(d);
	//VERTICE 3
	Point *ver3 = pen->getPos()->clone();
	pen->turn(pi/2);
	pen->forward(d);
	//VERTICE 4
	Point *ver4 = pen->getPos()->clone();
	cout << "Creados 4 vertices" << endl;
	cout << ver1->GetX() << " " << ver2->GetX() << " " << ver3->GetX() << " " << ver4->GetX() <<endl;
	cout << ver1->GetY() << " " << ver2->GetY() << " " << ver3->GetY() << " " << ver4->GetY() <<endl;
	Square *s = new Square(ver1,ver2,ver3,ver4,d);

	estructura = new vector<vector<Square*>*>();
	vector<Square*> *aux_level = new vector<Square*>();
	aux_level->push_back(s);
	estructura->push_back(aux_level);

	ver1 = ver2 = ver3 = ver4 = aux_p = NULL;
	s = NULL;
	aux_level = NULL;

}


