#include "Car.h"


Car::Car(GLdouble s)
{
	cout << "entrando a Car del Car" << endl;
	nWheelFaces = 20;
	
	carSize = s;
	chassisSize = 0.6*s; 
	wheelRatius = 0.2*s;
	wheelWith = 0.2*s;
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
		GLdouble posX,posZ;
		switch (i){
			case 0: 
				posX = -0.3 * carSize;
				posZ =  0.3 * carSize;
				break;
			case 1: 
				posX = 0.3 * carSize;
				posZ = 0.3 * carSize;
				break;
			case 2: 
				posX = -0.3 * carSize;
				posZ = -0.3 * carSize - wheelWith;
				break;
			case 3: 
				posX =  0.3 * carSize;
				posZ = -0.3 * carSize - wheelWith;
				break;
		}

		//Wheels
		glPushMatrix();
			glColor3f(0,0,0);//negro
			glRotated(90,0,1,0);
			glTranslated(posX,-0.3*carSize,posZ);//-radioRueda,0,0.1*x);
			glutSolidCylinder(wheelRatius, wheelWith, nWheelFaces,1);
		glPopMatrix();

	   }
	   

	glPopMatrix();
}
