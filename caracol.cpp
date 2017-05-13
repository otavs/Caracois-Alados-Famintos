#include "caracol.h"

Caracol::Caracol(){
	this->x = 0;
    this->y = 0;
    this->velocidade = 0;
    this->altura = 0;
    this->largura = 0;

	this->desejo = aleatorio(0, 3);
	
    if(desejo == chocolate)
        imagem = img_c_chocolate;
    else if(desejo == sushi)
        imagem = img_c_sushi;
    else if(desejo == pizza)
        imagem = img_c_pizza;
    else if(desejo == hotdog)
        imagem = img_c_hotdog;

}

Caracol::Caracol(int x, int y, int velocidade, int altura, int largura){
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;
    this->altura = altura;
    this->largura = largura;

    this->desejo = aleatorio(0, 3);
	
    if(desejo == chocolate)
        imagem = img_c_chocolate;
    else if(desejo == sushi)
        imagem = img_c_sushi;
    else if(desejo == pizza)
        imagem = img_c_pizza;
    else if(desejo == hotdog)
        imagem = img_c_hotdog;
        
}

Caracol::~Caracol(){
	
}
    

void Caracol::andar(){
    x += velocidade;
}

void Caracol::desenhar(){
    al_draw_bitmap(imagem, x-largura/2, y-altura/2, 0);
    //al_convert_mask_to_alpha(imagem, al_map_rgb(255, 0, 0));
}

// getters e setters:

int Caracol::getX(){
	return x;
}
void Caracol::setX(int x){
	this->x = x;
}

int Caracol::getY(){
	return y;
}
void Caracol::setY(int y){
	this->y = y;
}

int Caracol::getVelocidade(){
	return velocidade;
}
void Caracol::setVelocidade(int v){
	velocidade = v;
}

int Caracol::getAltura(){
	return altura;
}
void Caracol::setAltura(int a){
	altura = a;
}

int Caracol::getLargura(){
	return largura;
}
void Caracol::setLargura(int l){
	largura = l;
}

int Caracol::getDesejo(){
	return desejo;
}
void Caracol::setDesejo(int desejo){
	this->desejo = desejo;
	if(desejo == chocolate)
        imagem = img_c_chocolate;
    else if(desejo == sushi)
        imagem = img_c_sushi;
    else if(desejo == pizza)
        imagem = img_c_pizza;
    else if(desejo == hotdog)
        imagem = img_c_hotdog;
}

ALLEGRO_BITMAP* Caracol::getImagem(){
	return imagem;
}

ALLEGRO_BITMAP* Caracol::img_c_hotdog = NULL;
ALLEGRO_BITMAP* Caracol::img_c_sushi = NULL;
ALLEGRO_BITMAP* Caracol::img_c_pizza = NULL;
ALLEGRO_BITMAP* Caracol::img_c_chocolate = NULL;

void Caracol::inicializarImagens(){
	img_c_hotdog = al_load_bitmap("c_hotdog.png");
	img_c_pizza = al_load_bitmap("c_pizza.png");
	img_c_chocolate = al_load_bitmap("c_chocolate.png");
	img_c_sushi = al_load_bitmap("c_sushi.png");
}
