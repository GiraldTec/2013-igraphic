#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <Scene.h>
#include <Lectora/TextureLoader.h>
#include <Pixmap.h>

#include <iostream>
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;


Scene* escena;
Pixmap *pixMap1,*pixMap2;
boolean seleccionado1 = true;


void intitGL(){

	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(escena->red,escena->green,escena->blue); 

	glPointSize(4.0);
	glLineWidth(2.0);

	// Viewport
    glViewport(0, 0, WIDTH, HEIGHT);
    
	// Model transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Scene Visible Area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(escena->xLeft, escena->xRight, escena->yBot, escena->yTop); 
 }


void display(void){
  glClear( GL_COLOR_BUFFER_BIT );
 
  switch(seleccionado1){
  case true:
	  if(pixMap1!=NULL)pixMap1->drawMatrix(0,0);  // esto es con propósitos de debug unicamente
	  break;
  case false:
	  if(pixMap2!=NULL)pixMap2->drawMatrix(0,0);  // esto es con propósitos de debug unicamente
	  break;
  }
  // Scene rendering
  escena->render();
  cout<<"se renderiza"<<endl;

  glFlush();
  glutSwapBuffers();
}


void resize(int newWidth, int newHeight){
  //Resize Viewport
  WIDTH= newWidth;
  HEIGHT= newHeight;
  GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
  glViewport ( 0, 0, WIDTH, HEIGHT ) ;
 
  //Resize Scene Visible Area 
  //Se actualiza el área visible de la escena
  //para que su ratio coincida con ratioViewPort
  GLdouble SVAWidth= escena->xRight-escena->xLeft;
  GLdouble SVAHeight= escena->yTop-escena->yBot;
  GLdouble SVARatio= SVAWidth/SVAHeight;
  if (SVARatio >= RatioViewPort) {
	 // Increase SVAHeight
     GLdouble newHeight= SVAWidth/RatioViewPort;
	 GLdouble yMiddle= ( escena->yBot+escena->yTop )/2.0;
     escena->yTop= yMiddle + newHeight/2.0;
     escena->yBot= yMiddle - newHeight/2.0;
     }
  else {
     //Increase SVAWidth
     GLdouble newWidth= SVAHeight*RatioViewPort;
     GLdouble xMiddle= ( escena->xLeft+escena->xRight )/2.0;
	 escena->xRight= xMiddle + newWidth/2.0;
     escena->xLeft=  xMiddle - newWidth/2.0;
  }
  

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(escena->xLeft, escena->xRight, escena->yBot, escena->yTop); 
}

bool buferToPixMap(Pixmap *&pm){  // borra el "pixmap" entero cuando toca "sobreescribir"
	if (pm!=NULL) {delete(pm);pm=NULL;}
	pm = new Pixmap();
	return pm->loadFromBufer(WIDTH,HEIGHT,0,0); // se supone que (0,0) es la esquina inferior izquierda de la ventana
}

bool fileToPixMap(Pixmap *&pm,char* imagepath){
	if (pm!=NULL) {delete(pm);pm=NULL;}
	pm = new Pixmap();
	return pm->loadFromFile(imagepath);
}

void desenfoqueGauss(Pixmap *&pm){

}

