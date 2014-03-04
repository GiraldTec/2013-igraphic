#include "Pixmap.h"

Pixmap::Pixmap(void)
{rgbMap =NULL;
}


Pixmap::~Pixmap(void)
{
}



bool Pixmap::loadFromFile(const char * imagepath){
	int dp;
	unsigned char * data = loadBMPRaw(imagepath,nCols,nRows,dp,false);
	if(data == NULL) return false;
	fillRGBMap(data,dp);
	delete[] data;
	return true;
}

void Pixmap::fillRGBMap(unsigned char *data, int dp){
	if(rgbMap!=NULL)delete(rgbMap);
	rgbMap = new colorRGBA[nRows*nCols];
	int i,j;
	for (i=0; i < nCols; i++){
		for (j=0; j < nRows; j++) {
			int count = i*nRows+j;
			rgbMap[count][0]=data[count*3+2]; //R
			rgbMap[count][1]=data[count*3+1]; //G
			rgbMap[count][2]=data[count*3]; //B
		}	
	}
}

bool Pixmap::loadFromBufer(const int width,const int height, GLint x, GLint y){
	if(rgbMap!=NULL) delete[] rgbMap; rgbMap=NULL;
	rgbMap = new colorRGBA[height*width];
    nRows = height;
    nCols = width;
	glutSwapBuffers();
	glPixelStorei(GL_PACK_ALIGNMENT, //Cómo se leen los pixeles
        1); //sin padding entre filas
	glReadPixels(x, y, //esquina inferior-izquierda del bloque,
		nCols, nRows, // tamaño del bloque
		GL_RGB,  //datos a leer
		GL_UNSIGNED_BYTE, //tipo de los datos
		rgbMap); //destino
	glutSwapBuffers();
	return true;
}

bool Pixmap::drawMatrix(GLint x, GLint y){  // tal cual de las traspas
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
	for (i=0; i < nRows; i++)
		for (j=0; j < nCols; j++) {
			count=i*nCols + j;
			//Auxiliar point to rotate
			auxX = i-centerX;
			auxY = j-centerY;

			if(auxX != 0 || auxY != 0){
				//Get the length to current point to rotation center point
				GLdouble dist = sqrt (pow (auxX, 2) +  pow(auxY, 2));
                //Get angle
				GLdouble dir = atan2(auxY, auxX)+angle;
				//Calculate new point with rotation
                int newX = centerX + dist * cos(dir);
                int newY = centerY + dist * sin(dir);

                if(newX < nRows && newX >= 0 && newY < nCols && newY >= 0){
					rotation[count][0] = bilinearInterpolation(newX,newY,0);
					rotation[count][1] = bilinearInterpolation(newX,newY,1);
                    rotation[count][2] = bilinearInterpolation(newX,newY,2);
                }
				else{
					rotation[count][0] = 255;
                    rotation[count][1] = 255;
                    rotation[count][2] = 255;				
				}
			}
			else{
				rotation[count][0] = rgbMap[count][0];
				rotation[count][1] = rgbMap[count][1];
				rotation[count][2] = rgbMap[count][2];
			}
    }

    delete [] rgbMap;
    rgbMap = rotation;
}

GLdouble Pixmap::bilinearInterpolation(GLdouble x, GLdouble y, int channel){
	GLdouble difX = x - (int)x;
	GLdouble difY = y - (int)y;
	int newPos = x * nCols + y;
	GLdouble color = (1-difX) * (1-difY) * rgbMap[newPos][channel];

	if (y < nCols)
		color += (1-difX) * difY * rgbMap[newPos+1][channel];
	if (x < nRows+1)
		color += difX * (1-difY) * rgbMap[newPos+nCols][channel];
	if (y < nCols && x < nRows+1)
		color += difX * difY * rgbMap[newPos+nCols+1][channel];

	return color;

}

void Pixmap::difference(Pixmap* pm){
	int newCols=nCols,newRows=nRows;
	if(pm->nCols<nCols) newCols = pm->nCols;
	if(pm->nRows<nRows) newRows = pm->nRows;
	colorRGBA *tmpMap = new colorRGBA[nCols*nRows];

	int i,j;
	for (i=0; i < newRows; i++){
        for (j=0; j < newCols; j++) {
			tmpMap[i*newCols+j][0] = abs(rgbMap[i*(nCols)+j][0]-pm->rgbMap[i*pm->nCols+j][0]);
			tmpMap[i*newCols+j][1] = abs(rgbMap[i*(nCols)+j][1]-pm->rgbMap[i*pm->nCols+j][1]);
			tmpMap[i*newCols+j][2] = abs(rgbMap[i*(nCols)+j][2]-pm->rgbMap[i*pm->nCols+j][2]);
		}
	}
	delete [] rgbMap;
    rgbMap = tmpMap;
	nCols = newCols;
	nRows = newRows;
}

void Pixmap::weightedAverage(double k,Pixmap* pm){
	int newCols=nCols,newRows=nRows;
	if(pm->nCols<nCols) newCols = pm->nCols;
	if(pm->nRows<nRows) newRows = pm->nRows;
	colorRGBA *tmpMap = new colorRGBA[nCols*nRows];

	int i,j;
	for (i=0; i < newRows; i++){
        for (j=0; j < newCols; j++) {
			tmpMap[i*newCols+j][0] = (rgbMap[i*nCols+j][0]*k)+(pm->rgbMap[i*pm->nCols+j][0]*(1-k));
			tmpMap[i*newCols+j][1] = (rgbMap[i*nCols+j][1]*k)+(pm->rgbMap[i*pm->nCols+j][1]*(1-k));
			tmpMap[i*newCols+j][2] = (rgbMap[i*nCols+j][2]*k)+(pm->rgbMap[i*pm->nCols+j][2]*(1-k));
		}
	}
	delete [] rgbMap;
    rgbMap = tmpMap;
	nCols = newCols;
	nRows = newRows;
}

bool Pixmap::gaussianBlur(void){
	double matrixG[9];
	matrixG[0] = 0.0947416;	matrixG[1] = 0.118318;	matrixG[2] = 0.0947416;
	matrixG[3] = 0.118318;	matrixG[4] = 0.147761;	matrixG[5] = 0.118318;
	matrixG[6] = 0.0947416;	matrixG[7] = 0.118318;	matrixG[8] = 0.0947416;
	
	colorRGBA *tmpMap = new colorRGBA[nCols*nRows];
	
	int i,j,color;
	for (i=0; i < nRows; i++){
        for (j=0; j < nCols; j++) {
			for (color=0; color < 3; color ++){
				int prevR,prevC,postR,postC;
				prevR = (i-1) % nRows; 
				prevC = (j-1) % nCols; 
				postR = (i+1) % nRows; 
				postC = (j+1) % nCols; 
				tmpMap[i*nCols+j][color]= 
					matrixG[0]*rgbMap[prevR*nCols+prevC][color]+	
					matrixG[1]*rgbMap[prevR*nCols+j][color]+	
					matrixG[2]*rgbMap[prevR*nCols+postC][color]+
					matrixG[3]*rgbMap[i*nCols+prevC][color]+	
					matrixG[4]*rgbMap[i*nCols+j][color]+	
					matrixG[5]*rgbMap[i*nCols+postC][color]+
					matrixG[6]*rgbMap[postR*nCols+prevC][color]+	
					matrixG[7]*rgbMap[postR*nCols+j][color]+	
					matrixG[8]*rgbMap[postR*nCols+postC][color];

			}
		}
	}
	delete [] rgbMap;
    rgbMap = tmpMap;
	return true;
}