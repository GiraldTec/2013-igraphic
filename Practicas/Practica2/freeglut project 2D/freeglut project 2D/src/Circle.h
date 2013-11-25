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
		GLdouble A = ball->getVector()->scalarProduct(ball->getVector());
		PV2D* aux_v = ball->getCenter()->substract(getCenter());
		GLdouble B = (aux_v->scalarProduct(ball->getVector())*2);
		GLdouble C = (aux_v->scalarProduct(aux_v))-(pow(this->getRadius(),2));
		GLdouble dis = (pow(B,2)) - (4*A*C);
		delete aux_v;

		if (dis<0){
			return false;
		}
		if (dis == 0){
			//Hay una intersección
			tin = (-B)/(2*A);
			PV2D* aux_v=ball->getVector()->factor(tin);
			normalIn=ball->getCenter()->substract(aux_v);
            delete aux_v;
            return true;
		}
		if (dis>0){
			GLdouble t1 = ((-B)-sqrt(dis))/(2*A);
			GLdouble t2 = ((-B)+sqrt(dis))/(2*A);

			if(t1>0 && t2>0)
				{ tin=min(t1,t2); }
			if(t1>0 && t2<0)
				{ tin=t1; }
            if(t1<0 && t2>0)
				{ tin=t2; }
			if(t1<0 && t2<0)
				{ return false; }

			PV2D* aux_v=ball->getVector()->factor(tin);
            PV2D* aux_b=ball->getCenter()->add(aux_v);

			normalIn=ball->getCenter()->substract(aux_b);
			delete aux_v;
            delete aux_b;
            return true;
		}
	};

};

