#ifndef SAL_H
#define SAL_H

#include "includes.h"

class Sal{
	private:
		double x, y, xInicial, yInicial, raio, vX, vY, dx;
	public:
		Sal(int minX, int maxX);
		void desenha();
		void move();
		int getY();
};

#endif
