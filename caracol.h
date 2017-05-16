#ifndef CARACOL_H
#define CARACOL_H

#include "includes.h"

class Caracol{

    int x, y, velocidade, altura, largura, contadorImg;
    ALLEGRO_BITMAP *imagem[2];
    int desejo;
    static ALLEGRO_BITMAP *img_c_hotdog[2], *img_c_pizza[2], *img_c_chocolate[2], *img_c_sushi[2];

    public:
    Caracol();
    Caracol(int x, int y, int velocidade, int altura, int largura);
    ~Caracol();
    void andar();
    void desenhar();

	int getX();
	void setX(int);
	int getY();
	void setY(int);
	int getVelocidade();
	void setVelocidade(int);
	int getAltura();
	void setAltura(int);
	int getLargura();
	void setLargura(int);
	int getDesejo();
	void setDesejo(int);
	
	static void inicializarImagens();
	
};

#endif