void key(unsigned char key, int x, int y){
 
	int pmID;  // PixMap Identifier
  bool need_redisplay = true;

  switch (key) {
  case 27:  /* Escape key */
    //continue_in_main_loop = false; // (**)
	glutLeaveMainLoop (); //Freeglut's sentence for stopping glut's main loop (*)
    break;

// Movimientos de cámara : RIGHT / LEFT / UP / DOWN
  case 'd' :
  case 'D' :
    escena->cam_right();
    break ;

  case 'a' :
  case 'A' :
    escena->cam_left();
    break ;

  case 'w' :
  case 'W' :
    escena->cam_up();
    break ;

  case 's' :
  case 'S' :
    escena->cam_down();
    break ;

// Zoom de cámara : IN / OUT

  case 'e' :
  case 'E' :
	escena->cam_in();
	break ;

  case 'q' :
  case 'Q' :
    escena->cam_out();
    break ;

// Reset escene

  case 'r' :
  case 'R' :
	if (escena->reset()) cout << "La escena ha sido reseteada" << endl;
	else cout << "No había nada que resetear" << endl;
	break;

// Angle setting

  case 'k':
  case 'K':
	if (escena->read_angle()) cout << "El angulo ha sido impuesto" << endl;
	else cout << "No hay arbol" << endl;
	break;

//  Load BMP

  case 'l':
  case 'L':{
	  char imagepath[] = "./images/star.bmp";
	  //cout << "Escriba la ruta de la imagen";
	  //cin >> imagepath;
	  fileToPixMap(pixMap1,imagepath);
	  
	  // Hay que elegir a cual de los dos pixMaps disponibles se asigna el bmp que se carga
		   }
	  break;

//	Asignar lo que se muestra a un pixMap
	
	case 'm':
	case 'M':
		// TODO  Coger el bufer y asignarlo a una de nuestras estructuras pixMap
		
		cout << "Elija el pixMap que recibirá el contenido del Buffer";
		cin >> pmID;
	  
		switch (pmID) {
		case 1: buferToPixMap(pixMap1); break;
		case 2: buferToPixMap(pixMap2); break;
		default: break;
		}
	break;
	  
// Rotación de un angulo
	case 'v':
	case 'V':
		
		cout << "Elija el pixMap que recibirá el contenido del Buffer: ";
		cin >> pmID;
	  
		switch (pmID) {
		case 1: pixMap1->rotate(90);break;
		case 2: pixMap2->rotate(90); break;
		default: break;
		}
	break;

// Media Ponderada de BitMaps
	case 'z':
	case 'Z':
		if(pixMap1==NULL||pixMap2==NULL){
		cout << "Debe tener los dos pixMaps cargados" << endl;}
		else{
			double factor;
			cout << "Introduzca el valor del factor con el que realizar la operación: ";
			cin >> factor;
			cout << "Elija el pixMap que recibirá el resultado de la operación: " ;
			cin >> pmID;
	  
			switch (pmID) {
			case 1: pixMap1->weightedAverage(factor,pixMap2);break;
			case 2: pixMap2->weightedAverage(factor,pixMap1); break;
			default: break;
			}
		}
		break;

// Diferencia de BitMaps

	case 'x':
	case 'X':
		if(pixMap1==NULL||pixMap2==NULL){
		cout << "Debe tener los dos pixMaps cargados" << endl;}
		else{
			cout << "Elija el pixMap que recibirá el resultado de la operación: " ;
			cin >> pmID;
	  
			switch (pmID) {
			case 1: pixMap1->difference(pixMap2);break;
			case 2: pixMap2->difference(pixMap1); break;
			default: break;
			}
		}
		break;

// Gaussian Blur

	case 'b':
	case 'B':
		
		cout << "Elija el pixMap que recibirá el resultado de la operación: " ;
		cin >> pmID;

		double factor;
		cout << "Introduzca el valor del factor con el que realizar la operación: ";
		cin >> factor;
		switch (pmID) {
		case 1: desenfoqueGauss(pixMap1); break;
		case 2: desenfoqueGauss(pixMap2); break;
		default: break;
		}
		break;

// Selección del pixMap

	case 49:
		seleccionado1 = true;
		break;

	case 50:
		seleccionado1 = false;
		break;

// Crecimiento/Decrecimiento del árbol

  case '+' :
	if (escena->tree_grow()) cout << "El árbol existe y crece" << endl;
	else cout << "El árbol no existe o no crece" << endl;
	break;

  case '-' :
	if (escena->tree_drecrease()) cout << "El arbol existe y decrece" << endl;
	else cout << "El arbol no existe o no decrece" << endl;
	break;

  default:
    need_redisplay = false;
	cout << "la tecla es: " << (int) key << endl;
    break;
  }//switch

  if (need_redisplay)
    glutPostRedisplay();
}

void mouse(int button, int state,int x, int y){
	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state){
			case GLUT_DOWN:{
					y = HEIGHT - y;
					GLdouble aux_x = (((escena->xRight - escena->xLeft)*x)/WIDTH) + escena->xLeft;
					GLdouble aux_y = (((escena->yTop - escena->yBot)*y)/HEIGHT)+escena->yBot;
					cout << aux_x << " " << aux_y << " " << endl;

					escena->mouse_input(aux_x,aux_y);
					}
				break;
			case GLUT_UP:
				break; 
		}// switch state
		break;
	}//switch
}



int main(int argc, char *argv[]){
  cout<< "Starting console..." << endl;

  int my_window; //my window's identifier

  //Initialization
  glutInitWindowSize(500, 500);
  glutInitWindowPosition (0,0);//140, 140);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
  glutInit(&argc, argv);

  //Window construction
  my_window = glutCreateWindow( "Freeglut 2D-project" );
    
  //Callback registration
  glutReshapeFunc(resize);
  glutKeyboardFunc(key);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
    
  escena = new Scene();
  pixMap1 = pixMap2 = NULL;

  //OpenGL basic setting
  intitGL(); 

  // Freeglut's main loop can be stopped executing (**)
  //while ( continue_in_main_loop )
  //  glutMainLoopEvent();

  // Classic glut's main loop can be stopped after X-closing the window,
  // using the following freeglut's setting (*)
  glutSetOption ( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ) ;
    //GLUT_ACTION_GLUTMAINLOOP_RETURNS);
  // Classic glut's main loop can be stopped in freeglut using (*)
  glutMainLoop(); 
  
  cout << "se sale del programa" << endl;
  delete escena;
  escena = NULL;

  // We would never reach this point using classic glut
  system("PAUSE"); 
   
  return 0;
}
