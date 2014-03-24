#include "Malla.h"


Malla::Malla(){
}

Malla::Malla(int nV, int nF, int nN)
{
	this->numVertex = nV;
	this->numFaces = nF;
	this->numNormals = nN;

	this->vertex = new vector<PV3D*>(numVertex);
	this->faces = new vector<Cara*>(numFaces);
	this->normals = new vector<PV3D*>(numNormals);
}


Malla::~Malla(void)
{

}

PV3D* Malla::doVectorNormalNewell(Cara* c)
{
	GLdouble x = 0;
	GLdouble y = 0;
	GLdouble z = 0;
	PV3D* currentV;
	PV3D* nextV;
	for (int i=0; i<c->getNumV(); i++){
		currentV = vertex->at(c->getVertexIndex(i));
		nextV = vertex->at(c->getVertexIndex(i+1) % c->getNumV());
		x += (currentV->getY()-nextV->getY())*(currentV->getZ()+nextV->getZ());
		y += (currentV->getZ()-nextV->getZ())*(currentV->getX()+nextV->getX());
		z += (currentV->getX()-nextV->getX())*(currentV->getY()+nextV->getY());
	}
	PV3D* aux = new PV3D(x,y,z);
	aux->normalize();
	return aux;
}

void Malla::draw(bool fill, bool drawN)
{

	cout << "a dibujar la malla" << endl;
	for (int i=0; i<this->numFaces; i++){
           glLineWidth(1.0);
           glColor3f(0,0,0);
                if(!fill){
                   glBegin(GL_LINE_LOOP);
                }
                else{
                  glBegin(GL_POLYGON);
                }
				for (int j=0; j<faces->at(i)->getNumV();j++){
					int iN=faces->at(i)->getNormalIndex(j);
					int iV=faces->at(i)->getVertexIndex(j);
					glNormal3f(normals->at(iN)->getX(),normals->at(iN)->getY(),normals->at(iN)->getZ());
					//Si hubiera coordenadas de textura, aqui se suministrarian
					//las coordenadas de textura del vertice j con glTexCoor2f(c);
					glVertex3f(vertex->at(iV)->getX(),vertex->at(iV)->getY(),vertex->at(iV)->getZ());
					}
                glEnd();
    }
	if(drawN){
        //dibujamos las normales
		for(int i=0;i<this->numFaces;i++){
            int iN=faces->at(i)->getNormalIndex(0);

            GLdouble sumax=0;
            GLdouble sumay=0;
            GLdouble sumaz=0;
			for (int j=0;j<faces->at(i)->getNumV();j++){
				sumax=sumax+vertex->at(faces->at(i)->getVertexIndex(j))->getX();
				sumay=sumay+vertex->at(faces->at(i)->getVertexIndex(j))->getY();
				sumaz=sumaz+vertex->at(faces->at(i)->getVertexIndex(j))->getZ();
            }
			sumax=sumax/faces->at(i)->getNumV();
            sumay=sumay/faces->at(i)->getNumV();
            sumaz=sumaz/faces->at(i)->getNumV();

            PV3D* normalbase=normals->at(iN);

            GLdouble xaux,yaux,zaux;
            xaux=sumax+normalbase->getX();
            yaux=sumay+normalbase->getY();
            zaux=sumaz+normalbase->getZ();

            glColor3f(1,1,1);
            glBegin(GL_LINES);
                    glVertex3f(sumax,sumay,sumaz);
                    glVertex3f(xaux,yaux,zaux);
            glEnd();
        }
	}
}
