#pragma once
#include "TAfin.h"
class Objeto3D
{
private:
	TAfin *ta;

public:
	Objeto3D(void);
	~Objeto3D(void);

	virtual void init()=0;

	virtual void dibuja()=0;
};

