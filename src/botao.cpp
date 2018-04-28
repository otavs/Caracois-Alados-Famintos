#include "botao.h"

Botao::Botao(){
	
}

Botao::Botao(int x, int y, string endereco){
	this->x = x;
	this->y = y;
	this->selecionado = false;
	imagem = al_load_bitmap(endereco.c_str());
	this->largura = al_get_bitmap_width(imagem);
	this->altura = al_get_bitmap_height(imagem);
}

Botao::~Botao(){
	
}

void Botao::atualiza(int mouseX, int mouseY){
	if(mouseX > x-largura/2 && mouseX < x+largura/2
	&& mouseY > y-altura/2 && mouseY < y+altura/2)
		selecionado = true;
	else
		selecionado = false;
}

bool Botao::estaSelecionado(){
	if(selecionado)
		return true;
	return false;
}

void Botao::desenhar(){
	if(!selecionado){
		al_draw_scaled_bitmap(imagem, 0, 0, largura, altura, x-largura/2, y-altura/2, largura, altura, 0);
	}else{
		al_draw_scaled_bitmap(imagem, 0, 0, largura, altura, (x-largura/2)-5, (y-altura/2)-5, largura+10, altura+10, 0);
	}
	
}

