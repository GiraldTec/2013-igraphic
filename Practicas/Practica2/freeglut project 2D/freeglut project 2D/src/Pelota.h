#pragma once
#include "drawable.h"
#include "RegularPolygon.h"
class Pelota : public Drawable
{
private:
	RegularPolygon *forma;

public:
	Pelota(void);
	~Pelota(void);
	

	void render(void){ 
		forma->render();
		cout << "hago un render de mi pelotita" << endl;
	}
};

