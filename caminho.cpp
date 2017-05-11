#include "caminho.h"

Caminho::Caminho(int x0, int y0, int x1, int y1){
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
    filaCaracois = Fila<Caracol*>(500);
    filaComidas = Fila<Comida*>(500);
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

void Caminho::adicionarComida(){
	filaComidas.insere(new Comida(x1, y0+(y1-y0)/2, -5, 35, 25));
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
}

