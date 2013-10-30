#pragma once

#include <vector>
#include "Square.h"

class Tree
{
private:
	std::vector<Square*> open, archive;

public:
	Tree(void);
	~Tree(void);
};

