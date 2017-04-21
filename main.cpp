#include <allegro5/allegro.h>

#include <iostream>

#include "fila.h"

using namespace std;

int main(){
	
	int largura = 960;
	int altura = 540;
	bool acabou = false;
	
	ALLEGRO_DISPLAY *tela = NULL;
	ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
	
	al_init();
	
	tela = al_create_display(largura, altura);
	
	filaEventos = al_create_event_queue();
	
	al_install_keyboard();
	
	al_register_event_source(filaEventos, al_get_display_event_source(tela));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	
	while(!acabou){
		
		ALLEGRO_EVENT evento;
		al_wait_for_event(filaEventos, &evento);
		
		if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			acabou = true;
		}
		else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
			switch(evento.keyboard.keycode){
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
