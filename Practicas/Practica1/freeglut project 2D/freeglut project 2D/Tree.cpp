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
		//else if (estructura->size()>nivel) nivel++;
		else{
			//FIXME
			vector<Square*> *aux_level = estructura->at(estructura->size()-1);  // Puntero al último nivel
			vector<Square*> *new_level = new vector<Square*>();
			
			for (unsigned j=0; j<aux_level->size(); j++){
				Square *aux_sq = aux_level->at(j);
				Square *right_sq = rightSquare(aux_sq,angle);
				Square *left_sq = leftSquare(aux_sq,angle);

				new_level->push_back(right_sq);
				new_level->push_back(left_sq);

				aux_sq = right_sq = left_sq = NULL;
			}

			estructura->push_back(new_level);
			aux_level = new_level = NULL;
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

			//La idea es solo pintar los cuadrados hasta el nivel que se ha desanidado aunque ya estén calculados

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
	GLdouble pi = M_PI;
	//Calculo del tamaño del lado
	//GLdouble alto = base->getSide()/2;
	//cout<< "EL ALTO ES: " << alto << endl;
	//GLdouble lado = alto/sin(angle);
	GLdouble lado = cos(angle)*base->getSide();
	cout<< "EL LADO ES: " << lado << endl;
	GLdouble alto = base->getSide()/2; // solo sirve para el caso 45º
	GLdouble lado = alto/sin(angle);
	//Calculo de la dirección del lapiz
	GLdouble difX = base->getPoint3()->GetX() - base->getPoint4()->GetX();
	GLdouble difY = base->getPoint3()->GetY() - base->getPoint4()->GetY();
	GLdouble aux_ang = atan2(difY,difX) + angle;
	//Calculo de los vertices
	pen->setDir(aux_ang);
	pen->setPos(base->getPoint4()->clone());
	Point *ver1 = pen->getPos()->clone();
	pen->forward(lado);
	Point *ver2 = pen->getPos()->clone();
	pen->turn(M_PI/2);
	pen->forward(lado);
	Point *ver3 = pen->getPos()->clone();
	pen->turn(M_PI/2);
	pen->forward(lado);
	Point *ver4 = pen->getPos()->clone();
	cout << "Creados 4 vertices" << endl;
	cout << ver1->GetX() << " " << ver2->GetX() << " " << ver3->GetX() << " " << ver4->GetX() <<endl;
	cout << ver1->GetY() << " " << ver2->GetY() << " " << ver3->GetY() << " " << ver4->GetY() <<endl;
	Square *res_sq = new Square(ver1,ver2,ver3,ver4,lado);
	ver1 = ver2 = ver3 = ver4 = NULL;
	return res_sq;
}

Square* Tree::leftSquare(Square *base, GLdouble angle)
{
	//Calculo del tamaño del lado
	//GLdouble alto = base->getSide()/2;
	//cout<< "EL ALTO ES: " << alto << endl;
	//GLdouble lado = alto/cos(angle);
	GLdouble lado = sin(angle)*base->getSide();
	cout<< "EL LADO ES: " << lado << endl;
	//Calculo de la dirección del lapiz
	GLdouble difX = base->getPoint3()->GetX() - base->getPoint4()->GetX();
	GLdouble difY = base->getPoint3()->GetY() - base->getPoint4()->GetY();
	GLdouble aux_ang = atan2(difY,difX) + angle;
	//Calculo de los vertices
	GLdouble aux_angle = M_PI/2 + aux_ang;
	pen->setDir(aux_angle);
	pen->setPos(base->getPoint3()->clone());
	//Estamos situados en el vertice3,que sería el 2 del nuevo cuadrado
	//Avanzamos hasta el vertice 1, y luego volvemos
	pen->forward(lado);
	Point *ver1 = pen->getPos()->clone();
	pen->turn(M_PI);
	pen->forward(lado);
	Point *ver2 = pen->getPos()->clone();
	pen->turn(M_PI/2);
	pen->forward(lado);
	Point *ver3 = pen->getPos()->clone();
	pen->turn(M_PI/2);
	pen->forward(lado);
	Point *ver4 = pen->getPos()->clone();
	cout << "Creados 4 vertices" << endl;
	cout << ver1->GetX() << " " << ver2->GetX() << " " << ver3->GetX() << " " << ver4->GetX() <<endl;
	cout << ver1->GetY() << " " << ver2->GetY() << " " << ver3->GetY() << " " << ver4->GetY() <<endl;
	Square *res_sq = new Square(ver1,ver2,ver3,ver4,lado);
	ver1 = ver2 = ver3 = ver4 = NULL;

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
	int size = estructura->size();

	while(decrease()){}

	for(int i=1; i<size; i++){
		grow();
	}
	
	cout << "Se recalcula el árbol para: " << angle << " radianes" << endl;
}

void Tree::searchSquare(GLdouble x, GLdouble y){
	vector<Square*> *aux_level ;
	Square *aux_sq = NULL;
	GLdouble aux_dist=0;
	Point *point = new Point(x,y);

	cout << "testing 1" <<endl;

	for (unsigned i=0; i<estructura->size(); i++){
		aux_level = estructura->at(i);
		for (unsigned j=0; j<aux_level->size(); j++){
			if(aux_sq==NULL) {
				aux_sq = aux_level->at(j);
				aux_dist = point->distance(aux_sq->getClosestCorner(point));
			}
			else{
				Point *aux_point = aux_level->at(j)->getClosestCorner(point);
				if(point->distance(aux_point)<aux_dist){
					aux_sq = aux_level->at(j);
					aux_dist = point->distance(aux_point);
					cout << "ahora me gusta el cuadrado " << i << " " << j << endl;
				}
				aux_point = NULL;
			}
		}
	}

	// TODO
	//aux_sq->setColor();

	delete point;
	point =NULL;
	aux_level = NULL;
	aux_sq = NULL;
}
