#include "Pixmap.h"

Pixmap::Pixmap(void)
{rgbMap =NULL;
}


Pixmap::~Pixmap(void)
{
}



bool Pixmap::loadFromFile(char * imagepath){
	unsigned char * data = loadBMPRaw(imagepath,nRows,nCols);
	rgbMap = new colorRGBA[nRows*nCols];
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, nCols, nRows, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	return true;
}

bool Pixmap::loadFromBufer(int width, int height, GLfloat x, GLfloat y){
	//if(rgbMap==NULL) delete[] rgbMap; // esta linea no tiene mucho sentido
    rgbMap = new colorRGBA[height*width];
    nRows = height;
    nCols = width;
	glPixelStorei(GL_PACK_ALIGNMENT, //Cómo se leen los pixeles
        1); //sin padding entre filas
	glReadPixels(x, y, //esquina inferior-izquierda del bloque,
		nCols, nRows, // tamaño del bloque
		GL_RGB,  //datos a leer
		GL_UNSIGNED_BYTE, //tipo de los datos
		rgbMap); //destino
	
	return true;
}

bool Pixmap::drawMatrix(GLfloat x, GLfloat y){  // tal cual de las traspas
	glPixelStorei(GL_UNPACK_ALIGNMENT, //como escribir los pixeles 
		1); //sin padding entre filas
	glRasterPos2i(x, y); //esquina inferior-izquerda donde escribiremos el bloque, usando coordenadas OpenGL de la ventana
	glDrawPixels(nCols, nRows, //tamaño del bloque
		GL_RGB, //datos a escribir: buffer de color, de profundidad, componente alpha...
		GL_UNSIGNED_BYTE, //tipo de los datos
		rgbMap); //origen



	return true;
}

void Pixmap::rotate(GLdouble angle){

}

void Pixmap::difference(Pixmap* pm){

}

void Pixmap::weightedAverage(Pixmap* pm){

}