#include "includes.h"
#include "caminho.h"
#include "botao.h"

int main(){

	// declaração de variáveis
	int largura = 960; // largura da tela
	int altura = 540; // altura da tela
	bool acabou = false; // variável que controla o loop do jogo
	int numCaminhos = 4; // número de caminhos
	int fps = 60;
	int numCaracois = 100;
	int tempoSpawn = 120;
	int contador = 120;
	int seletor = 0;
	int mouseX = 0, mouseY = 0;
	int estado = menu;

	// declaração de variáveis da allegro
	ALLEGRO_DISPLAY *tela = NULL;
	ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
	ALLEGRO_TIMER *timer = NULL;

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
	al_init_primitives_addon();
	al_install_mouse();

	tela = al_create_display(largura, altura); //cria a janela
	
	timer = al_create_timer(1.0 / fps);
	
	filaEventos = al_create_event_queue(); // cria a fila de eventos
 
	// registra fontes de eventos na fila de eventos
	al_register_event_source(filaEventos, al_get_display_event_source(tela));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	al_register_event_source(filaEventos, al_get_timer_event_source(timer));
	al_register_event_source(filaEventos, al_get_mouse_event_source());
	
	Caracol::inicializarImagens();
	Comida::inicializarImagens();
	Caminho::inicializarImagens();
	
	Botao botaoJogar(largura/2, 100, "botao_jogar.png");
	Botao botaoSair(largura/2, 200, "botao_sair.png");
	
	al_start_timer(timer); 
	
	// loop do jogo
	while(!acabou){
		ALLEGRO_EVENT evento; // cria variável de evento
		al_wait_for_event(filaEventos, &evento); // espera por algum evento
		
		if(estado == menu){
			if(evento.type == ALLEGRO_EVENT_TIMER){
				botaoJogar.atualiza(mouseX, mouseY);
				botaoSair.atualiza(mouseX, mouseY);
				botaoJogar.desenhar();
				botaoSair.desenhar();
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
				mouseX = evento.mouse.x;
				mouseY = evento.mouse.y;
			}
			else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if(evento.mouse.button == 1){
					if(botaoJogar.estaSelecionado()){
						estado = jogando;
					}
					if(botaoSair.estaSelecionado()){
						acabou = true;
					}
				}
			}
		}
		else if(estado == jogando){
			if(evento.type == ALLEGRO_EVENT_TIMER){
				contador--;
				if(contador == 0){
					caminho[aleatorio(0,3)]->adicionarCaracol();
					contador = aleatorio(0, tempoSpawn);
				}
				for(int i = 0; i < numCaminhos; i++){
					caminho[i]->atualizarCaracois();
					caminho[i]->atualizarComidas();
					caminho[i]->desenharCaracois();
					caminho[i]->desenharComidas();
				}
				
				for(int i = 0; i < numCaminhos; i++){
					caminho[i]->verificaColisoes();
				}
				
				al_draw_line(700, 0, 700, altura, al_map_rgb(255, 255, 255), 100);
				caminho[seletor]->desenhar();
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // evento disparado quando clicamos no X da tela
				acabou = true;
			}
			
			else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){ // evento disparado quando uma tecla é pressionada
				switch(evento.keyboard.keycode){ // verifica qual tecla foi pressionada
					case ALLEGRO_KEY_ESCAPE:
						acabou = true;
						break;
					case ALLEGRO_KEY_UP:
						seletor--;
						if(seletor < 0)
							seletor = 0;
						break;
					case ALLEGRO_KEY_DOWN:
						seletor++;
						if(seletor > numCaminhos-1)
							seletor = numCaminhos-1;
						break;
						
					case ALLEGRO_KEY_Q:
						caminho[seletor]->adicionarComida(hotdog);
						break;
						
					case ALLEGRO_KEY_W:
						caminho[seletor]->adicionarComida(pizza);
						break;
						
					case ALLEGRO_KEY_E:
						caminho[seletor]->adicionarComida(chocolate);
						break;
						
					case ALLEGRO_KEY_R:
						caminho[seletor]->adicionarComida(sushi);
						break;
				}
	
			}
		}
		else if(estado == gameover){
			
		}
		
		

	}

	return 0;

}






