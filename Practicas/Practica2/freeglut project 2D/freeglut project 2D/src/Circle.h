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
		bool retValue = false;
		retValue = this->getCenter()->distance(ball->getCenter()) < ball->getRadius()+this->getRadius();
		if(retValue){
		// TODO calcular la normal
		}
		return retValue;


		
		/*
		 GLdouble a=vel->dot(vel);
        PV2D* cp=pelota->resta(centro);
        GLdouble b=cp->dot(vel)*2;
        GLdouble c=(cp->dot(cp))-pow(radio,2);

        GLdouble discriminante=  pow(b,2)-4*(a*c);
        delete cp;

        if(discriminante<0)
        {
         return false;
        }

        if(discriminante==0)
        {
              tIn=(-b)/(2*a);

              PV2D* velaux=vel->factor(tIn);
              normalIn=centro->resta(velaux); //TODO ESTO ESTA MAL
              delete velaux;
              return true;

        }

        if(discriminante>0)
        {
              GLdouble t1=((-b)-sqrt(discriminante))/(2*a);
              GLdouble t2=((-b)+sqrt(discriminante))/(2*a);

              if(t1>0 && t2>0)
              {
               tIn=min(t1,t2);
              }
              if(t1<0 && t2<0)
              {
                  return false;
              }

              if(t1<0 && t2>0)
              {
               tIn=t2;
              }

              if(t1>0 && t2<0)
              {
               tIn=t1;
              }

              PV2D* paux=vel->factor(tIn);
              PV2D* pelaux=pelota->suma(paux);

              normalIn=centro->resta(pelaux);
              delete paux;
              delete pelaux;
              return true;
        }


         return false;
		*/
	};

};

