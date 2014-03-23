#pragma once
class VerticeNormal
{
private:
	int indiceVertice, indiceNormal;

public:
	VerticeNormal(void);
	VerticeNormal(int iv, int in);
	~VerticeNormal(void){};

	int getIndiceVertice(){return this->indiceVertice;};
	int getIndiceNormal(){return this->indiceNormal;};
	void setIndiceVertice(int iv){this->indiceVertice = iv;};
	void setIndiceNormal(int in){this->indiceNormal = in;};
};

