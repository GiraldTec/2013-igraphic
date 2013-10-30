#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <Scene.h>

#include <iostream>
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;


Scene* escena;

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
 
  // Scene rendering
  escena->render();

  glFlush();
  glutSwapBuffers();
}


void resize(int newWidth, int newHeight){
  //Resize Viewport
 /* WIDTH= newWidth;
  HEIGHT= newHeight;
  GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
  glViewport ( 0, 0, WIDTH, HEIGHT ) ;
 
  //Resize Scene Visible Area 
  //Se actualiza el área visible de la escena
  //para que su ratio coincida con ratioViewPort
  GLdouble SVAWidth= xRight-xLeft;
  GLdouble SVAHeight= yTop-yBot;
  GLdouble SVARatio= SVAWidth/SVAHeight;
  if (SVARatio >= RatioViewPort) {
	 // Increase SVAHeight
     GLdouble newHeight= SVAWidth/RatioViewPort;
	 GLdouble yMiddle= ( yBot+yTop )/2.0;
     yTop= yMiddle + newHeight/2.0;
     yBot= yMiddle - newHeight/2.0;
     }
  else {
     //Increase SVAWidth
     GLdouble newWidth= SVAHeight*RatioViewPort;
     GLdouble xMiddle= ( xLeft+xRight )/2.0;
	 xRight= xMiddle + newWidth/2.0;
     xLeft=  xMiddle - newWidth/2.0;
  }
  

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft, xRight, yBot, yTop); */
}


void key(unsigned char key, int x, int y){
 
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
    break;
  }//switch

  if (need_redisplay)
    glutPostRedisplay();
}

void mouse(int button, int state,int x, int y){
	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state){
			case GLUT_DOWN:
					y = HEIGHT - y;
					GLdouble aux_x = ((escena->xRight - escena->xLeft)*x)/WIDTH;
					GLdouble aux_y = ((escena->yTop - escena->yBot)*y)/HEIGHT;

					if (escena->mouse_input(aux_x,aux_y)) cout << "Se crea arbol en la escena" << endl;
					else cout << "Ya existe arbol en la escena" << endl;
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
