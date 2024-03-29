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
#include "TextureLoader.h";

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 1000, HEIGHT= 1000;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=10.0, eyeY=10.0, eyeZ=10.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

// Axis angles
GLfloat angleX=0,angleY=0,angleZ=0;

//Camara
Camara camera;
PV3D aux = PV3D(0.01, 0.01, 1);
GLdouble acumRoll, acumYaw, acumPitch;

// Prueba
Escena *escena;

//Componentes de luz
bool lampOn,eastOn,ambOn,fogOn;


//Texturas
GLuint texturas[2];

void initGL() {	 	
	
	camera = Camara(PV3D(50.0, 50.0, 50.0), PV3D(0.0, 0.0, 0.0), PV3D(0, 1, 0));
	acumRoll = 0;
	acumPitch = 0;
	acumYaw = 0;
	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	glClearColor(0.0,0.0,0.0,1.0);//0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);    

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_FLAT);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  

	// LUZ AMBIENTE
	GLfloat amb[] = {1.0,0.05,0.05,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	 // Foco de la l�mpara
    glEnable(GL_LIGHT0);
/*	//glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, focoA);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 4.0);
	

    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a); */

	// Luz del este
	glEnable(GL_LIGHT1);

	fogOn = true;
	ambOn = true;
	lampOn = true;
	eastOn = true;

	//Niebla
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_DENSITY, 0.018f);
	glHint (GL_FOG_HINT, GL_NICEST);

	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	//Texturas
	unsigned int width;
	unsigned int height;
	unsigned char * data = loadBMPRaw("bmp/madera.bmp", width, height);
	unsigned char * data2 = loadBMPRaw("bmp/hierba.bmp", width, height);
	cout<< width << endl;
	cout<< height << endl;

	glGenTextures(2, texturas);
	//glGenTextures(1, &textureID);

	//glEnable(GL_TEXTURE_2D);
	//Leer en la variable textura, el archivo que contiene la imagen 
	//usando la clase lectora
	glBindTexture(GL_TEXTURE_2D, 0);

	//Textura mesa
	glBindTexture(GL_TEXTURE_2D, texturas[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);

	//Textura tapete
	glBindTexture(GL_TEXTURE_2D, texturas[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);

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
	
	// LUZ DEL ESTE
	GLfloat d[]={0.8,0.8,0.8,1.0};
    GLfloat a[]={0.2,0.2,0.2,1.0};
	GLfloat p2[]={10.0,10.0,0.0,1.0};
	glLightfv(GL_LIGHT1, GL_POSITION, p2);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, d);
    glLightfv(GL_LIGHT1, GL_AMBIENT, a);

	
	//FOG
	glFogf(GL_FOG_START, 60.0f);
	glFogf(GL_FOG_END, 95.0f);
	
	escena->dibuja();

	glFlush();
	glutSwapBuffers();
	
}

