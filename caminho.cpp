#include "caminho.h"

Caminho::Caminho(int x0, int y0, int x1, int y1){
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
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
