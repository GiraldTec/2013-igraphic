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
	GLdouble propX,propY;

public:
	Elipse(void);
	Elipse(PV2D *c, GLdouble pX, GLdouble pY);
	~Elipse(void);
	
	bool collide(Ball *ball, GLdouble& tin, PV2D*& normalIn){

		PV2D *bVectorTransformed;	// ball->getVector()
		PV2D *bCenterTransformed;	// ball->getCenter()

		// Transformamos la información que lleva la pelota para hacer bien la colisión

		bVectorTransformed = new PV2D(ball->getVector()->getX()/propX,
										ball->getVector()->getY()/propY);

		bCenterTransformed = new PV2D((ball->getCenter()->getX()-this->getCenter()->getX())/propX,
										(ball->getCenter()->getY()-this->getCenter()->getY())/propY);

		GLdouble a = bVectorTransformed->scalarProduct(bVectorTransformed);
		PV2D* cp = bCenterTransformed->substract(new PV2D(0.0,0.0));
		GLdouble b=cp->scalarProduct(bVectorTransformed)*2;
		GLdouble c=(cp->scalarProduct(cp))-pow(1,2);

        GLdouble discriminante=pow(b,2)-4*(a*c);
        delete cp;

        if(discriminante<0)
        {
         return false;
        }

        if(discriminante==0)
        {
              tin=(-b)/(2*a);

			  PV2D* velaux = bVectorTransformed->factor(tin);
			  normalIn = bCenterTransformed->substract(velaux);
              delete velaux;
              return true;

          }

        if(discriminante>0)
        {
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

			  PV2D *aux= new PV2D(0.0,0.0);
			  normalIn = aux->substract(pelaux);

              delete aux;
			  delete paux;
              delete pelaux;
              return true;
        }

		delete bVectorTransformed;
		delete bCenterTransformed;

		// Aplicamos las transformaciones pertinentes a tIn
		// tIn solo se afecta por la escala

		tin = tin * (propY/propX);
		PV2D *aux= new PV2D (normalIn->getX()*propX+this->getCenter()->getX(),
								normalIn->getY()*propY+this->getCenter()->getY());
		normalIn = aux;

		delete aux;

        return false;


	}


	void render(void){
		
		glPushMatrix();
		//Aplicamos las transformaciones parar las elipses
		glTranslatef(getCenter()->getX(),getCenter()->getY(),0);
		glScalef(propX,propY,0);
		renderX();
		glPopMatrix();
	
	}

};