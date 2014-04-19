//Carlos Giraldo
//Raquel Peces
#pragma once
class VerticeNormal{
	private:
		int indexV;
		int indexN;
	public:
		VerticeNormal(int v, int n);
		int getNormal();
		int getVertex();
		~VerticeNormal(void);
};

