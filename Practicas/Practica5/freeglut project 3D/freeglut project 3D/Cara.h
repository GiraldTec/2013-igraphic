#pragma once
#include "VerticeNormal.h"

#include <vector>
#include <iostream>

class Cara
{
public:
	int numV; // numero de vertices (Por defecto 4)

	std::vector<VerticeNormal*> indicesVN;
	
	Cara(void);
	~Cara(void);
};

