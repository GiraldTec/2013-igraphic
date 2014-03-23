#include "Cube.h"


Cube::Cube(GLdouble x, GLdouble y, GLdouble z)
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
              VerticeNormal** arrayParcial= new VerticeNormal*[nVerticesPorCara];

              int base=j;
              int suc=(j+1)%nVerticesPorCara;

              int a= base;
              int b= suc;
              int c= suc+nVerticesPorCara;
              int d= base+nVerticesPorCara;


              arrayParcial[0]=new VerticeNormal(a,numcara);
              arrayParcial[1]=new VerticeNormal(b,numcara);
              arrayParcial[2]=new VerticeNormal(c,numcara);
              arrayParcial[3]=new VerticeNormal(d,numcara);


              faces->at(numcara)->  addVerticeNormal(arrayParcial);

           }

        

        //tapa 1
        caras[4]=new Cara(nVerticesPorCara);
        VerticeNormal** arrayCara4= new VerticeNormal*[nVerticesPorCara];
        arrayCara4[0]=new VerticeNormal(0,4);
        arrayCara4[1]=new VerticeNormal(3,4);
        arrayCara4[2]=new VerticeNormal(2,4);
        arrayCara4[3]=new VerticeNormal(1,4);
        caras[4]->addVerticeNormal(arrayCara4);

        //tapa 2
        caras[5]=new Cara(nVerticesPorCara);
        VerticeNormal** arrayCara5= new VerticeNormal*[nVerticesPorCara];
        arrayCara5[0]=new VerticeNormal(4,5);
        arrayCara5[1]=new VerticeNormal(5,5);
        arrayCara5[2]=new VerticeNormal(6,5);
        arrayCara5[3]=new VerticeNormal(7,5);
        caras[5]->addVerticeNormal(arrayCara5);


        for(int i=0; i<this->numeroCaras;i++)
        {
            PV3D* normal=this->CalculoVectorNormalPorNewell(caras[i]);
            normales[i]= normal;
        }
}
