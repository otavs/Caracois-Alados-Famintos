#ifndef COMIDA_H
#define COMIDA_H

#include "includes.h"

class Comida{

    int x, y, velocidade, altura, largura;
    ALLEGRO_BITMAP *imagem;
    int tipo;
    static ALLEGRO_BITMAP *img_hotdog, *img_pizza, *img_chocolate, *img_sushi;

    public:
    Comida();
    Comida(int x, int y, int velocidade, int altura, int largura, int tipo);
    ~Comida();
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
	int getTipo();
	void setTipo(int);
	static void inicializarImagens();

};

#endif
