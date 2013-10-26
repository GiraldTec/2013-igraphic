#pragma once

#include <gl/GL.h>

class pencil
{
public:
	pencil(void);
	~pencil(void);

	PV2D* pos;
	GLdouble dir;

	void moveTo(PV2D* p, bool draw);
	void turnTo(GLdouble a);
	void turn(GLdouble a);
	void forward(GLdouble dist, bool draw);

	PV2D* getPos();
	GLdouble getDir();
};

