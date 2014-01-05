//Carlos Giraldo
//Raquel Peces
#pragma once
#include "DrawablePolygon.h"
#include "Obstacle.h"

#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>

class Elipse :	public Obstacle
{
private:


public:
	Elipse(void);
	Elipse(PV2D *c);
	~Elipse(void);
	PV2D* multMatriz(GLfloat* matriz, PV2D* punt);
	bool collide(Ball *ball, GLdouble& tin, PV2D*& normalIn){

		// De alguna forma hay que recoger la matriz que se le aplica a la elipse y aplicarsela al centro y la velocidad de la pelota
		//Aplicar M a la pelota (centro y vector)

		GLfloat matrizActual[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, matrizActual);
		//Sacar el centro transformado
		PV2D* aux_center = multMatriz(matrizActual,ball->getCenter());
		//matrizactual*centro (x,y,0,0)
		//Sacar el vector transformado
		//matrizactual*vector(x,y,0,1)
		PV2D* aux_vector = multMatriz(matrizActual,ball->getVector());
		
		GLdouble a=aux_vector->scalarProduct(aux_vector);
		//GLdouble a=ball->getVector()->scalarProduct(ball->getVector());
		PV2D* cp=aux_center->substract(this->getCenter());
		//PV2D* cp=ball->getCenter()->substract(this->getCenter());
		GLdouble b=cp->scalarProduct(aux_vector)*2;
		//GLdouble b=cp->scalarProduct(ball->getVector())*2;
		GLdouble c=(cp->scalarProduct(cp))-pow(this->getRadius(),2);

        GLdouble discriminante=pow(b,2)-4*(a*c);
        delete cp;

		cout <<"discriminante="<<discriminante<<endl;

        if(discriminante<0)
        {
			cout <<"discriminante<0"<<endl;
         return false;
        }

        if(discriminante==0)
        {
			  cout <<"discriminante=0"<<endl;
              tin=(-b)/(2*a);

			  PV2D* velaux=ball->getVector()->factor(tin);
			  normalIn=ball->getCenter()->substract(velaux); //TODO ESTO ESTA MAL
              delete velaux;
              return true;

          }

        if(discriminante>0)
        {
			  cout <<"discriminante>0"<<endl;
              GLdouble t1=((-b)-sqrt(discriminante))/(2*a);
              GLdouble t2=((-b)+sqrt(discriminante))/(2*a);

              if(t1>0 && t2>0)
              {
			   cout <<"t1>0 && t2>0"<<endl;
               tin=min(t1,t2);
			   cout <<tin<<endl;
              }
              if(t1<0 && t2<0)
              {
				  cout <<"t1<0 && t2<0"<<endl;
                  return false;
              }

              if(t1<0 && t2>0)
              {
				  cout <<"t2>0"<<endl;
               tin=t2;
			   cout <<tin<<endl;
              }

              if(t1>0 && t2<0)
              {
				  cout <<"t1>0"<<endl;
               tin=t1;
			   cout <<tin<<endl;
              }

              PV2D* paux=ball->getVector()->factor(tin);
              PV2D* pelaux=ball->getCenter()->add(paux);

			  normalIn=this->getCenter()->substract(pelaux);
              delete paux;
              delete pelaux;
              return true;
        }


         return false;
	}

	void render(void){
		
		glPushMatrix();
		//Aplicamos las transformaciones parar las elipses
		//glRotatef(45,0,0,1);
		//glScalef(1,1,0); lo deja igual
		glScalef(1,0.2,0);
		renderX();
	
		glPopMatrix();
		renderX();
	
	}

};