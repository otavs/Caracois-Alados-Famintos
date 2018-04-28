#include "caminho.h"

Caminho::Caminho(int x0, int y0, int x1, int y1){
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
    filaCaracois = Fila<Caracol*>(200);
    filaComidas = Fila<Comida*>(200);
}

Caminho::~Caminho(){

}

// getters e setters:

int Caminho::getX0(){
    return x0;
}
void Caminho::setX0(int x0){
	this->x0 = x0;
}

int Caminho::getY0(){
    return y0;
}
void Caminho::setY0(int y0){
	this->y0 = y0;
}

int Caminho::getX1(){
    return x1;
}
void Caminho::setX1(int x1){
	this->x1 = x1;
}

int Caminho::getY1(){
    return y1;
}
void Caminho::setY1(int y1){
	this->y1 = y1;
}

void Caminho::adicionarCaracol(){
	filaCaracois.insere(new Caracol(x0, y0+(y1-y0)/2, 3, 102, 95));
}

void Caminho::removerCaracol(){
	delete filaCaracois.primeiroElem();
	filaCaracois.remove();
}

void Caminho::desenharCaracois(){
	for(int i = 0; i < filaCaracois.getNumElementos(); i++){
		filaCaracois[i]->desenhar();
	}
}

void Caminho::atualizarCaracois(){
	for(int i = 0; i < filaCaracois.getNumElementos(); i++){
		filaCaracois[i]->andar();
	}
}

void Caminho::adicionarComida(int tipo){
	filaComidas.insere(new Comida(x1-70, 8+y0+(y1-y0)/2, -13, 35, 25, tipo));
}

void Caminho::removerComida(){
	delete filaComidas.primeiroElem();
	filaComidas.remove();
}

void Caminho::desenharComidas(){
	for(int i = 0; i < filaComidas.getNumElementos(); i++){
		filaComidas[i]->desenhar();
	}
}

void Caminho::atualizarComidas(){
	for(int i = 0; i < filaComidas.getNumElementos(); i++){
		filaComidas[i]->andar();
	}
}

void Caminho::desenhar(){
	al_draw_rectangle(x0, y0, x1, y1, al_map_rgb(0, 255, 50), 2);
	al_draw_bitmap(img_alien, x1-100, y0 , 0);
}

void Caminho::verificaColisoes(int& pontos, int& vidas, ALLEGRO_SAMPLE *erou, ALLEGRO_SAMPLE *comeu, ALLEGRO_SAMPLE *morreu){
	if (!filaCaracois.vazia() && !filaComidas.vazia()){
		if(filaCaracois.primeiroElem()->getX() > filaComidas.primeiroElem()->getX()){
			if(filaCaracois.primeiroElem()->getDesejo() == filaComidas.primeiroElem()->getTipo()){
				al_play_sample(comeu, 2, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
				this->removerCaracol();
				this->removerComida();
				pontos++;
			}
			else{
				this->removerComida();
				al_play_sample(erou, 2, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
				vidas--;
			}
		}
	}
	if(!filaCaracois.vazia()){
		if(filaCaracois.primeiroElem()->getX()+filaCaracois.primeiroElem()->getLargura()/2 > 770){
			al_play_sample(morreu, 2, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
			this->removerCaracol();
			vidas--;
		}
	}
	if(!filaComidas.vazia()){
		if(filaComidas.primeiroElem()->getX() < 0)
			removerComida();
	}
}

ALLEGRO_BITMAP* Caminho::img_alien = NULL;

void Caminho::esvaziarFilaCaracois(){
	while(!filaCaracois.vazia())
		filaCaracois.remove();
}

void Caminho::esvaziarFilaComidas(){
	while(!filaComidas.vazia())
		filaComidas.remove();
}

void Caminho::inicializarImagens(){
	img_alien = al_load_bitmap("../res/img/alien.png");
}
