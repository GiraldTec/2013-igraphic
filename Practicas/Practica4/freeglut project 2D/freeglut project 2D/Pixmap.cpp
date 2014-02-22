#include "Pixmap.h"

Pixmap::Pixmap(void)
{
}


Pixmap::~Pixmap(void)
{
}


bool Pixmap::loadFromBufer(int width, int height, GLfloat x, GLfloat y){
	delete[] rgbMap;
    rgbMap = new colorRGBA[height*width];
    nRows = height;
    nCols = width;
	glPixelStorei(GL_PACK_ALIGNMENT, //Cómo se leen los pixeles
        1); //sin padding entre filas
	glReadPixels(x, y, //esquina inferior-izquierda del bloque,
		nCols, nRows, // tamaño del bloque
		GL_RGB,  //datos a leer
		GL_UNSIGNED_BYTE, //tipo de los datos
		arbol); //destino
	
	return true;
}

bool Pixmap::drawMatrix(void){

	return true;
}