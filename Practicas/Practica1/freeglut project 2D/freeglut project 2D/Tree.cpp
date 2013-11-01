#include "Tree.h"



Tree::Tree(GLdouble x, GLdouble y, GLdouble d)
{
	angle=M_PI/4;
	firstSquare(x,y,d);
}


Tree::~Tree(void)
{
	estructura = NULL;
	pen = NULL;
	cout << "Se borra el arbol" << endl;
}

bool Tree::set_angle(GLdouble a){ // angulo en grados

	GLdouble aux = std::floor(a / 360);
	cout << aux << endl;
	aux = a - (360*aux);
	cout << aux << endl;
	angle = aux * (2 * M_PI) / 360;

	recalculate();

	return true;
}

GLdouble Tree::get_angle(void){
	return angle;
}

bool Tree::grow(void){
	if(estructura!=NULL){
		if(estructura->size()>10) return false;
		else{
			//FIXME
		/*	vector<Square*> *aux_level = estructura->at(estructura->size()-1);  // Puntero al último nivel
			vector<Square*> *new_level = new vector<Square*>();
			
			for (unsigned j=0; j<aux_level->size(); j++){
				Square *aux_sq = aux_level->at(j);
				Square *right_sq = rightSquare(aux_sq);
				Square *left_sq = leftSquare(aux_sq);

				new_level->push_back(right_sq);
				new_level->push_back(left_sq);

				aux_sq = right_sq = left_sq = NULL;
			}

			estructura->push_back(new_level);
			aux_level = new_level = NULL;*/
			return true;
		}
	}else return false;
}

bool Tree::decrease(void){
	if (estructura!=NULL){
		if(estructura->size()==1) return false;
		else{
			estructura->pop_back(); // llama al destructor del vector que llama a la destructora de los contenedores... 
									//igual no hay que romperse el coco

			/* // sino...
				// TODO
			*/

			return true;
		}
	}else{
		return false;
	}
}

void Tree::render(void){
	if(estructura != NULL){
		vector<Square*> *aux_level ;

		for (unsigned i=0; i<estructura->size(); i++){
			aux_level = estructura->at(i);
			for (unsigned j=0; j<aux_level->size(); j++){
				aux_level->at(j)->render();
			}
		}

		aux_level = NULL;
	}
}

Square* Tree::rightSquare(Square *base, GLdouble angle)
{
	Square *res_sq;
	//TODO
	return res_sq;
}

Square* Tree::leftSquare(Square *base, GLdouble angle)
{
	Square *res_sq;
	//TODO
	return res_sq;
}

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

void Tree::recalculate(void){
	cout << "Se recalcula el árbol para: " << angle << " radianes" << endl;
	// TODO
}