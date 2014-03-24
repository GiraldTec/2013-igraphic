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
    car=NULL;//new Car(tam*0.9,tam*0.9,tam*0.9);
    acumCoche=0;
}
MontanaRusa::~MontanaRusa()
{
    delete car;
}
//--------------------------------------------------------------------------

GLfloat MontanaRusa::fDerivateX(GLfloat t)
{
	return -3*sin(degToRad(t));
}

GLfloat MontanaRusa::sDerivateX(GLfloat t)
{
	return -3*cos(degToRad(t));
}

GLfloat MontanaRusa::fDerivateY(GLfloat t)
{
        return -3*sin(1.5*degToRad(t));
}

GLfloat MontanaRusa::sDerivateY(GLfloat t)
{
        return -4.5*cos(1.5*degToRad(t));
}

GLfloat MontanaRusa::fDerivateZ(GLfloat t)
{
        return 3*cos(degToRad(t));
}

GLfloat MontanaRusa::sDerivateZ(GLfloat t)
{
        return -3*sin(degToRad(t));
}

//-------------------------------------------------------------------------
GLfloat MontanaRusa::functionX(GLfloat t)
{
	return 3*cos(t);
}

GLfloat MontanaRusa::functionY(GLfloat t)
{
	return 2*cos(t*1.5);
}

GLfloat MontanaRusa::functionZ(GLfloat t)
{
	return 3*sin(t);
}

//-------------------------------------------------------------------------

PV3D* MontanaRusa::function(GLfloat t)
{
        GLfloat x= functionX(degToRad(t));
		GLfloat y= functionY(degToRad(t));
        GLfloat z= functionZ(degToRad(t));
        return new PV3D(x,y,z);
}
PV3D* MontanaRusa::fDerivate(GLfloat val)
{
        GLfloat x= fDerivateX(degToRad(val));
		GLfloat y= fDerivateY(degToRad(val));
        GLfloat z= fDerivateZ(degToRad(val));
        return new PV3D(x,y,z);
}
PV3D* MontanaRusa::sDerivate(GLfloat val)
{
        GLfloat x= sDerivateX(degToRad(val));
		GLfloat y= sDerivateY(degToRad(val));
        GLfloat z= sDerivateZ(degToRad(val));
		return new PV3D(x,y,z);
}

void MontanaRusa::build(){
     
	GLfloat intervaloToma =(GLfloat)(360.0*this->nVueltas/NQ);
	
	//construimos un objeto con el lapiz

    PV3D* centro = new PV3D();
	Poligon *poli = new Poligon(centro,tam,NP);
    vector<PV3D*>* puntos= poli->getVertex();  
        
    for(int i=0;i<NQ;i++)
    {
            GLfloat toma=intervaloToma*i;
            PV3D* Tt=fDerivate(toma); Tt->normalize();
            PV3D* segundaderivada=sDerivate(toma);
            PV3D* primeraderivada=fDerivate(toma);
            PV3D* Bt=primeraderivada->crossProduct(segundaderivada); Bt->normalize();
            PV3D* Nt=Bt->crossProduct(Tt);
            PV3D* Ct=function(toma);
                    Ct->setPv(1);                    


            for(int j=0;j<NP;j++)
            {
                   
                int numvertice=NP*i+j;
                PV3D* clon=puntos->at(j)->clone();
                PV3D* punto=clon->matrixProduct(Nt,Bt,Tt,Ct);
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
                vector<VerticeNormal*>* arrayParcial= new vector<VerticeNormal*>(4);

                int verticeBase=numcara;
                int a= (verticeBase) % (NP*NQ);
                int b= (sucesor(verticeBase))% (NP*NQ);
                int c=  (sucesor(verticeBase)+NP)% (NP*NQ);
                int d=  (verticeBase+NP)% (NP*NQ);


                arrayParcial->at(0)=new VerticeNormal(a,numcara);
                arrayParcial->at(1)=new VerticeNormal(b,numcara);
                arrayParcial->at(2)=new VerticeNormal(c,numcara);
                arrayParcial->at(3)=new VerticeNormal(d,numcara);
                    

                faces->at(numcara)->setIndicesVN(arrayParcial); 
            }


    }

    //construir las primeras caras(desde toma 0 a toma NQ


    for(int i=0;i<this->numFaces;i++)
    {
            normals->at(i)= this->doVectorNormalNewell(faces->at(i));
    }



    delete poli;
	
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
        PV3D* Tt = fDerivate(acumCoche); Tt->normalize();
        PV3D* segundaderivada = sDerivate(acumCoche);
        PV3D* primeraderivada = fDerivate(acumCoche);
        PV3D* Bt=primeraderivada->crossProduct(segundaderivada); Bt->normalize();
        PV3D* Nt=Bt->crossProduct(Tt);
        PV3D* Ct=function(acumCoche);
                Ct->setPv(1);
      /*
        GLfloat m[]={   Nt->getX(),Bt->getX(),Tt->getX(),Ct->getX(),
                        Nt->getY(),Bt->getY(),Tt->getY(),Ct->getY(),
                        Nt->getZ(),Bt->getZ(),Tt->getZ(),Ct->getZ(),
                        0,0,0,1};
      // */

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
     // car->draw(acumCoche); 
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
