#include "comida.h"

Comida::Comida(){
	this->x = 0;
    this->y = 0;
    this->velocidade = 0;
    this->altura = 0;
    this->largura = 0;

	this->tipo = aleatorio(0, 3);
	
    if(tipo == chocolate)
        imagem = img_chocolate;
    else if(tipo == sushi)
        imagem = img_sushi;
    else if(tipo == pizza)
        imagem = img_pizza;
    else if(tipo == hotdog)
        imagem = img_hotdog;

}

Comida::Comida(int x, int y, int velocidade, int altura, int largura, int tipo){
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;
    this->altura = altura;
    this->largura = largura;

    this->tipo = tipo;

    if(tipo == chocolate)
        imagem = img_chocolate;
    else if(tipo == sushi)
        imagem = img_sushi;
    else if(tipo == pizza)
        imagem = img_pizza;
    else if(tipo == hotdog)
        imagem = img_hotdog;
}

Comida::~Comida(){
	
}

void Comida::andar(){
    x += velocidade;
}

void Comida::desenhar(){
    al_draw_bitmap(imagem, x-largura/2, y-altura/2, 0);
}

// getters e setters:

int Comida::getX(){
	return x;
}
void Comida::setX(int x){
	this->x = x;
}

int Comida::getY(){
	return y;
}
void Comida::setY(int y){
	this->y = y;
}

int Comida::getVelocidade(){
	return velocidade;
}
void Comida::setVelocidade(int v){
	velocidade = v;
}

int Comida::getAltura(){
	return altura;
}
void Comida::setAltura(int a){
	altura = a;
}

int Comida::getLargura(){
	return largura;
}
void Comida::setLargura(int l){
	largura = l;
}

int Comida::getTipo(){
	return tipo;
}
ALLEGRO_BITMAP* Comida::img_hotdog = NULL;
ALLEGRO_BITMAP* Comida::img_sushi = NULL;
ALLEGRO_BITMAP* Comida::img_pizza = NULL;
ALLEGRO_BITMAP* Comida::img_chocolate = NULL;


void Comida::setTipo(int tipo){
	this->tipo = tipo;
	if(tipo == chocolate)
        imagem = img_chocolate;
    else if(tipo == sushi)
        imagem = img_sushi;
    else if(tipo == pizza)
        imagem = img_pizza;
    else if(tipo == hotdog)
        imagem = img_hotdog;
}

void Comida::inicializarImagens(){
	img_hotdog = al_load_bitmap("hotdog.png");
	img_pizza = al_load_bitmap("pizza.png");
	img_chocolate = al_load_bitmap("chocolate.png");
	img_sushi = al_load_bitmap("sushi.png");
}
