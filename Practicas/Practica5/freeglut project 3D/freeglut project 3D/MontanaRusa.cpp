#include "MontanaRusa.h"


//---------------------------------------------------------------------------

MontanaRusa::MontanaRusa(GLfloat R,GLfloat r,GLfloat d,int NP,int NQ,GLfloat tam) : Malla(NP*NQ,NP*NQ,NP*NQ)
{
    this->R=R;
    this->r=r;
    this->d=d;
    this->NP=NP;
    this->NQ=NQ;
    this->tam=tam;
    this->nVueltas=calculaVueltas();
    //coche=new Coche(tam*0.9,tam*0.9,tam*0.9);
    acumCoche=0;
}
MontanaRusa::~MontanaRusa()
{
    //delete coche;
}
//--------------------------------------------------------------------------

GLfloat MontanaRusa::primeraDerivadaX(GLfloat val)
{
        GLfloat A=R-r;
        GLfloat B=(R-r)/r;

        GLfloat val1=-A*sin(val);
        GLfloat val2=-d*B*sin(B*val);
        return val1+val2;
}

GLfloat MontanaRusa::segundaDerivadaX(GLfloat val)
{
        GLfloat A=R-r;
        GLfloat B=(R-r)/r;
        
        GLfloat val1=-A*cos(val);
        GLfloat val2=-d*B*B*cos(B*val);
        return val1+val2;
}

GLfloat MontanaRusa::primeraDerivadaZ(GLfloat val)
{
        GLfloat A=R-r;
        GLfloat B=(R-r)/r;

        GLfloat val1=A*cos(val);
        GLfloat val2=-d*B*cos(B*val);
        return val1+val2;
}

GLfloat MontanaRusa::segundaDerivadaZ(GLfloat val)
{
        GLfloat A=R-r;
        GLfloat B=(R-r)/r;
        
        GLfloat val1=-A*sin(val);
        GLfloat val2=d*B*B*sin(B*val);
        return val1+val2;
}

PV3D* MontanaRusa::funcion(GLfloat val)
{
        GLfloat x= funcionX(degToRad(val));
		GLfloat y= funcionY(degToRad(val));
        GLfloat z=funcionZ(degToRad(val));
        return new PV3D(x,y,z);
}
PV3D* MontanaRusa::primeraDerivada(GLfloat val)
{
        GLfloat x= primeraDerivadaX(degToRad(val));
        GLfloat z=primeraDerivadaZ(degToRad(val));
        return new PV3D(x,0,z);
}
PV3D* MontanaRusa::segundaDerivada(GLfloat val)
{
        GLfloat x= segundaDerivadaX(degToRad(val));
        GLfloat z=segundaDerivadaZ(degToRad(val));
        return new PV3D(x,0,z);
}

void MontanaRusa::construye()
{
     GLfloat intervaloToma =(GLfloat)(360.0*this->nVueltas/NQ);

        //construimos un objeto con el lapiz
    
        PV3D* centro= new PV3D(0,0,0);
        Polygon* p= new Polygon(centro,tam,NP);
        PV3D** puntos=p->getVertices();
        
        for(int i=0;i<NQ;i++)
        {
                GLfloat toma=intervaloToma*i;
                PV3D* Tt=primeraDerivada(toma); Tt->normalize();
                PV3D* segundaderivada=segundaDerivada(toma);
                PV3D* primeraderivada=primeraDerivada(toma);
                PV3D* Bt=primeraderivada->productoVectorial(segundaderivada); Bt->normalize();
                PV3D* Nt=Bt->productoVectorial(Tt);
                PV3D* Ct=funcion(toma);
                        Ct->setPv(1);                    


                for(int j=0;j<NP;j++)
                {
                   
                   int numvertice=NP*i+j;
                   PV3D* clon=puntos[j]->clone();
                   PV3D* punto=clon->multiplicaMatriz(Nt,Bt,Tt,Ct);
				   vertex->at(numvertice)=punto;
                   delete clon;  
                }

                //deletes de los objetos ya no necesarios
               delete Tt;
               delete Bt;
               delete segundaderivada;
               delete primeraderivada;
               delete Nt;
               delete Ct;

        } //fin del for para cada toma


        //construimos las caras

        for(int i=0;i<NQ;i++)
        {
             //construir las caras
               for(int j=0;j<NP;j++)
               {
                    int numcara= NP*(i)+j ;
                    faces->at(numcara)= new Cara(4);
                    VerticeNormal** arrayParcial= new VerticeNormal*[4];

                    int verticeBase=numcara;
                    int a= (verticeBase) % (NP*NQ);
                    int b= (sucesor(verticeBase))% (NP*NQ);
                    int c=  (sucesor(verticeBase)+NP)% (NP*NQ);
                    int d=  (verticeBase+NP)% (NP*NQ);


                    arrayParcial[0]=new VerticeNormal(a,numcara);
                    arrayParcial[1]=new VerticeNormal(b,numcara);
                    arrayParcial[2]=new VerticeNormal(c,numcara);
                    arrayParcial[3]=new VerticeNormal(d,numcara);
                    

                    faces->at(numcara)->addVerticeNormal(arrayParcial);
               }


        }

        //construir las primeras caras(desde toma 0 a toma NQ


        for(int i=0;i<this->numFaces;i++)
        {
                normals->at(i)= this->CalculoVectorNormalPorNewell(caras[i]);
        }



        delete p;

}//fin funcion construye

