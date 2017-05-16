#include "caracol.h"

Caracol::Caracol(){
	this->x = 0;
    this->y = 0;
    this->velocidade = 0;
    this->altura = 0;
    this->largura = 0;
    this->contadorImg = 0;

	this->desejo = aleatorio(0, 3);
	
    if(desejo == chocolate){
    	imagem[0] = img_c_chocolate[0];
    	imagem[1] = img_c_chocolate[1];
	}
    else if(desejo == sushi){
    	imagem[0] = img_c_sushi[0];
    	imagem[1] = img_c_sushi[1];
	}
    else if(desejo == pizza){
    	imagem[0] = img_c_pizza[0];
    	imagem[1] = img_c_pizza[1];
	}
	else if(desejo == hotdog){
    	imagem[0] = img_c_hotdog[0];
    	imagem[1] = img_c_hotdog[1];
	}

}

Caracol::Caracol(int x, int y, int velocidade, int altura, int largura){
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;
    this->altura = altura;
    this->largura = largura;
    this->contadorImg = aleatorio(0, 1);

    this->desejo = aleatorio(0, 3);
	
    if(desejo == chocolate){
    	imagem[0] = img_c_chocolate[0];
    	imagem[1] = img_c_chocolate[1];
	}
    else if(desejo == sushi){
    	imagem[0] = img_c_sushi[0];
    	imagem[1] = img_c_sushi[1];
	}
    else if(desejo == pizza){
    	imagem[0] = img_c_pizza[0];
    	imagem[1] = img_c_pizza[1];
	}
	else if(desejo == hotdog){
    	imagem[0] = img_c_hotdog[0];
    	imagem[1] = img_c_hotdog[1];
	}
        
}

Caracol::~Caracol(){
	
}
    

void Caracol::andar(){
    x += velocidade;
}

void Caracol::desenhar(){
	contadorImg++;
	if(contadorImg >= 10)
		contadorImg = 0;
    al_draw_bitmap(imagem[contadorImg/5], x-largura/2, y-altura/2, 0);
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
	if(desejo == chocolate){
    	imagem[0] = img_c_chocolate[0];
    	imagem[1] = img_c_chocolate[1];
	}
    else if(desejo == sushi){
    	imagem[0] = img_c_sushi[0];
    	imagem[1] = img_c_sushi[1];
	}
    else if(desejo == pizza){
    	imagem[0] = img_c_pizza[0];
    	imagem[1] = img_c_pizza[1];
	}
	else if(desejo == hotdog){
    	imagem[0] = img_c_hotdog[0];
    	imagem[1] = img_c_hotdog[1];
	}
}

ALLEGRO_BITMAP* Caracol::img_c_hotdog[2];
ALLEGRO_BITMAP* Caracol::img_c_sushi[2];
ALLEGRO_BITMAP* Caracol::img_c_chocolate[2];
ALLEGRO_BITMAP* Caracol::img_c_pizza[2];

void Caracol::inicializarImagens(){
	img_c_hotdog[0] = al_load_bitmap("imagens/c_hotdog0.png");
	img_c_hotdog[1] = al_load_bitmap("imagens/c_hotdog1.png");
	img_c_sushi[0] = al_load_bitmap("imagens/c_sushi0.png");
	img_c_sushi[1] = al_load_bitmap("imagens/c_sushi1.png");
	img_c_chocolate[0] = al_load_bitmap("imagens/c_chocolate0.png");
	img_c_chocolate[1] = al_load_bitmap("imagens/c_chocolate1.png");
	img_c_pizza[0] = al_load_bitmap("imagens/c_pizza0.png");
	img_c_pizza[1] = al_load_bitmap("imagens/c_pizza1.png");
}
