#include "Camara.h"


Camara::Camara(PV3D* eye, PV3D* look, PV3D* up)
{
	this->eye = eye;
	this->look = look;
	this->up = up;
	getCoordCam();
}


Camara::~Camara(void)
{
}

void Camara::getCoordCam()
{
	// n = (eye-look).normalizar()
	this->n = this->eye->subtraction(this->look);
	this->n->normalize();
	// u = (up*n).normalizar() 
	this->u = this->up->crossProduct(this->n);
	this->u->normalize();
	// v = n*u
	this->v = this->n->crossProduct(this->u);
}

void Camara::getMatriz()
{
	GLfloat* m= new GLfloat[16];
	m[0] = this->u->getX();
	m[1] = this->v->getX();
	m[2] = this->n->getX();
	m[3] = 0;

	m[4] = this->u->getY();
	m[5] = this->v->getY();
	m[6] = this->n->getY();
	m[7] = 0;

	m[8] = this->u->getZ();
	m[9] = this->v->getZ();
	m[10] = this->n->getZ();
	m[11] = 0;

	m[12] = -(this->eye->scalarProduct(this->u));
	m[13] = -(this->eye->scalarProduct(this->v));
	m[14] = -(this->eye->scalarProduct(this->n));
	m[15] = 0;

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glLoadMatrixf(m);

	delete[] m;
}

void Camara::fijarCam()
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(this->eye->getX(), this->eye->getY(), this->eye->getZ(), this->look->getX(), this->look->getY(), this->look->getZ(), this->up->getX(), this->up->getY(), this->up->getZ());
}

void Camara::roll(GLdouble alfa)
{
	PV3D* aux = u->clone();

	u->setX((aux->getX()*cos(alfa)) - (v->getX()*sin(alfa)));
	u->setY((aux->getY()*cos(alfa)) - (v->getY()*sin(alfa)));
	u->setZ((aux->getZ()*cos(alfa)) - (v->getZ()*sin(alfa)));

	v->setX((aux->getX())*sin(alfa) + (v->getX()*cos(alfa)));
	v->setY((aux->getY())*sin(alfa) + (v->getY()*cos(alfa)));
	v->setZ((aux->getZ())*sin(alfa) + (v->getZ()*cos(alfa)));

	getMatriz();
}

void Camara::yaw(GLdouble alfa)
{
	PV3D* aux = u->clone();

	u->setX((aux->getX()*cos(alfa)) + (n->getX()*sin(alfa)));
	u->setY((aux->getY()*cos(alfa)) + (n->getY()*sin(alfa)));
	u->setZ((aux->getZ()*cos(alfa)) + (n->getZ()*sin(alfa)));

	n->setX(-((aux->getX())*sin(alfa)) + (n->getX()*cos(alfa)));
	n->setY(-((aux->getY())*sin(alfa)) + (n->getY()*cos(alfa)));
	n->setZ(-((aux->getZ())*sin(alfa)) + (n->getZ()*cos(alfa)));

	getMatriz();
}

void Camara::pitch(GLdouble alfa)
{
	PV3D* aux = n->clone();

	n->setX((aux->getX()*cos(alfa)) + (v->getX()*sin(alfa)));
	n->setY((aux->getY()*cos(alfa)) + (v->getY()*sin(alfa)));
	n->setZ((aux->getZ()*cos(alfa)) + (v->getZ()*sin(alfa)));

	v->setX(-((aux->getX())*sin(alfa)) + (v->getX()*cos(alfa)));
	v->setY(-((aux->getY())*sin(alfa)) + (v->getY()*cos(alfa)));
	v->setZ(-((aux->getZ())*sin(alfa)) + (v->getZ()*cos(alfa)));

	getMatriz();
}

void Camara::desplazar(GLdouble x, GLdouble y, GLdouble z)
{
	this->eye->setX(this->eye->getX()+x);
	this->eye->setY(this->eye->getY()+y);
	this->eye->setZ(this->eye->getZ()+z);

	this->look->setX(this->look->getX()+x);
	this->look->setY(this->look->getY()+y);
	this->look->setY(this->look->getZ()+z);

	this->fijarCam();
}

void Camara::recorridoEje(GLdouble x, GLdouble y, GLdouble z)
{
	this->eye->setX(this->eye->getX()+x);
	this->eye->setY(this->eye->getY()+y);
	this->eye->setZ(this->eye->getZ()+z);
	
	this->fijarCam();
}

void Camara::giraX(GLdouble alfa)
{
	this->eye->setY(cos(alfa)*this->eye->getY()-sin(alfa)*this->eye->getZ());
	this->eye->setZ(sin(alfa)*this->eye->getY()+cos(alfa)*this->eye->getZ());

	this->fijarCam();
}

void Camara::giraY(GLdouble alfa)
{
	this->eye->setX(cos(alfa)*this->eye->getX()+sin(alfa)*this->eye->getZ());
	this->eye->setZ(-sin(alfa)*this->eye->getX()+cos(alfa)*this->eye->getZ());

	this->fijarCam();
}

void Camara::giraZ(GLdouble alfa)
{
	this->eye->setX(cos(alfa)*this->eye->getX()-sin(alfa)*this->eye->getY());
	this->eye->setY(sin(alfa)*this->eye->getX()+cos(alfa)*this->eye->getY());

	this->fijarCam();
}

void Camara::lateral()
{
	this->eye->setX(100);
	this->eye->setY(0);
	this->eye->setZ(0);

	this->up->setX(0);
	this->up->setY(1);
	this->up->setZ(0);

	this->fijarCam();
}

void Camara::frontal()
{
	this->eye->setX(0);
	this->eye->setY(0);
	this->eye->setZ(100);

	this->up->setX(0);
	this->up->setY(1);
	this->up->setZ(0);

	this->fijarCam();
}

void Camara::cenital()
{
	this->eye->setX(0);
	this->eye->setY(100);
	this->eye->setZ(0);

	this->up->setX(1);
	this->up->setY(0);
	this->up->setZ(0);

	this->fijarCam();
}

void Camara::esquina()
{
	this->eye->setX(100);
	this->eye->setY(100);
	this->eye->setZ(100);

	this->up->setX(0);
	this->up->setY(1);
	this->up->setZ(0);

	this->fijarCam();
}