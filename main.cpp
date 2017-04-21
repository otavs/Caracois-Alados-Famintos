#include <allegro5/allegro.h>

#include <iostream>

#include "fila.h"

using namespace std;

int main(){
	
	// declaração de variáveis
	int largura = 960; // largura da tela
	int altura = 540; // altura da tela
	bool acabou = false; // variavel que controla o loop do jogo
	
	// declaração de variáveis da allegro
	ALLEGRO_DISPLAY *tela = NULL;
	ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
	
	al_init(); // inicializa a allegro
	
	tela = al_create_display(largura, altura); //cria a janela
	
	filaEventos = al_create_event_queue(); //cria a fila de eventos
	
	// inicialização dos addons
	al_install_keyboard();
	
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
					cout << "OLA ";
					break;
				default:
					cout << "ola ";
			}
		}
			
	}
	
	return 0;
	
}
