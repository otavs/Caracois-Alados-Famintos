#include "comida.h"

Comida::Comida(){
	this->x = 0;
    this->y = 0;
    this->velocidade = 0;
    this->altura = 0;
    this->largura = 0;

	// this->tipo = aleatorio(0, 3);
	this->tipo = hotdog;
	
    if(tipo == chocolate)
        imagem = al_load_bitmap("chocolate.png");
    else if(tipo == sushi)
        imagem = al_load_bitmap("sushi.png");
    else if(tipo == pizza)
        imagem = al_load_bitmap("pizza.png");
    else if(tipo == hotdog)
        imagem = al_load_bitmap("hotdog.png");

}

Comida::Comida(int x, int y, int velocidade, int altura, int largura){
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;
    this->altura = altura;
    this->largura = largura;

    this->tipo = aleatorio(0, 3); // aleatório!
	this->tipo = hotdog;

    if(tipo == chocolate)
        imagem = al_load_bitmap("chocolate.png");
    else if(tipo == sushi)
        imagem = al_load_bitmap("sushi.png");
    else if(tipo == pizza)
        imagem = al_load_bitmap("pizza.png");
    else if(tipo == hotdog){
        imagem = al_load_bitmap("hotdog.png");
    }
}

Comida::~Comida(){
	al_destroy_bitmap(imagem);
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
void Comida::setTipo(int tipo){
	this->tipo = tipo;
	if(tipo == chocolate)
        imagem = al_load_bitmap("chocolate.png");
    else if(tipo == sushi)
        imagem = al_load_bitmap("sushi.png");
    else if(tipo == pizza)
        imagem = al_load_bitmap("pizza.png");
    else if(tipo == hotdog)
        imagem = al_load_bitmap("hotdog.png");
}


