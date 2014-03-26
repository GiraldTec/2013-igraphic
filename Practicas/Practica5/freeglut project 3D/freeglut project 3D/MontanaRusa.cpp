//Carlos Giraldo
//Raquel Peces
#include "MontanaRusa.h"

//---------------------------------------------------------------------------
MontanaRusa::MontanaRusa(int NP,int NQ,GLfloat tam) : Malla(NP*NQ,NP*NQ,NP*NQ){			// El numero de Vértice y Caras es el mismo 
    this->NP=NP;
    this->NQ=NQ;
    this->tam=tam;
    car= new Car(2*tam*0.8);
    carPos=0;
}
MontanaRusa::~MontanaRusa(){
    delete car;
}
//--------------------------------------------------------------------------
GLfloat MontanaRusa::fDerivateX(GLfloat t){	return -3*sin(t);}
GLfloat MontanaRusa::fDerivateY(GLfloat t){ return -3*sin(1.5*t);}
GLfloat MontanaRusa::fDerivateZ(GLfloat t){ return 3*cos(t);}
//-----------------------------------------
GLfloat MontanaRusa::sDerivateX(GLfloat t){	return -3*cos(t);}
GLfloat MontanaRusa::sDerivateY(GLfloat t){ return -4.5*cos(1.5*t);}
GLfloat MontanaRusa::sDerivateZ(GLfloat t){ return -3*sin(t);}
//-------------------------------------------------------------------------
GLfloat MontanaRusa::functionX(GLfloat t){ return 3*cos(t);}
GLfloat MontanaRusa::functionY(GLfloat t){ return 2*cos(t*1.5);}
GLfloat MontanaRusa::functionZ(GLfloat t){ return 3*sin(t);}
//-------------------------------------------------------------------------
PV3D* MontanaRusa::function(GLfloat t){
        GLfloat x= functionX(t);
		GLfloat y= functionY(t);
        GLfloat z= functionZ(t);
        return new PV3D(x,y,z);
}
PV3D* MontanaRusa::fDerivate(GLfloat t){
        GLfloat x= fDerivateX(t);
		GLfloat y= fDerivateY(t);
        GLfloat z= fDerivateZ(t);
        return new PV3D(x,y,z);
}
PV3D* MontanaRusa::sDerivate(GLfloat t){
        GLfloat x= sDerivateX(t);
		GLfloat y= sDerivateY(t);
        GLfloat z= sDerivateZ(t);
		return new PV3D(x,y,z);
}
//-------------------------------------------------------------------------
void MontanaRusa::build(){
     
	GLfloat intervaloToma = 2*2*M_PI/NQ;  // Hay que dar dos vueltas porque hay puntos con 2 valores
	
	Poligon *poli = new Poligon(new PV3D(),NP,tam);  // un polígono del tamaño y con los lados que queremos
    vector<PV3D*>* puntos= poli->getVertex();  
        
    for(int i=0;i<NQ;i++){  // Esto ocurre en cada "sección" del gusano
            GLfloat toma=intervaloToma*i;				// Este valor hace que a cada vuelta la "matriz" sea única
            
            PV3D* fderivate = fDerivate(toma);			// Se calculan los valores que ayudan al cálculo de los puntos
			PV3D* sderivate = sDerivate(toma);

			PV3D* Tt=fDerivate(toma); Tt->normalize();
            PV3D* Bt=fderivate->crossProduct(sderivate); Bt->normalize();
            PV3D* Nt=Bt->crossProduct(Tt);
            PV3D* Ct=function(toma);

			for(int j=0;j<NP;j++){									// Esto ocurre con cada uno de los vértices del polígono
                int numV=NP*i+j;
                PV3D* clon=puntos->at(j)->clone();					// Un clon del punto del polígono para trabajar
                PV3D* punto=clon->matrixProduct(Nt,Bt,Tt,Ct);
				vertex->at(numV)=punto;								// El punto recibe un identificador y siempre con sentido
                delete clon;  
            }

            //deletes de los objetos ya no necesarios
            delete sderivate;	delete fderivate;	delete Tt;
			delete Bt;			delete Nt;			delete Ct;

    }
    // Se construyen las caras

	for(int numFace=0;numFace<faces->size();numFace++){      //  |>Recorremos todas las caras en orden
        faces->at(numFace)= new Cara(4);
        vector<VerticeNormal*>* auxNormals= new vector<VerticeNormal*>(4);

		int a= (numFace) % (NP*NQ);
        int b= (nextVertex(numFace) )% (NP*NQ);		// Teniendo cuidado de cerrar bien el círculo
        int c= (nextVertex(numFace) +NP)% (NP*NQ);
        int d= (numFace+NP)% (NP*NQ);

        auxNormals->at(0)=new VerticeNormal(a,numFace);
        auxNormals->at(1)=new VerticeNormal(b,numFace);
        auxNormals->at(2)=new VerticeNormal(c,numFace);
        auxNormals->at(3)=new VerticeNormal(d,numFace);
        
        faces->at(numFace)->setIndicesVN(auxNormals); 
     }
	// Se hacen las normales

    for(int i=0;i<this->numFaces;i++){
            normals->at(i)= this->doVectorNormalNewell(faces->at(i));
    }
	
    delete poli;
	
}
//-------------------------------------------------------------------------
int MontanaRusa::nextVertex(int v){  
        int vAux=v+1;
        if(vAux%NP==0){	
			return vAux-NP;
		}
        return vAux;
}
//-------------------------------------------------------------------------
void MontanaRusa::draw(bool relleno,bool dibujaNormales){

	Malla::draw(relleno,dibujaNormales);  // Dibuja la malla
        
	PV3D* fderivate = fDerivate(carPos);
	PV3D* sderivate = sDerivate(carPos);

	PV3D* Tt=fDerivate(carPos); Tt->normalize();					// Tt = C'
	PV3D* Bt=fderivate->crossProduct(sderivate); Bt->normalize();	// Bt = C'.C''
	PV3D* Nt=Bt->crossProduct(Tt);									// Nt = Bt.Tt
	PV3D* Ct=function(carPos);										// Ct = C

	GLfloat m[] ={  Nt->getX(),	Nt->getY(),	Nt->getZ(),	0,		// Se niega Bt porque al ser 
					-Bt->getX(),-Bt->getY(),-Bt->getZ(),0,		// un producto escalar es perpendicular 
					Tt->getX(),	Tt->getY(),	Tt->getZ(),	0,		// al plano definido por C'.C'' 
					Ct->getX(),	Ct->getY(),	Ct->getZ(),	1};		// pero en sentido contrario

	glMatrixMode(GL_MODELVIEW);        
	glPushMatrix();
               
		glMultMatrixf(m);
		//glTranslated(Ct->getX(),Ct->getY(),Ct->getZ());  // lo pone en la posición pero no con la torsión necesaria
		car->draw(); 
              
	glPopMatrix();

	//deletes de los objetos ya no necesarios
	delete sderivate;	delete fderivate;	delete Tt;
	delete Bt;			delete Nt;			delete Ct;
		
}
//-------------------------------------------------------------------------
void MontanaRusa::carStep(GLfloat step){
        carPos +=step;
		car->stepWheel();
}

