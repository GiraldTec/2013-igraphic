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
	//GLfloat matrix[16];
	//GLfloat inv_matrix[16];
	GLdouble propX,propY;

public:
	Elipse(void);
	Elipse(PV2D *c);
	~Elipse(void);
	PV2D* multMatriz(GLfloat* matrix, PV2D* punt, int tipo);
	PV2D* multMatrizT(GLfloat* matrix, PV2D* punt, int tipo);
	/*bool collide(Ball *ball, GLdouble& tin, PV2D*& normalIn){

		// De alguna forma hay que recoger la matriz que se le aplica a la elipse y aplicarsela al centro y la velocidad de la pelota
		//Aplicar M a la pelota (centro y vector)

		//Sacar el centro transformado
		PV2D* aux_center = multMatriz(inv_matrix,ball->getCenter(),1);
		//Sacar el vector transformado
		PV2D* aux_vector = multMatriz(inv_matrix,ball->getVector(),0);
		
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
			  PV2D* aux_normal = this->getCenter()->substract(pelaux);
			  normalIn=multMatrizT(inv_matrix,aux_normal,0);
			  delete paux;
              delete pelaux;
			  delete aux_normal;
              return true;
        }


         return false;
	}*/

	bool collide(Ball *ball, GLdouble& tin, PV2D*& normalIn){

		PV2D *bVectorTransformed;	// ball->getVector()
		PV2D *bCenterTransformed;	// ball->getCenter()

		// Transformamos la información que lleva la pelota para hacer bien la colisión



		GLdouble a = bVectorTransformed->scalarProduct(bVectorTransformed);
		PV2D* cp = bCenterTransformed->substract(new PV2D());
		GLdouble b=cp->scalarProduct(bVectorTransformed)*2;
		GLdouble c=(cp->scalarProduct(cp))-pow(1,2);

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

			  PV2D* velaux = bVectorTransformed->factor(tin);
			  normalIn = bCenterTransformed->substract(velaux); //TODO ESTO ESTA MAL
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
               tin=min(t1,t2);
              }
              if(t1<0 && t2<0)
              {
                  return false;
              }

              if(t1<0 && t2>0)
              {
               tin=t2;
              }

              if(t1>0 && t2<0)
              {
               tin=t1;
              }

              PV2D* paux = bVectorTransformed->factor(tin);
              PV2D* pelaux = bCenterTransformed->add(paux);

			  normalIn= new PV2D()->substract(pelaux);
              delete paux;
              delete pelaux;
              return true;
        }


		// Aplicamos las transformaciones pertinentes a tIn

         return false;


	}


	void render(void){
		
		glPushMatrix();
		//Aplicamos las transformaciones parar las elipses
		//glLoadMatrixf(matriz);
		//glMultMatrixf(matrix);
		glTranslatef(getCenter()->getX(),getCenter()->getY(),0);
		glScalef(200,100,0);
		renderX();
		glPopMatrix();
		//renderX();
	
	}

};