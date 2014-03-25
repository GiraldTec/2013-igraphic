#include "MontanaRusa.h"


//---------------------------------------------------------------------------

MontanaRusa::MontanaRusa(int NP,int NQ,GLfloat tam) : Malla(NP*NQ,NP*NQ,NP*NQ)
{
    this->NP=NP;
    this->NQ=NQ;
    this->tam=tam;
    car= new Car(2*tam*0.8);
    carPos=0;
}
MontanaRusa::~MontanaRusa()
{
    delete car;
}
//--------------------------------------------------------------------------

GLfloat MontanaRusa::fDerivateX(GLfloat t)
{
	return -3*sin(t);
}

GLfloat MontanaRusa::fDerivateY(GLfloat t)
{
        return -3*sin(1.5*t);
}

GLfloat MontanaRusa::fDerivateZ(GLfloat t)
{
        return 3*cos(t);
}
//-----------------------------------------
GLfloat MontanaRusa::sDerivateX(GLfloat t)
{
	return -3*cos(t);
}

GLfloat MontanaRusa::sDerivateY(GLfloat t)
{
        return -4.5*cos(1.5*t);
}
GLfloat MontanaRusa::sDerivateZ(GLfloat t)
{
        return -3*sin(t);
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
        GLfloat x= functionX(t);
		GLfloat y= functionY(t);
        GLfloat z= functionZ(t);
        return new PV3D(x,y,z);
}
PV3D* MontanaRusa::fDerivate(GLfloat t)
{
        GLfloat x= fDerivateX(t);
		GLfloat y= fDerivateY(t);
        GLfloat z= fDerivateZ(t);
        return new PV3D(x,y,z);
}
PV3D* MontanaRusa::sDerivate(GLfloat t)
{
        GLfloat x= sDerivateX(t);
		GLfloat y= sDerivateY(t);
        GLfloat z= sDerivateZ(t);
		return new PV3D(x,y,z);
}

void MontanaRusa::build(){
     
	GLfloat intervaloToma = 2*2*M_PI/NQ;  // Hay que dar dos vueltas porque hay puntos con 2 valores
	
	//construimos un objeto con el lapiz

	Poligon *poli = new Poligon(new PV3D(),NP,tam);  // un polígono del tamaño y con los lados que queremos
    vector<PV3D*>* puntos= poli->getVertex();  
        
    for(int i=0;i<NQ;i++)
    {
            GLfloat toma=intervaloToma*i;
            
            PV3D* fderivate = fDerivate(toma);
			PV3D* sderivate = sDerivate(toma);

			PV3D* Tt=fDerivate(toma); Tt->normalize();
            PV3D* Bt=fderivate->crossProduct(sderivate); Bt->normalize();
            PV3D* Nt=Bt->crossProduct(Tt);
            PV3D* Ct=function(toma);

            for(int j=0;j<NP;j++)
            {
                   
                int numvertice=NP*i+j;
                PV3D* clon=puntos->at(j)->clone();
                PV3D* punto=clon->matrixProduct(Nt,Bt,Tt,Ct);
				vertex->at(numvertice)=punto;
                delete clon;  
            }

            //deletes de los objetos ya no necesarios
            delete sderivate;	delete fderivate;	delete Tt;
			delete Bt;			delete Nt;			delete Ct;

    } //fin del for para cada toma


    //construimos las caras

    for(int i=0;i<NQ;i++)
    {
            //construir las caras
            for(int j=0;j<NP;j++)
            {
                int numFace= NP*(i)+j ;
                faces->at(numFace)= new Cara(4);
                vector<VerticeNormal*>* arrayParcial= new vector<VerticeNormal*>(4);

                int baseVertex=numFace;
                int a= (baseVertex) % (NP*NQ);
                int b= (nextVertex(baseVertex))% (NP*NQ);
                int c=  (nextVertex(baseVertex)+NP)% (NP*NQ);
                int d=  (baseVertex+NP)% (NP*NQ);


                arrayParcial->at(0)=new VerticeNormal(a,numFace);
                arrayParcial->at(1)=new VerticeNormal(b,numFace);
                arrayParcial->at(2)=new VerticeNormal(c,numFace);
                arrayParcial->at(3)=new VerticeNormal(d,numFace);
                    

                faces->at(numFace)->setIndicesVN(arrayParcial); 
            }


    }

    //construir las primeras caras(desde toma 0 a toma NQ


    for(int i=0;i<this->numFaces;i++)
    {
            normals->at(i)= this->doVectorNormalNewell(faces->at(i));
    }



    delete poli;
	
}//fin funcion construye

int MontanaRusa::nextVertex(int val)
{
        int valaux=val+1;
        if(valaux%NP==0)
        {
          return valaux-NP;
        }
        return valaux;
}

void MontanaRusa::draw(bool relleno,bool dibujaNormales)
{
        Malla::draw(relleno,dibujaNormales);

        //dibujo  del coche
        
		PV3D* fderivate = fDerivate(carPos);
		PV3D* sderivate = sDerivate(carPos);

		PV3D* Tt=fDerivate(carPos); Tt->normalize();
        PV3D* Bt=fderivate->crossProduct(sderivate); Bt->normalize();
        PV3D* Nt=Bt->crossProduct(Tt);
        PV3D* Ct=function(carPos);

      /*
        GLfloat m[]={   Nt->getX(),Bt->getX(),Tt->getX(),Ct->getX(),
                        Nt->getY(),Bt->getY(),Tt->getY(),Ct->getY(),
                        Nt->getZ(),Bt->getZ(),Tt->getZ(),Ct->getZ(),
                        0,0,0,1};
      // */

       GLfloat m[] ={   -Nt->getX(),-Nt->getY(),-Nt->getZ(),0,  // He cambiado esta parte
                        -Bt->getX(),-Bt->getY(),-Bt->getZ(),0, 
                        -Tt->getX(),-Tt->getY(),-Tt->getZ(),0,
                        Ct->getX(),Ct->getY(),Ct->getZ(),1};

        glMatrixMode(GL_MODELVIEW);        
        glPushMatrix();
               
            glMultMatrixf(m);
			//glTranslated(Ct->getX(),Ct->getY(),Ct->getZ());  // lo pone en la posición
            drawCar();
              
        glPopMatrix();

		//deletes de los objetos ya no necesarios
            delete sderivate;	delete fderivate;	delete Tt;
			delete Bt;			delete Nt;			delete Ct;
		
}

void MontanaRusa::drawCar()
{
      car->draw(); 
}

void MontanaRusa::carStep(GLfloat step)
{
        carPos +=step;
}

