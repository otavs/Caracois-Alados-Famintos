#ifndef CARACOL_H
#define CARACOL_H

#include "includes.h"

class Caracol{

    int x, y, velocidade, altura, largura;
    ALLEGRO_BITMAP *imagem;
    int desejo;
    static ALLEGRO_BITMAP *img_c_hotdog, *img_c_pizza, *img_c_chocolate, *img_c_sushi;

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
	ALLEGRO_BITMAP* getImagem();
	
	static void inicializarImagens();
	
};

#endif
