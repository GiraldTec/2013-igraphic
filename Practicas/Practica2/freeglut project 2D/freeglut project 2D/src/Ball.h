#pragma once
#include "DrawablePolygon.h"
class Ball : public DrawablePolygon
{
private:
	PV2D* vector;
	
public:
	Ball(void);
	~Ball(void);
	Ball(PV2D *c, GLdouble r);

	void forward(GLdouble t);
	void bounce(PV2D* n);
	void render(void){ 
		cout << "hago un render de mi pelotita" << endl;

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
	}
	void initBall();
};

