//Carlos Giraldo
//Raquel Peces
#include "TrianguloBolas.h"


TrianguloBolas::TrianguloBolas(void){

	GLdouble pX,pZ;
	pX=pZ=0.0;
	int nBola=1;

	for(int i=0;i<=4;i++){
		
		for(int j=0;j<=4-i;j++){
			Bola *b;
			switch(nBola){
			case 1:	
				b= new Bola(1.0,0.84,0.0);
				break;
			case 2:
				b= new Bola(0.11,0.56,1.0);
				break;
			case 3:
				b= new Bola(1.0,0.0,0.0);
				break;
			case 4:
				b= new Bola(0.62,0.12,0.94);
				break;
			case 5:
				b= new Bola(1.0,0.64,0.0);
				break;
			case 6:
				b= new Bola(0.19,0.8,0.19);
				break;
			case 7:
				b= new Bola(0.64,0.16,0.16);
				break;
			case 8:
				b= new Bola(0.0,0.0,0.0);
				break;
			case 9:
				b= new Bola(0.85,0.64,0.12);
				break;
			case 10:
				b= new Bola(0.0,0.80,0.81);
				break;
			case 11:
				b= new Bola(0.98,0.5,0.44);
				break;
			case 12:
				b= new Bola(0.55,0.21,0.55);
				break;
			case 13:
				b= new Bola(1.0,0.27,0.0);
				break;
			case 14:
				b= new Bola(0.56,0.93,0.56);
				break;
			case 15:
				b= new Bola(0.82,0.41,0.11);
				break;
			}
			b->obTraslate(pX-j*10*sin(30*M_PI/180),0.0,-(pZ-j*10*cos(30*M_PI/180)));
			addComponente(b);
			nBola++;
		}
		pX=pX+10*sin(30*M_PI/180);
		pZ=pZ-10*cos(30*M_PI/180);
	}
	obTraslate(0.0,0.0,-70.0);
	obRotate(60.0,1);
	obTraslate(0.0,0.0,-10/sin(30*M_PI/180)*cos(30*M_PI/180));
	obTraslate(5.0,0.0,-5/sin(30*M_PI/180)*cos(30*M_PI/180));
	
}


TrianguloBolas::~TrianguloBolas(void)
{
}
