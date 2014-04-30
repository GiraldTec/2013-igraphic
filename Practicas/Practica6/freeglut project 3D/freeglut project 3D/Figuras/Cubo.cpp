//Carlos Giraldo
//Raquel Peces
#include "Cubo.h"

Cubo::Cubo(int d):
		Malla(2*(d+1)*(d+1)+(d-1)*(2*(d+d)),
				(d*d+d*d+d*d)*2,
					(d*d+d*d+d*d)*2){ 
	xDiv=d; 
	yDiv=d;
	zDiv=d;  // (Tapas Inf&Sup)+(Anillos interiores)

	build();
}

Cubo::Cubo(int x,int y,int z):
		Malla(2*(x+1)*(z+1)+(y-1)*(2*(x+z)),
				(x*y+x*z+y*z)*2,
					(x*y+x*z+y*z)*2){  
	xDiv=x; 
	yDiv=y;
	zDiv=z;  // (Tapas Inf&Sup)+(Anillos interiores)

	build();
}


Cubo::~Cubo(void){ // TODO delete de los vectores
}


void Cubo::build(void){
	red=green=blue=0.5;

	GLdouble wideX,wideY,wideZ;
	wideX = 1.0/xDiv;	wideY = 1.0/yDiv;	wideZ = 1.0/zDiv;
	int numCara=0; int numPunto=0;
	// Empezamos con los puntos de la cara que se encuentra con Z negativa

	// Se monta una estructura que ayuda a sostener los puntos de la ultima cara
	//vector<PV3D*>* auxPuntosA= new vector<PV3D*>((xDiv+1)*(yDiv+1));
	// Y una estructura para mantener un regstro de los indices de los puntos
	vector<int>* auxIndicesA= new vector<int>((xDiv+1)*(yDiv+1));

	for(unsigned i=0;i<=yDiv;i++){
		for(unsigned j=0;j<=xDiv;j++){
			unsigned acum=i*(xDiv+1)+j;
			puntos->at(acum)=new PV3D(0.5-j*wideX,0.5-i*wideY,-0.5);
			if(i==0 || j==0 || i == yDiv || j == xDiv){
				//auxPuntosA->at(acum)=puntos->at(acum);  // la estructura auxiliar solo almacena los puntos del borde
				auxIndicesA->at(acum)=acum;
			}
			if(i>0 && j>0){ // Podemos formar caras
				caras->at(numCara)= new Cara(4);
				vector<VerticeNormal*>* auxNormals= new vector<VerticeNormal*>(4);
				int a=acum-xDiv-2;
				int b=acum-xDiv-1;
				int c=acum-1;
				int d=acum;

				auxNormals->at(0)=new VerticeNormal(a,numCara);
				auxNormals->at(1)=new VerticeNormal(c,numCara);
				auxNormals->at(2)=new VerticeNormal(d,numCara);
				auxNormals->at(3)=new VerticeNormal(b,numCara);
        
				caras->at(numCara)->setIndicesVN(auxNormals); 
				numCara = numCara+1;
			}
		}
	}
	numPunto = (xDiv+1)*(yDiv+1);

	int contPuntos = numPunto;

	for(int k=1;k<=zDiv;k++){  // los anillos interiores
		//vector<PV3D*>* auxPuntosB= new vector<PV3D*>((xDiv+1)*(yDiv+1));
		vector<int>* auxIndicesB= new vector<int>((xDiv+1)*(yDiv+1));
		
		// Cada uno de los anillos, incluido el borde de la utima cara
		for(unsigned i=0;i<=yDiv;i++){  // Construimos los puntos que forman el anillo
			for(unsigned j=0;j<=xDiv;j++){
				if(i==0 || j==0 || i == yDiv || j == xDiv){ // solo construiremos el borde
					unsigned acum=i*(xDiv+1)+j;
					puntos->at(numPunto)=new PV3D(0.5-j*wideX,0.5-i*wideY,-0.5+k*wideZ);
					//auxPuntosB->at(acum)=puntos->at(numPunto);
					auxIndicesB->at(acum)=numPunto;

					if(i!=0 || j!=0){ // este punto no construye cara
						int a,b,c,d;
						vector<VerticeNormal*>* auxNormals;
						if(i==0){//Tapa superior		
							caras->at(numCara)= new Cara(4);
							auxNormals= new vector<VerticeNormal*>(4);
							a=c=acum;
							b=d=acum - 1;

							auxNormals->at(0)=new VerticeNormal(auxIndicesA->at(a),numCara);
							auxNormals->at(1)=new VerticeNormal(auxIndicesB->at(c),numCara);
							auxNormals->at(2)=new VerticeNormal(auxIndicesB->at(d),numCara);
							auxNormals->at(3)=new VerticeNormal(auxIndicesA->at(b),numCara);

							caras->at(numCara)->setIndicesVN(auxNormals); 

							numCara = numCara+1;
						}

						if(j==0){// Tapa frontal
							caras->at(numCara)= new Cara(4);
							auxNormals= new vector<VerticeNormal*>(4);
							c=d=acum;
							a=b=acum-xDiv-1;
							

							auxNormals->at(0)=new VerticeNormal(auxIndicesB->at(a),numCara);
							auxNormals->at(1)=new VerticeNormal(auxIndicesB->at(c),numCara);
							auxNormals->at(2)=new VerticeNormal(auxIndicesA->at(d),numCara);
							auxNormals->at(3)=new VerticeNormal(auxIndicesA->at(b),numCara);

							caras->at(numCara)->setIndicesVN(auxNormals); 

							numCara = numCara+1;
						}

						if(i==yDiv && j!=0){  // tapa inferior
							caras->at(numCara)= new Cara(4);
							auxNormals= new vector<VerticeNormal*>(4);
							a=c=acum - 1;
							b=d=acum;

							auxNormals->at(0)=new VerticeNormal(auxIndicesA->at(a),numCara);
							auxNormals->at(1)=new VerticeNormal(auxIndicesB->at(c),numCara);
							auxNormals->at(2)=new VerticeNormal(auxIndicesB->at(d),numCara);
							auxNormals->at(3)=new VerticeNormal(auxIndicesA->at(b),numCara);

							caras->at(numCara)->setIndicesVN(auxNormals); 

							numCara = numCara+1;
						}

						if(j==xDiv && i!=0){ //Tapa del fondo
							caras->at(numCara)= new Cara(4);
							auxNormals= new vector<VerticeNormal*>(4);
							a=b=acum-xDiv-1;
							c=d=acum;

							auxNormals->at(0)=new VerticeNormal(auxIndicesA->at(a),numCara);
							auxNormals->at(1)=new VerticeNormal(auxIndicesA->at(c),numCara);
							auxNormals->at(2)=new VerticeNormal(auxIndicesB->at(d),numCara);
							auxNormals->at(3)=new VerticeNormal(auxIndicesB->at(b),numCara);

							caras->at(numCara)->setIndicesVN(auxNormals); 

							numCara = numCara+1;
						}
					}

					numPunto = numPunto +1;
				}
			}
		}
		
		contPuntos = contPuntos + 2*(xDiv+yDiv);
		auxIndicesA = auxIndicesB;
		//auxPuntosA = auxPuntosB;
	}


	// Acabamos con los puntos de la cara que se encuentra con Z positiva
	for(unsigned i=1;i<=yDiv;i++){
		for(unsigned j=1;j<=xDiv;j++){
			unsigned acum=i*(xDiv+1)+j;
			if(i!=yDiv && j!= xDiv){  // Creamos punto
				puntos->at(numPunto) = new PV3D(0.5-j*wideX,0.5-i*wideY,0.5);
				auxIndicesA->at(acum) = numPunto;
			}
			// Creamos cara
			caras->at(numCara)= new Cara(4);

			int a,b,c,d;
			vector<VerticeNormal*>* auxNormals= new vector<VerticeNormal*>(4);
			a = acum - xDiv - 1;
			b = acum - xDiv - 2;
			c = acum;
			d = acum -1;

			auxNormals->at(0)=new VerticeNormal(auxIndicesA->at(a),numCara);
			auxNormals->at(1)=new VerticeNormal(auxIndicesA->at(c),numCara);
			auxNormals->at(2)=new VerticeNormal(auxIndicesA->at(d),numCara);
			auxNormals->at(3)=new VerticeNormal(auxIndicesA->at(b),numCara);

			caras->at(numCara)->setIndicesVN(auxNormals); 

			numCara = numCara+1;

		}
	}

	for(int i=0;i<this->nCaras;i++){
            normales->at(i)= this->doVectorNormalNewell(caras->at(i));
    }

}
