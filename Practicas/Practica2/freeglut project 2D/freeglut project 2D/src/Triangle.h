#pragma once
#include "drawable.h"
class Triangle : public Drawable
{
private:
	std::vector<Point*> *vertices;
public:
	Triangle(void);
	~Triangle(void);
	Triangle(vector<Point*> *v);
	

	void render(void){ cout << "hago un render de mi triangulo" << endl;}
};

