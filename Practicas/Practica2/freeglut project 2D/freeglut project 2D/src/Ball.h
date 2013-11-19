#pragma once
#include "DrawablePolygon.h"
class Ball : public DrawablePolygon
{
private:
	

public:
	Ball(void);
	~Ball(void);
	

	void render(void){ 
		cout << "hago un render de mi pelotita" << endl;
	}
};

