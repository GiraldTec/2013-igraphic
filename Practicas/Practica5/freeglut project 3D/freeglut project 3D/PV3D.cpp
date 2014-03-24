#include "PV3D.h"


PV3D::PV3D(void)
{
	this->corX = 0;
	this->corY = 0;
	this->corZ = 0;
}

PV3D::PV3D(GLdouble x, GLdouble y, GLdouble z)
{
	this->corX = x;
	this->corY = y;
	this->corZ = z;
}

GLdouble PV3D::getX()
{
	return corX;
}

GLdouble PV3D::getY()
{
	return corY;
}

GLdouble PV3D::getZ()
{
	return corZ;
}

void PV3D::setX(GLdouble x)
{
	this->corX = x;
}

void PV3D::setY(GLdouble y)
{
	this->corY = y;
}

void PV3D::setZ(GLdouble z)
{
	this->corZ = z;
}

//--------------------------------------
int PV3D::getPv()
{
     return this->pv;
}
void PV3D::setPv(int val)
{
        this->pv=val;
}
//--------------------------------------

PV3D* PV3D::clone(){
	return new PV3D(this->corX,this->corY,this->corZ);
}

PV3D* PV3D::addition(PV3D* p)
{
	return new PV3D(this->corX+p->getX(),this->corY+p->getY(),this->corZ+p->getZ());
}

PV3D* PV3D::subtraction(PV3D* p)
{
	return new PV3D(this->corX-p->getX(),this->corY-p->getY(),this->corZ-p->getZ());
}

void PV3D::normalize()
{
	GLdouble magnitude = this->magnitude();
	this->corX = this->corX/magnitude;
	this->corY = this->corY/magnitude;
	this->corZ = this->corZ/magnitude;
}

GLdouble PV3D::magnitude()
{
	GLdouble aux = pow(this->corX,2)+pow(this->corY,2)+pow(this->corZ,2);
	return sqrt(aux);
}

PV3D* PV3D::crossProduct(PV3D* v)
{
	GLdouble factori=(this->corY*v->getZ())-(this->corZ*v->getY());
     GLdouble factorj=(this->corZ*v->getX())-(this->corX*v->getZ());
     GLdouble factork=(this->corX*v->getY())-(this->corY*v->getX());

     return new PV3D(factori,factorj,factork);

}

PV3D* PV3D::matrixProduct(PV3D* Nt,PV3D* Bt,PV3D* Tt,PV3D* Ct)
{
        GLdouble matriz[4][4];
                matriz[0][0]=Nt->getX();
                matriz[1][0]=Nt->getY();
                matriz[2][0]=Nt->getZ();
                matriz[3][0]=0;

                matriz[0][1]=Bt->getX();
                matriz[1][1]=Bt->getY();
                matriz[2][1]=Bt->getZ();
                matriz[3][1]=0;

                matriz[0][2]=Tt->getX();
                matriz[1][2]=Tt->getY();
                matriz[2][2]=Tt->getZ();
                matriz[3][2]=0;

                matriz[0][3]=Ct->getX();
                matriz[1][3]=Ct->getY();
                matriz[2][3]=Ct->getZ();
                matriz[3][3]=1;


        GLdouble valx=matriz[0][0]*corX+matriz[0][1]*corY+matriz[0][2]*corZ+matriz[0][3]*pv;
        GLdouble valy=matriz[1][0]*corX+matriz[1][1]*corY+matriz[1][2]*corZ+matriz[1][3]*pv;
        GLdouble valz=matriz[2][0]*corX+matriz[2][1]*corY+matriz[2][2]*corZ+matriz[2][3]*pv;
        return new PV3D(valx,valy,valz);
}

PV3D::~PV3D(void)
{
}
