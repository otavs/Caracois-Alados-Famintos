#include "fila.h"
#include "caminho.h"
#include "caracol.h"

#include "includes.h"

int main(){

	// declaração de variáveis
	int largura = 960; // largura da tela
	int altura = 540; // altura da tela
	bool acabou = false; // variável que controla o loop do jogo
	int numCaminhos = 4; // número de caminhos

	// declaração de variáveis da allegro
	ALLEGRO_DISPLAY *tela = NULL;
	ALLEGRO_EVENT_QUEUE *filaEventos = NULL;

	// criação dos 4 caminhos
	Caminho *caminho[numCaminhos];
	caminho[0] = new Caminho(0, 0, largura, 108);
	caminho[1] = new Caminho(0, 108, largura, 216);
	caminho[2] = new Caminho(0, 216, largura, 324);
	caminho[3] = new Caminho(0, 324, largura, 432);

	srand(time(NULL)); // gera uma seed baseada na hora atual para gerar números aleatórios pela funcao rand() 

	al_init(); // inicializa a allegro
    al_install_keyboard();
	al_init_image_addon();

	tela = al_create_display(largura, altura); //cria a janela
	
	filaEventos = al_create_event_queue(); // cria a fila de eventos
 
	// registra fontes de eventos na fila de eventos
	al_register_event_source(filaEventos, al_get_display_event_source(tela));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());

	// loop do jogo
	while(!acabou){

		ALLEGRO_EVENT evento; // cria variável de evento
		al_wait_for_event(filaEventos, &evento); // espera por algum evento

		if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // evento disparado quando clicamos no X da tela
			acabou = true;
		}
		else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){ // evento disparado quando uma tecla é pressionada
			switch(evento.keyboard.keycode){ // verifica qual tecla foi pressionada
				case ALLEGRO_KEY_ESCAPE:
					acabou = true;
					break;
				case ALLEGRO_KEY_UP:
					
					Caracol c(100, 100, 2, 100, 100);
					c.setDesejo(hotdog); // o desejo é gerado aleatoriamente no construtor, mas aqui setamos como hotdog apenas para testar a imagem
					c.desenhar();
					al_flip_display();
					
					break;

			}
		}

	}

	return 0;

}
