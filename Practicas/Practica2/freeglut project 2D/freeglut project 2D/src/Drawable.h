#pragma once

#include <vector>
#include <src/Point.h>

class Drawable
{
public:
	virtual void render(void) const = 0;
};

