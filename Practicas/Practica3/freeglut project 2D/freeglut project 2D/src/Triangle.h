//Carlos Giraldo
//Raquel Peces
#pragma once

#include "src/Obstacle.h"
#include "src/DrawablePolygon.h"

class Triangle : public Obstacle
{
private:
	std::vector<PV2D*> *normales;
public:
	Triangle(void);
	Triangle(PV2D *c, GLdouble r, GLdouble o);
	~Triangle(void);
	
	bool collide(Ball *ball, GLdouble& tIn, PV2D*& normalIn){
		int sign[3];	GLdouble proj[3];	GLdouble dist[3];
		PV2D *auxVp = ball->getVector()->normalize()->doNormal();
		
		for(int i=0;i<3;i++){
			PV2D *auxPPi = new PV2D(ball->getCenter(),this->getVertex()->at(i));
			
			dist[i] = auxPPi->scalarProduct(auxVp);
			proj[i] = auxPPi->scalarProduct(ball->getVector()->normalize());
			
			if(dist[i]>0.01) sign[i] = 1;
			if(dist[i]<=0.01) sign[i] = 0;
			if(dist[i]<-0.01) sign[i] = -1;

			delete auxPPi;
			auxPPi = NULL;
		}
		delete auxVp;	auxVp= NULL;

		int sum = sign[0]+sign[1]+sign[2];
		if(abs(sum) == 3) return false;

		int nHits = 0;	double hit[3];	PV2D* n[3];
		for(int i=0;i<3;i++){
			int j=(i+1)%3;
			if((sign[i]*sign[j])<0 ){
				GLdouble numerator = (proj[i]*dist[j]) - (proj[j]*dist[i]);
				GLdouble denominator = dist[j] - dist[i];

				hit[nHits] = numerator/denominator;

				PV2D *auxNi = (new PV2D(this->getVertex()->at(j),this->getVertex()->at(i)))->doNormal();
				n[nHits]=auxNi->normalize();
				delete auxNi;	auxNi = NULL;

				nHits++;
			}
		}

		if(nHits<2){
			for(int i=0;i<3;i++){
				if(sign[i]==0){
					hit[nHits] = proj[i];
					n[nHits] = new PV2D(this->getCenter(),this->getVertex()->at(i));
					nHits++;
				}
			}
		}

		tIn = hit[0];
		normalIn = n[0];

		for(int m=1;m<nHits;m++){
			if(hit[m]<tIn){
				tIn = hit[m];
				normalIn = n[m];
			}
		}
		tIn /= ball->getVector()->calculateMod();
		return true;
	};

	void doNormals(void);

	void render(void){
		glPushMatrix();
		glRotatef(45,0,0,1);
		renderX();
		glPopMatrix();
	}
};

