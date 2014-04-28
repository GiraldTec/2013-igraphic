//Carlos Giraldo
//Raquel Peces
#include "PV3D.h"

PV3D::PV3D(void){
	this->corX = 0;
	this->corY = 0;
	this->corZ = 0;
}
PV3D::PV3D(GLdouble x, GLdouble y, GLdouble z){
	this->corX = x;
	this->corY = y;
	this->corZ = z;
}
PV3D::~PV3D(void){}
//--------------------------------------------------------------
GLdouble PV3D::getX(){
	return corX;
}
GLdouble PV3D::getY(){
	return corY;
}
GLdouble PV3D::getZ(){
	return corZ;
}
//--------------------------------------------------------------
void PV3D::setXYZ(GLdouble x, GLdouble y, GLdouble z){
	setX(x);
	setY(y);
	setZ(z);
}
void PV3D::setX(GLdouble x){
	this->corX = x;
}
void PV3D::setY(GLdouble y){
	this->corY = y;
}
void PV3D::setZ(GLdouble z){
	this->corZ = z;
}
//--------------------------------------------------------------
int PV3D::getPv(){
     return this->pv;
}
void PV3D::setPv(int val){
        this->pv=val;
}
//--------------------------------------------------------------
PV3D* PV3D::clone(){
	return new PV3D(this->corX,this->corY,this->corZ);
}

PV3D* PV3D::addition(PV3D* p){
	return new PV3D(this->corX+p->getX(),this->corY+p->getY(),this->corZ+p->getZ());
}
PV3D* PV3D::subtraction(PV3D* p){
	return new PV3D(this->corX-p->getX(),this->corY-p->getY(),this->corZ-p->getZ());
}
//--------------------------------------------------------------
void PV3D::normalize(){
	GLdouble magnitude = this->magnitude();
	this->corX = this->corX/magnitude;
	this->corY = this->corY/magnitude;
	this->corZ = this->corZ/magnitude;
}
GLdouble PV3D::magnitude(){
	GLdouble aux = pow(this->corX,2)+pow(this->corY,2)+pow(this->corZ,2);
	return sqrt(aux);
}
PV3D* PV3D::crossProduct(PV3D* v){
	GLdouble factori=(this->corY*v->getZ())-(this->corZ*v->getY());
	GLdouble factorj=(this->corZ*v->getX())-(this->corX*v->getZ());
	GLdouble factork=(this->corX*v->getY())-(this->corY*v->getX());

	return new PV3D(factori,factorj,factork);
}
GLdouble PV3D::scalarProduct(PV3D* v){
	return this->corX*v->getX()+this->corY*v->getY()+this->corZ*v->getZ();
}
PV3D* PV3D::matrixProduct(PV3D* Nt,PV3D* Bt,PV3D* Tt,PV3D* Ct)
{
        /*	Esta es la idea de esta operación
            {   Nt->getX()	Bt->getX()	Tt->getX()	Ct->getX()	}	{ corX }
            {   Nt->getY()	Bt->getY()	Tt->getY()	Ct->getY()	}	{ corY }
            {   Nt->getZ()	Bt->getZ()	Tt->getZ()	Ct->getZ()	}	{ corZ }
																	{  1   }

		*/
        GLdouble valx= Nt->getX() * corX + Bt->getX() * corY + Tt->getX() * corZ + Ct->getX();
        GLdouble valy= Nt->getY() * corX + Bt->getY() * corY + Tt->getY() * corZ + Ct->getY();
        GLdouble valz= Nt->getZ() * corX + Bt->getZ() * corY + Tt->getZ() * corZ + Ct->getZ();
        return new PV3D(valx,valy,valz);
}
//-----------------------------------------------------
void PV3D::rotateX(GLfloat angle){
	GLdouble newX=getX();
	GLdouble newY=getY()*cos(angle)-getZ()*sin(angle);
	GLdouble newZ=getY()*sin(angle)+getZ()*cos(angle);
	setXYZ(newX,newY,newZ);
}
void PV3D::rotateY(GLfloat angle){
	GLdouble newX=getZ()*sin(angle)+getX()*cos(angle);
	GLdouble newY=getY();
	GLdouble newZ=getZ()*cos(angle)-getX()*sin(angle);
	setXYZ(newX,newY,newZ);
}
void PV3D::rotateZ(GLfloat angle){
	GLdouble newX=getX()*cos(angle)-getY()*sin(angle);
	GLdouble newY=getX()*sin(angle)+getY()*cos(angle);
	GLdouble newZ=getZ();
	setXYZ(newX,newY,newZ);
}
