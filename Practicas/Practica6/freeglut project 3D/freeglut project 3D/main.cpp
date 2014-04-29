//Carlos Giraldo
//Raquel Peces
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
using namespace std;

#include "Escena.h";
#include "Camara.h";

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=10.0, eyeY=10.0, eyeZ=10.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

// Axis angles
GLfloat angleX=0,angleY=0,angleZ=0;

// Escena
Escena *scene;

//Camara
Camara camera;
PV3D aux = PV3D(0.01, 0.01, 1);

// Prueba
Objeto3D *testO;

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);    

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// buildSceneObjects();

	// Camera set up
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);
	*/
	//PV3D *eye = new PV3D(100.0, 100.0, 100.0);
	//PV3D *look = new PV3D(0.0, 0.0, 0.0);
	//PV3D *up = new PV3D(0, 1, 0);
	camera = Camara(PV3D(100.0, 100.0, 100.0), PV3D(0.0, 0.0, 0.0), PV3D(0, 1, 0));

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  

	 // Light0
    glEnable(GL_LIGHT0);
    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[]={25.0, 25.0, 0.0, 1.0};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	
		// Drawing axes
	glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);	glVertex3f(20, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);	glVertex3f(0, 20, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);	glVertex3f(0, 0, 20);	     
	glEnd();
	
	//glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
		// TODO esto se cambiará por la cámara

		glRotatef(angleX,1,0,0);
        glRotatef(angleY,0,1,0);
        glRotatef(angleZ,0,0,1);

		glColor3f(1.0, 1.0, 1.0);
		glBegin( GL_LINES );
			glColor3f(1.0,0.0,0.0); 
			glVertex3f(0, 0, 0);	glVertex3f(20, 0, 0);	     
	 
			glColor3f(0.0,1.0,0.0); 
			glVertex3f(0, 0, 0);	glVertex3f(0, 20, 0);	 
	 
			glColor3f(0.0,0.0,1.0);	
			glVertex3f(0, 0, 0);	glVertex3f(0, 0, 20);	     
		glEnd();

		testO->dibuja();
		//scene->dibuja();
	glPopMatrix();




	glFlush();
	glutSwapBuffers();
	
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

GLfloat mod360(GLfloat a){
	if(a>=360) return a-360;
	
	return a;
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
		break;		 			 
		// ----------------
		/*
		 // linea de debug::: 	cout<< angleX << " "<< angleY << " " <<angleZ << " ";
		case 'a': 
			angleX+=5;
			break;
		case 'z': 
			angleX-=5;
			break;
		// ----------------
		case 's': 
			angleY+=5;
			break;
		case 'x': 
			angleY-=5;
			break;
		// ----------------
		case 'd': 
			angleZ+=5;
			break;
		case 'c': 
			angleZ-=5;
			break;
		// ----------------
			*/
		// ------ Roll
		case 'u':
			camera.roll(0.09);
			break;
		case 'i':
			camera.roll(-0.09);
			break;
		// ------ Yaw
		case 'j':
			camera.yaw(0.01);
			break;
		case 'k':
			camera.yaw(-0.01);
			break;
		// ------ Pitch
		case 'n':
			camera.pitch(0.01);
			break;
		case 'm':
			camera.pitch(-0.01);
			break;
		// ------ Recorrido X
		case 'e':
			camera.recorridoEje(10.0,0.0,0.0);
			break;
		case 'r':
			camera.recorridoEje(-10.0,0.0,0.0);
			break;
		// ------ Recorrido Y
		case 'd':
			camera.recorridoEje(0.0,10.0,0.0);
			break;
		case 'f':
			camera.recorridoEje(0.0,-10.0,0.0);
			break;
		// ------ Recorrido Z
		case 'c':
			camera.recorridoEje(0.0,0.0,10.0);
			break;
		case 'v':
			camera.recorridoEje(0.0,0.0,-10.0);
			break;
		// ------ Desplazar X
		case 'q':
			camera.desplazar(2.0,0.0,0.0);
			break;
		case 'w':
			camera.desplazar(-2.0,0.0,0.0);
			break;
		// ------ Desplazar Y
		case 'a':
			camera.desplazar(0.0,2.0,0.0);
			break;
		case 's':
			camera.desplazar(0.0,-2.0,0.0);
			break;
		// ------ Desplazar Z
		case 'z':
			camera.desplazar(0.0,0.0,2.0);
			break;
		case 'x':
			camera.desplazar(0.0,0.0,-2.0);
			break;
		// ------ Ortogonal
		case 'o':
			camera.ortogonal(xLeft,xRight,yBot,yTop,N,F);
			break;
		// ------ Perspectiva
		case 'p':
			camera.perspectiva(xLeft,xRight,yBot,yTop,N,F);
			break;
		// ------ Oblicua
		case 'l':
			camera.oblicua(aux.clone(),xLeft,xRight,yBot,yTop,N,F);
			break;
		// ------ Gira X
		case '1':
			camera.giraX(0.1);
			break;
		// ------ Gira Y
 		case '2':
			camera.giraY(0.1);
			break;
		// ------ Gira Z
		case '3':
			camera.giraZ(0.1);
			break;
		// ------ Vista Lateral
		case '4':
			camera.lateral();
			break;
		// ------ Vista Frontal
		case '5':
			camera.frontal();
			break;
		// ------ Vista Cenital
		case '6':
			camera.cenital();
			break;
		// ------ Vista Esquina
		case '7':
			camera.esquina();
			break;
		default:
			need_redisplay = false;
			cout<<key<<endl;
			break;
	}
	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Escena
	/*cout << "inicializa" << endl;
	scene = new Escena(); // NP = 30 NQ = 40
	cout << "construye" << endl;
	scene->init();*/

	testO = new Escena();
	//testO->obRotate(-90.0,0);
	//testO->obScale(1.0,5.0,1.0);
	

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}
