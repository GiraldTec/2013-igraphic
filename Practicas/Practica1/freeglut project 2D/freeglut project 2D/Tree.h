#pragma once

#include <vector>

#include <Square.h>

#include <iostream>
using namespace std;

class Tree
{
private:
	std::vector<vector<Square*>*> *estructura;
	//std::vector<Level*> niveles;

public:
	Tree(void);
	~Tree(void);
	bool grow(void);
	bool decrease(void);
	void init(void);
	void render(void);
};