int MontanaRusa::sucesor(int val)
{
        int valaux=val+1;
        if(valaux%NP==0)
        {
          return valaux-NP;
        }
        return valaux;
}

GLfloat MontanaRusa::degToRad(GLfloat deg)
{
    GLfloat num=deg*2*M_PI;
    GLfloat den=360;

    return num/den;
}


GLfloat MontanaRusa::calculaVueltas()
{
     /*
     GLfloat valor=(R-r)/r;
     GLfloat porcentajeVuelta=valor*360;
     while(porcentajeVuelta<0)
     {
      porcentajeVuelta=porcentajeVuelta+360;
     }

     while(porcentajeVuelta>360)
     {
     porcentajeVuelta=porcentajeVuelta-360;
     }

     GLfloat devolver=360.0/porcentajeVuelta;
     return ceil(devolver);
     */
     return (r*6)/mcd(R*6,r*6);

}

void MontanaRusa::dibuja(bool relleno,bool dibujaNormales)
{
        Malla::draw(relleno,dibujaNormales);

        //dibujo  del coche
        PV3D* Tt=primeraDerivada(acumCoche); Tt->normalize();
        PV3D* segundaderivada=segundaDerivada(acumCoche);
        PV3D* primeraderivada=primeraDerivada(acumCoche);
        PV3D* Bt=primeraderivada->productoVectorial(segundaderivada); Bt->normalize();
        PV3D* Nt=Bt->productoVectorial(Tt);
        PV3D* Ct=funcion(acumCoche);
                Ct->setPv(1);
      /*
        GLfloat m[]={   Nt->getX(),Bt->getX(),Tt->getX(),Ct->getX(),
                        Nt->getY(),Bt->getY(),Tt->getY(),Ct->getY(),
                        Nt->getZ(),Bt->getZ(),Tt->getZ(),Ct->getZ(),
                        0,0,0,1};
       */

       GLfloat m[] ={   Nt->getX(),Nt->getY(),Nt->getZ(),Nt->getPv(),
                        Bt->getX(),1,Bt->getZ(),Bt->getPv(),//el 1 es para que salga hacia arriba
                        Tt->getX(),Tt->getY(),Tt->getZ(),Tt->getPv(),
                        Ct->getX(),Ct->getY(),Ct->getZ(),Ct->getPv()};

        glMatrixMode(GL_MODELVIEW);        
        glPushMatrix();
               
                glMultMatrixf(m);
                dibujaCoche();
              
        glPopMatrix();

        delete Tt;
        delete Bt;
        delete segundaderivada;
        delete primeraderivada;
        delete Nt;
        delete Ct;

}

void MontanaRusa::dibujaCoche()
{
      //coche->dibuja(acumCoche); 
}

void MontanaRusa::addAcum(GLfloat cantidad)
{
        acumCoche=acumCoche+cantidad;

}

int MontanaRusa::mcd(int x, int y)
{
      if(y==0)
        return x;
    else
        return mcd(y, x%y);

}
GLdouble MontanaRusa::functionX(GLdouble t)
{
	return 3*cos(t);
}

GLdouble MontanaRusa::functionY(GLdouble t)
{
	return 2*cos(t*1.5);
}

GLdouble MontanaRusa::functionZ(GLdouble t)
{
	return 3*sin(t);
}