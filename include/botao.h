#ifndef BOTAO_H
#define BOTAO_H

#include "includes.h"

class Botao{
	private:
		int x, y, largura, altura;
		bool selecionado;
		ALLEGRO_BITMAP *imagem;
	public:
		Botao();
		Botao(int, int, string);
		~Botao();
		void atualiza(int, int);
		bool estaSelecionado();
		void desenhar();
};

#endif


