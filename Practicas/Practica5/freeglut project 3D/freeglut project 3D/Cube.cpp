#include "Cube.h"


Cube::Cube(GLdouble x, GLdouble y, GLdouble z) : Malla(6,6,6)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


Cube::~Cube(void)
{
}

void Cube::build()
{
	vertex->at(0) = new PV3D(0,y,0);
	vertex->at(4) = new PV3D(0,y,z);

	vertex->at(1) = new PV3D(0,0,0);
	vertex->at(5) = new PV3D(0,0,z);

	vertex->at(2) = new PV3D(x,0,0);
	vertex->at(6) = new PV3D(x,0,z);

	vertex->at(3) = new PV3D(x,y,0);
	vertex->at(7) = new PV3D(x,y,z);

     

	int nVerticesPorCara=4;

           for(int j=0;j<nVerticesPorCara;j++)
           {
              int numcara= j;
              faces->at(numcara)= new Cara(nVerticesPorCara);
              vector<VerticeNormal*> *arrayParcial = new vector<VerticeNormal*>();
			  //VerticeNormal** arrayParcial= new VerticeNormal*[nVerticesPorCara];

              int base=j;
              int suc=(j+1)%nVerticesPorCara;

              int a= base;
              int b= suc;
              int c= suc+nVerticesPorCara;
              int d= base+nVerticesPorCara;

              arrayParcial->at(0) = new VerticeNormal(a,numcara);
              arrayParcial->at(1) = new VerticeNormal(b,numcara);
              arrayParcial->at(2) = new VerticeNormal(c,numcara);
              arrayParcial->at(3) =	new VerticeNormal(d,numcara);

              faces->at(numcara)->setIndicesVN(arrayParcial);
           }
		//Tapa 1
        faces->at(4) = new Cara(nVerticesPorCara);
		vector<VerticeNormal*> *arrayCara4 = new vector<VerticeNormal*>();
		arrayCara4->at(0) = new VerticeNormal(0,4);
		arrayCara4->at(1) = new VerticeNormal(3,4);
		arrayCara4->at(2) = new VerticeNormal(2,4);
		arrayCara4->at(3) = new VerticeNormal(1,4);
		faces->at(4)->setIndicesVN(arrayCara4);
		//Tapa 2
		faces->at(5) = new Cara(nVerticesPorCara);
		vector<VerticeNormal*> *arrayCara5 = new vector<VerticeNormal*>();
		arrayCara5->at(0) = new VerticeNormal(4,5);
		arrayCara5->at(1) = new VerticeNormal(5,5);
		arrayCara5->at(2) = new VerticeNormal(6,5);
		arrayCara5->at(3) = new VerticeNormal(7,5);
		faces->at(5)->setIndicesVN(arrayCara5);

		for(int i=0; i<this->numFaces;i++)
        {
            PV3D* normal=this->doVectorNormalNewell(faces->at(i));
            normals->at(i) = normal;
        }
}