void selectTexture(int i){
	glBindTexture(GL_TEXTURE_2D, texturas[i]);
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
		

		case '+': 
			if(lampOn){
				escena->getLamp()->increaseA();
				escena->getLamp()->obScale(1.0,0.8,1.0);
			}
			break;
		case '-': 
			if(lampOn){
				escena->getLamp()->decreaseA();
				escena->getLamp()->obScale(1.0,1.25,1.0);
			}
			break;
		case '8': 
			if(ambOn){
				GLfloat amb[] = {0.0,0.0,0.0,1.0};
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
				ambOn = false;
			}else{
				GLfloat amb[] = {1.0,0.05,0.05,1.0};
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
				ambOn = true;
			}
			break;
		case '*': 
			if(fogOn){
				glDisable(GL_FOG);
				fogOn = false;
			}else{
				glEnable(GL_FOG);;
				fogOn = true;
			}
			break;
		case '9': 
			if(lampOn){
				glDisable(GL_LIGHT0);
				lampOn = false;
			}else{
				glEnable(GL_LIGHT0);
				lampOn = true;
			}
			break;
		case '0': 
			if(eastOn){
				glDisable(GL_LIGHT1);
				eastOn = false;
			}else{
				glEnable(GL_LIGHT1);
				eastOn = true;
			}
			break;
		case 'T': 
			escena->getLamp()->obRotate(5,0);
			break;
		case 'Y': 
			escena->getLamp()->obRotate(-5,0);
			break;
		// ----------------
		case 'G':
			escena->getLamp()->obRotate(5,1);
			break;
		case 'H': 
			escena->getLamp()->obRotate(-5,1);
			break;
		// ----------------
		case 'B': 
			escena->getLamp()->obRotate(5,-1);
			break;
		case 'N': 
			escena->getLamp()->obRotate(-5,-1);
			break;
		// ----------------
		case 'Q': 
			escena->getLamp()->obTraslate(1.0,0.0,0.0);
			break;
		case 'W': 
			escena->getLamp()->obTraslate(-1.0,0.0,0.0);
			break;
		// ----------------
		case 'A':
			escena->getLamp()->obTraslate(0.0,1.0,0.0);
			break;
		case 'S': 
			escena->getLamp()->obTraslate(0.0,-1.0,0.0);
			break;
		// ----------------
		case 'Z': 
			escena->getLamp()->obTraslate(0.0,0.0,1.0);
			break;
		case 'X': 
			escena->getLamp()->obTraslate(0.0,0.0,-1.0);
			break;
		// -----------------

		 // linea de debug::: 	cout<< angleX << " "<< angleY << " " <<angleZ << " ";
		case 't': 
			escena->obRotate(5,0);
			break;
		case 'y': 
			escena->obRotate(-5,0);
			break;
		// ----------------
		case 'g':
			escena->obRotate(5,1);
			break;
		case 'h': 
			escena->obRotate(-5,1);
			break;
		// ----------------
		case 'b': 
			escena->obRotate(5,-1);
			break;
		case ',': 
			escena->obRotate(-5,-1);
			break;
		// ----------------
			
		// ------ Roll
		case 'u':
			acumRoll += 0.09;
			camera.roll(acumRoll);
			break;
		case 'i':
			acumRoll += -0.09;
			camera.roll(acumRoll);
			break;
		// ------ Yaw
		case 'j':
			acumYaw += 0.01;
			acumRoll = 0;
			acumPitch = 0;
			camera.yaw(acumYaw);
			break;
		case 'k':
			acumYaw += -0.01;
			acumRoll = 0;
			acumPitch = 0;
			camera.yaw(acumYaw);
			break;
		// ------ Pitch
		case 'n':
			acumPitch += 0.01;
			acumRoll = 0;
			acumYaw = 0;
			camera.pitch(acumPitch);
			break;
		case 'm':
			acumPitch += -0.01;
			acumRoll = 0;
			acumYaw = 0;
			camera.pitch(acumPitch);
			break;
		// ------ Recorrido X
		case 'e':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.recorridoEje(10.0,0.0,0.0);
			break;
		case 'r':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.recorridoEje(-10.0,0.0,0.0);
			break;
		// ------ Recorrido Y
		case 'd':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.recorridoEje(0.0,10.0,0.0);
			break;
		case 'f':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.recorridoEje(0.0,-10.0,0.0);
			break;
		// ------ Recorrido Z
		case 'c':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.recorridoEje(0.0,0.0,10.0);
			break;
		case 'v':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.recorridoEje(0.0,0.0,-10.0);
			break;
		// ------ Desplazar X
		case 'q':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.desplazar(2.0,0.0,0.0);
			break;
		case 'w':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.desplazar(-2.0,0.0,0.0);
			break;
		// ------ Desplazar Y
		case 'a':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.desplazar(0.0,2.0,0.0);
			break;
		case 's':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.desplazar(0.0,-2.0,0.0);
			break;
		// ------ Desplazar Z
		case 'z':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.desplazar(0.0,0.0,2.0);
			break;
		case 'x':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.desplazar(0.0,0.0,-2.0);
			break;
		// ------ Ortogonal
		case 'o':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.ortogonal(xLeft,xRight,yBot,yTop,N,F);
			break;
		// ------ Perspectiva
		case 'p':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.perspectiva(xLeft,xRight,yBot,yTop,N,F);
			break;
		// ------ Oblicua
		case 'l':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.oblicua(aux.clone(),xLeft,xRight,yBot,yTop,N,F);
			break;
		// ------ Gira X
		case '1':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.giraX(0.1);
			break;
		// ------ Gira Y
 		case '2':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.giraY(0.1);
			break;
		// ------ Gira Z
		case '3':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.giraZ(0.1);
			break;
		// ------ Vista Lateral
		case '4':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.lateral();
			break;
		// ------ Vista Frontal
		case '5':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.frontal();
			break;
		// ------ Vista Cenital
		case '6':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
			camera.cenital();
			break;
		// ------ Vista Esquina
		case '7':
			acumRoll = 0;
			acumPitch = 0;
			acumYaw = 0;
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
	escena = new Escena();
	escena->obScale(0.06);

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
