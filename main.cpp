#include "includes.h"
#include "caminho.h"
#include "sal.h"
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
	int pontos = 0;
	int vidas = 3;
	int dificuldade = 0;
	
	int maxNumSais = 500;
	int numSais = 90;
	Sal **sais = new Sal*[maxNumSais];
	int limiteSaisX0 = 755;
	int limiteSaisX1 = 825;

	ALLEGRO_BITMAP *bg_game = NULL, *bg_inicio = NULL;

	// declaração de variáveis da allegro
	ALLEGRO_DISPLAY *tela = NULL;
	ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *arial24 = NULL;

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
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();

	tela = al_create_display(largura, altura); //cria a janela
	bg_game = al_load_bitmap("bg.png");
	bg_inicio = al_load_bitmap("bg.png");
	timer = al_create_timer(1.0 / fps);
	arial24 = al_load_font("fontes/arial.ttf", 24, NULL);
	
	filaEventos = al_create_event_queue(); // cria a fila de eventos
 
	// registra fontes de eventos na fila de eventos
	al_register_event_source(filaEventos, al_get_display_event_source(tela));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	al_register_event_source(filaEventos, al_get_timer_event_source(timer));
	al_register_event_source(filaEventos, al_get_mouse_event_source());
	
	Caracol::inicializarImagens();
	Comida::inicializarImagens();
	Caminho::inicializarImagens();
	
	Botao botaoJogar(largura/2, 350, "imagens/botao_jogar.png");
	Botao botaoSair(largura/2, 450, "imagens/botao_sair.png");
	
	Botao botaoMenu(largura/2, 100, "imagens/botao_menu.png");
	Botao botaoDesistir(largura/2, 200, "imagens/botao_desistir.png");
	
	bg_game = al_load_bitmap("imagens/bg_jogo.png");
	bg_inicio = al_load_bitmap("imagens/bg_inicio.png");
	
	for(int i = 0; i < maxNumSais; i++){
		sais[i] = NULL;
	}
	
	al_start_timer(timer);
	
	// loop do jogo
	while(!acabou){
		ALLEGRO_EVENT evento; // cria variável de evento
		al_wait_for_event(filaEventos, &evento); // espera por algum evento
		
		if(estado == menu){
			if(evento.type == ALLEGRO_EVENT_TIMER){
				botaoJogar.atualiza(mouseX, mouseY);
				botaoSair.atualiza(mouseX, mouseY);
				al_draw_bitmap(bg_inicio, 0, 0, 0);
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
						vidas = 3;
						pontos = 0;
						tempoSpawn = 120;
						dificuldade = 0;
						seletor = 0;
						for(int i = 0; i < numCaminhos; i++){
							caminho[i]->esvaziarFilaCaracois();
							caminho[i]->esvaziarFilaComidas();
						}
					}
					if(botaoSair.estaSelecionado()){
						acabou = true;
					}
				}
			}
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // evento disparado quando clicamos no X da tela
				acabou = true;
			}
		}
		else if(estado == jogando){
			cout << vidas << endl;
			if(evento.type == ALLEGRO_EVENT_TIMER){
				contador--;
				if(vidas <= 0){
					estado = gameover;
				}
				for(int i = 0; i < numSais; i++){ // cria novo sal
					if(sais[i] == NULL){
						sais[i] = new Sal(limiteSaisX0, limiteSaisX1);
						break;
					}
				}
				for(int i = 0; i < maxNumSais; i++){ // atualiza sais
					if(sais[i]!=NULL){
						sais[i]->move();
						if(sais[i]->getY() < 0){
							delete sais[i];
							sais[i] = NULL;
						}
					}
				}			
				if(contador <= 0){ // cria novo caracol
					caminho[aleatorio(0,3)]->adicionarCaracol();
					contador = aleatorio(10, tempoSpawn);
				}
				
				if(pontos == 10 && dificuldade == 0){
					tempoSpawn -= 15;
					dificuldade++;
				}
				if(pontos == 25 && dificuldade == 1){
					tempoSpawn -= 15;
					dificuldade++;
				}
				if(pontos == 50 && dificuldade == 2){
					tempoSpawn -= 15;
					dificuldade++;
				}
				if(pontos == 80 && dificuldade == 3){
					tempoSpawn -= 15;
					dificuldade++;
				}if(pontos == 150 && dificuldade == 4){
					tempoSpawn -= 15;
					dificuldade++;
				}
				
				
				for(int i = 0; i < numCaminhos; i++){ // atualiza caracois
					caminho[i]->atualizarCaracois();
					caminho[i]->atualizarComidas();
				}
				for(int i = 0; i < numCaminhos; i++){ // verifica colisoes
					caminho[i]->verificaColisoes(pontos, vidas);
				}
				al_draw_bitmap(bg_game, 0, 0, 0); // desenha background
				
				for(int i = 0; i < numCaminhos; i++){ // desenha caracois
					caminho[i]->desenharCaracois();
					caminho[i]->desenharComidas();
				}
				
				for(int i = 0; i < maxNumSais; i++){ // desenha sais
					if(sais[i]!=NULL)
						sais[i]->desenha();
				}
				caminho[seletor]->desenhar();
				al_draw_textf(arial24, al_map_rgb(255, 255, 255), 107, 467, NULL, "%d", pontos);
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
			else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
				mouseX = evento.mouse.x;
				mouseY = evento.mouse.y;
			}
		}
		else if(estado == gameover){
			if(evento.type == ALLEGRO_EVENT_TIMER){
				botaoMenu.atualiza(mouseX, mouseY);
				botaoDesistir.atualiza(mouseX, mouseY);
				botaoMenu.desenhar();
				botaoDesistir.desenhar();
				al_draw_textf(arial24, al_map_rgb(255, 255, 255), largura/2, 473, NULL, "PONTOS: %d", pontos);
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
				mouseX = evento.mouse.x;
				mouseY = evento.mouse.y;
			}
			else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if(evento.mouse.button == 1){
					if(botaoMenu.estaSelecionado()){
						estado = menu;
					}
					if(botaoDesistir.estaSelecionado()){
						acabou = true;
					}
				}
			}
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // evento disparado quando clicamos no X da tela
				acabou = true;
			}
			
		}
		
		

	}

	return 0;

}



