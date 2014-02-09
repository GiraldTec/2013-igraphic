//Carlos Giraldo
//Raquel Peces
#pragma once
#include "drawablepolygon.h"
#include "Obstacle.h"
class Circle :	public Obstacle
{
private:


public:
	Circle(void);
	Circle(PV2D *c,GLdouble r);
	~Circle(void);
	bool collide(Ball *ball, GLdouble& tin, PV2D*& normalIn){
		GLdouble a=ball->getVector()->scalarProduct(ball->getVector());
		PV2D* cp=ball->getCenter()->substract(this->getCenter());
		GLdouble b=cp->scalarProduct(ball->getVector())*2;
		GLdouble c=(cp->scalarProduct(cp))-pow(this->getRadius(),2);

        GLdouble discriminante=pow(b,2)-4*(a*c);
        delete cp;

	        if(discriminante<0)
        {
	     return false;
        }

        if(discriminante==0)
        {
	          tin=(-b)/(2*a);

			  PV2D* velaux=ball->getVector()->factor(tin);
			  normalIn=ball->getCenter()->substract(velaux); //TODO ESTO ESTA MAL
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
		renderX();	
	}

};

