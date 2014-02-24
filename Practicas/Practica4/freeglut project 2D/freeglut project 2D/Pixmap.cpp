#include "Pixmap.h"

Pixmap::Pixmap(void)
{rgbMap =NULL;
}


Pixmap::~Pixmap(void)
{
}



bool Pixmap::loadFromFile(const char * imagepath){
	int dp;
	unsigned char * data = loadBMPRaw(imagepath,nRows,nCols,dp,false);
	if(data == NULL) return false;
	fillRGBMap(data,dp);
	delete[] data;
	return true;
}

void Pixmap::fillRGBMap(unsigned char *data, int dp){
	if(rgbMap!=NULL)delete(rgbMap);
	rgbMap = new colorRGBA[nRows*nCols];
	int i,j;
	for (i=0; i < nRows; i++){
		for (j=0; j < nCols; j++) {
			rgbMap[i*nCols+j][0]=data[(i*nCols+j)*3+2]; //R
			rgbMap[i*nCols+j][1]=data[(i*nCols+j)*3+1]; //G
			rgbMap[i*nCols+j][2]=data[(i*nCols+j)*3]; //B
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, //como escribir los pixeles 
		1); //sin padding entre filas
	glRasterPos2i(x, y); //esquina inferior-izquerda donde escribiremos el bloque, usando coordenadas OpenGL de la ventana
	glDrawPixels(nCols, nRows, //tamaño del bloque
		GL_RGB, //datos a escribir: buffer de color, de profundidad, componente alpha...
		GL_UNSIGNED_BYTE, //tipo de los datos
		rgbMap); //origen
	return true;
}

void Pixmap::rotate(GLdouble angle, GLdouble centerX, GLdouble centerY){
	colorRGBA* rotation = new colorRGBA[nCols * nRows];
	GLdouble auxX, auxY;
	int count, newPos;
    unsigned int i, j;
    for (i=1; i < nRows; i++)
		for (j=1; j < nCols; j++) {
			count=i*nCols + j;
			//Auxiliar point to rotate
			auxX = i-centerX;
			auxY = j-centerY;

			if(auxX != 0 && auxY != 0){
				//Get the length to current point to aux point
				GLdouble dist = sqrt (pow (auxX, 2) +  pow(auxY, 2) );
                //Get angle
				GLdouble dir = atan2(auxY, auxX)-angle;
				//Calculate new point with rotation
                int newX = centerX + dist * cos(dir);
                int newY = centerY + dist * sin(dir);
				//If new point out
                if(newX < 0 || newX >= nRows || newY < 0 || newY >= nCols){
                    rotation[count][0] = 0;
                    rotation[count][1] = 0;
                    rotation[count][2] = 0;
                }
				else{
					newPos = newX*nCols+newY;
					rotation[count][0] = rgbMap[newPos][0];
					rotation[count][1] = rgbMap[newPos][1];
                    rotation[count][2] = rgbMap[newPos][2];
				}
            }
    }

    delete [] rgbMap;
    rgbMap = rotation;
}

void Pixmap::difference(Pixmap* pm){
	if(pm->nCols<nCols) nCols = pm->nCols;
	if(pm->nRows<nRows) nRows = pm->nRows;
	colorRGBA *tmpMap = new colorRGBA[nCols*nRows];

	int i,j;
	for (i=1; i < nRows; i++){
        for (j=1; j < nCols; j++) {
			tmpMap[i*nCols+j][0] = abs(rgbMap[i*nCols+j][0]-pm->rgbMap[i*nCols+j][0]);
			tmpMap[i*nCols+j][1] = abs(rgbMap[i*nCols+j][1]-pm->rgbMap[i*nCols+j][1]);
			tmpMap[i*nCols+j][2] = abs(rgbMap[i*nCols+j][2]-pm->rgbMap[i*nCols+j][2]);
		}
	}
	delete [] rgbMap;
    rgbMap = tmpMap;
}

void Pixmap::weightedAverage(double k,Pixmap* pm){
	if(pm->nCols<nCols) nCols = pm->nCols;
	if(pm->nRows<nRows) nRows = pm->nRows;
	colorRGBA *tmpMap = new colorRGBA[nCols*nRows];

	int i,j;
	for (i=1; i < nRows; i++){
        for (j=1; j < nCols; j++) {
			tmpMap[i*nCols+j][0] = (rgbMap[i*nCols+j][0]*k)+(pm->rgbMap[i*nCols+j][0]*(1-k));
			tmpMap[i*nCols+j][1] = (rgbMap[i*nCols+j][1]*k)+(pm->rgbMap[i*nCols+j][1]*(1-k));
			tmpMap[i*nCols+j][2] = (rgbMap[i*nCols+j][2]*k)+(pm->rgbMap[i*nCols+j][2]*(1-k));
		}
	}
	delete [] rgbMap;
    rgbMap = tmpMap;
}