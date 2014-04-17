//Carlos Giraldo
//Raquel Peces
#include "Car.h"

Car::Car(GLdouble s)
{
	cout << "entrando a Car del Car" << endl;
	nWheelFaces = 20;
	
	carSize = s;
	chassisSize = 0.6*s; 
	wheelRatius = 0.2*s;
	wheelWith = 0.2*s;
	wheelPosition = 0;
	cout << "saliendo de Car del Car" << endl;
}


Car::~Car(void)
{
}

void Car::draw()
{
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glColor3f(1,1,1);//blanco
		glutSolidCube(chassisSize);
	glPopMatrix();

	for (int i=0; i<4; i++){
		GLdouble posX,posZ, rim;
		switch (i){
			case 0: 
				posX = -0.3 * carSize;
				posZ =  0.3 * carSize;
				rim = posZ + 0.1 * wheelWith;
				break;
			case 1: 
				posX = 0.3 * carSize;
				posZ = 0.3 * carSize;
				rim = posZ + 0.1 * wheelWith;
				break;
			case 2: 
				posX = -0.3 * carSize;
				posZ = -0.3 * carSize - wheelWith;
				rim = posZ - 0.1 * wheelWith;
				break;
			case 3: 
				posX =  0.3 * carSize;
				posZ = -0.3 * carSize - wheelWith;
				rim = posZ - 0.1 * wheelWith;
				break;
		}

		//Tires
		glPushMatrix();
			glColor3f(0,0,0);//negro
			glRotated(90,0,1,0);   // Tuerce las ruedas para que no vaya de lado
			glTranslated(posX,-0.3*carSize,posZ);//-radioRueda,0,0.1*x);
			glRotated(wheelPosition,0,0,1);
			glutSolidCylinder(wheelRatius, wheelWith, nWheelFaces,1);
		glPopMatrix();

		//Rims
		glPushMatrix();
			glColor3f(1,1,1);//blanco
			glRotated(90,0,1,0);   // Tuerce las ruedas para que no vaya de lado
			glTranslated(posX,-0.3*carSize,rim);//-radioRueda,0,0.1*x);
			glRotated(wheelPosition,0,0,1);
			glutSolidCylinder(wheelRatius*0.9, wheelWith*1.1, 3,1);
		glPopMatrix();

	   }
	   
	glPopMatrix();
}

void Car::stepWheel(){
	wheelPosition += wheelInc;
}