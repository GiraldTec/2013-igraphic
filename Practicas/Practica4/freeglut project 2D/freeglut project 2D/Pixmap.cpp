#include "Pixmap.h"

Pixmap::Pixmap(void)
{rgbMap =NULL;
}


Pixmap::~Pixmap(void)
{
}



bool Pixmap::loadFromFile(char * imagepath){
	int dp;
	unsigned char * data = loadBMPRaw(imagepath,nRows,nCols,dp,false);
	fillRGBMap(data,dp);
	//if(rgbMap!=NULL)delete(rgbMap);
	//rgbMap = new colorRGBA[nRows*nCols];
	//GLuint textureID;
	//glGenTextures(1, &textureID);
	//glBindTexture(GL_TEXTURE_2D, textureID);
	//glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, nCols, nRows, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
	delete[] data;
	return true;
}

void Pixmap::fillRGBMap(unsigned char *data, int dp){
	if(rgbMap!=NULL)delete(rgbMap);
	rgbMap = new colorRGBA[nRows*nCols];
	int i,j;
	for (i=0; i < nRows; i++){
		for (j=0; j < nCols; j++) {
			rgbMap[i*nCols+j][0]=data[dp+(i*nCols+j)*3+2]; //R
			rgbMap[i*nCols+j][1]=data[dp+(i*nCols+j)*3+1]; //G
			rgbMap[i*nCols+j][2]=data[dp+(i*nCols+j)*3+0]; //B
		}	
	}
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
	  colorRGBA* rotacion = new colorRGBA[nCols * nRows];

        //int puntoOrigenX = nCols / 2;
        //int puntoOrigenY = nRows / 2;

        int puntoOrigenX =10;
        int puntoOrigenY =10;

        int count;
        unsigned int i, j;
        for (i=1; i < nRows; i++)
                for (j=1; j < nCols; j++) {
                        count=i*nCols + j;
                        //Hallamos la distancia desde el punto actual al ogigen
                        GLdouble dist = sqrt (pow (i - puntoOrigenX, 2) +  pow(j - puntoOrigenY, 2) );
                        //Hallamos el angulo nuevo
                        GLdouble auxX = i-puntoOrigenX;
                        GLdouble auxY = j-puntoOrigenY;
                        if(auxX =! 0 && auxY != 0){
                        GLdouble dir = atan2(auxX, auxY);
                        dir +=-angle;

                                int puntoNuevoX = puntoOrigenX + dist * cos(dir);
                                int puntoNuevoY = puntoOrigenY + dist * sin(dir);

                                if(puntoNuevoX < nRows && puntoNuevoY < nCols ){

                                        //rotacion[puntoNuevoX * nCols + puntoNuevoY][0] = pixmap[count][0];
                                        //rotacion[puntoNuevoX * nCols + puntoNuevoY][1] = pixmap[count][1];
                                        //rotacion[puntoNuevoX * nCols + puntoNuevoY][2] = pixmap[count][2];

                                        rotacion[count][0] = rgbMap[puntoNuevoX * nCols + puntoNuevoY][0];
                                        rotacion[count][1] = rgbMap[puntoNuevoX * nCols + puntoNuevoY][1];
                                        rotacion[count][2] = rgbMap[puntoNuevoX * nCols + puntoNuevoY][2];
                                }
                        }
        }

		delete [] rgbMap;
        rgbMap = rotacion;

}

void Pixmap::difference(Pixmap* pm){

}

void Pixmap::weightedAverage(Pixmap* pm){

}