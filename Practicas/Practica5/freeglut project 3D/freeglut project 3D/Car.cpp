#include "Car.h"


Car::Car(GLdouble x,GLdouble y,GLdouble z)
{
	cout << "entrando a Car del Car" << endl;
	this->aproximacion=40;
    this->x=x;
    this->y=y;
    this->z=z;
    this->radioRueda=0.1*x;
    this->anchoRueda=0.1*x;
        
    build();
	cout << "saliendo de Car del Car" << endl;
}


Car::~Car(void)
{
}

void Car::build()
{
	cout << "entrando a build del Car" << endl;
	//cubo1=new Cube(0.6*x,0.6*y,0.8*z);   
	//cubo1->build();
	//cubo2=new Cube(0.4*x,0.2*y,0.6*z);   
	//cubo2->build();

	wheels = new vector<GLUquadric*>(4);
	covers = new vector<GLUquadric*>(4);

	for (int i=0; i<4; i++){
		this->wheels->at(i) = gluNewQuadric();
		this->covers->at(i) = gluNewQuadric();
	}

	cout << "saliendo de build del Car" << endl;
}

void Car::draw(GLdouble acumCoche)
{
	glMatrixMode(GL_MODELVIEW);
       

	glPushMatrix();
		glColor3f(1,1,1);//blanco
		glTranslated(0,0.5,0);
		glutSolidCube(1);
	glPopMatrix();
	/*	glPushMatrix();
			glTranslated(0.2*x,radioRueda/2,radioRueda);
			//PV3D* color1= new PV3D(1,0,0);
			cubo1->draw(true,false);//parte de abajo
			//delete color1;
		glPopMatrix();

		glPushMatrix();
			//PV3D* color2= new PV3D(1,1,0);
			glTranslated(0.3*x,radioRueda/2+0.6*x,radioRueda+0.1*z);
			cubo2->draw(true,false); //parte de arriba
			//delete color2;
		glPopMatrix();
		*/
	   for (int i=0; i<4; i++){
		   GLdouble posX,posZ;
		   switch (i){
				case 0: 
					posX = -0.5;
					posZ = 0.5;
					break;
				case 1: 
					posX = 0.5;
					posZ = 0.5;
					break;
				case 2: 
					posX = -0.5;
					posZ = -0.5;
					break;
				case 3: 
					posX = 0.5;
					posZ = -0.5;
					break;
		   }

		   //Wheel
			glPushMatrix();
				glColor3f(0,0,0);//negro
				gluQuadricDrawStyle(wheels->at(i), GLU_LINE);
				//gluQuadricNormals(wheels->at(i), GLU_LINE);
				glRotated(90,0,1,0);
				glTranslated(posX,0,posZ);//-radioRueda,0,0.1*x);
				//glRotated(acumCoche,0,0,1);
				gluCylinder(wheels->at(i), radioRueda*2, radioRueda*2, anchoRueda, this->aproximacion,this->aproximacion);
			glPopMatrix();

			//Cover
			glPushMatrix();
				glColor3f(0,0,0);//negro
				gluQuadricDrawStyle(covers->at(i), GLU_LINE);
				//gluQuadricNormals(covers->at(i), GLU_LINE);
				glRotated(90,0,1,0);
				glTranslated(posX,0,posZ);
				gluDisk(covers->at(i),0, radioRueda*2, this->aproximacion,this->aproximacion);
			glPopMatrix();
	   }

	glPopMatrix();
}
