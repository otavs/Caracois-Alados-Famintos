#include "sal.h"

Sal::Sal(int minX, int maxX){
	x = aleatorio(minX, maxX);
	xInicial = x;
	y = 460;
	yInicial = y;
	raio = aleatorio(1, 4);
	vY = aleatorio(3, 8) * (-1);
	vX = aleatorio(1, 4) * 0.2;
	dx = aleatorio(0, 8);
}

void Sal::desenha(){
	al_draw_filled_circle(x, y, raio, al_map_rgb(255, 255, 255));
}

void Sal::move(){
	y += vY;
	x += vX;
	if(x > xInicial+dx){
		vX *= (-1);
	}
	if(x < xInicial-dx){
		vX *= (-1);
	}
}

int Sal::getY(){
	return y;
}
