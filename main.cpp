#include "includes.h"
#include "caminho.h"
#include "sal.h"
#include "botao.h"

int main(){

	int largura = 960;
	int altura = 540;
	bool acabou = false;
	int numCaminhos = 4;
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
	int recorde = 0;
	double sx = 1.0, sy = 1.0;

	int maxNumSais = 500;
	int numSais = 90;
	Sal **sais = new Sal*[maxNumSais];
	int limiteSaisX0 = 755;
	int limiteSaisX1 = 825;

	ALLEGRO_BITMAP *bg_game = NULL;
	ALLEGRO_BITMAP *bg_inicio = NULL;
	ALLEGRO_BITMAP *c_vida_1 = NULL;
	ALLEGRO_BITMAP *c_vida_2 = NULL;
	ALLEGRO_BITMAP *c_vida_3 = NULL;
	ALLEGRO_BITMAP *bg_fim = NULL;

	ALLEGRO_DISPLAY *tela = NULL;
	ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *arial24 = NULL;
	
	ALLEGRO_SAMPLE *musica = NULL;
	ALLEGRO_SAMPLE *erou = NULL;
	ALLEGRO_SAMPLE *comeu = NULL;
	ALLEGRO_SAMPLE *atirou = NULL;
	ALLEGRO_SAMPLE *morreu = NULL;

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
	al_install_audio();
	al_init_acodec_addon();
	
	cout << "ola! :D";
	al_reserve_samples(15);
	
	musica = al_load_sample("sons/musica.ogg");
	erou = al_load_sample("sons/erou.ogg");
	comeu = al_load_sample("sons/comeu.ogg");
	atirou = al_load_sample("sons/atirou.ogg");
	morreu = al_load_sample("sons/morreu.ogg");
	
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	tela = al_create_display(largura, altura); //cria a janela
	
	bg_game = al_load_bitmap("imagens/bg_jogo.png");
	bg_inicio = al_load_bitmap("imagens/bg_inicio.png");
	c_vida_1 = al_load_bitmap("imagens/c_vida_1.png");
	c_vida_2 = al_load_bitmap("imagens/c_vida_1.png");
	c_vida_3 = al_load_bitmap("imagens/c_vida_1.png");
	bg_fim = al_load_bitmap("imagens/bg_fim.png");
	
	timer = al_create_timer(1.0 / fps);
	
	arial24 = al_load_font("fontes/arial.ttf", 24, 0);
	
	filaEventos = al_create_event_queue(); // cria a fila de eventos

	// registra fontes de eventos na fila de eventos
	al_register_event_source(filaEventos, al_get_display_event_source(tela));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	al_register_event_source(filaEventos, al_get_timer_event_source(timer));
	al_register_event_source(filaEventos, al_get_mouse_event_source());

	Caracol::inicializarImagens();
	Comida::inicializarImagens();
	Caminho::inicializarImagens();

	Botao botaoJogar(largura/2, 340, "imagens/botao_jogar.png");
	Botao botaoSair(largura/2, 440, "imagens/botao_sair.png");

	Botao botaoMenu(largura/2, 365, "imagens/botao_menu.png");
	Botao botaoDesistir(largura/2, 450, "imagens/botao_desistir.png");

	for(int i = 0; i < maxNumSais; i++){ // inicializa ponteiros de sal
		sais[i] = NULL;
	}

	al_play_sample(musica, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

	al_start_timer(timer);

	// loop do jogo
	while(!acabou){
		ALLEGRO_EVENT evento; // cria variável de evento
		al_wait_for_event(filaEventos, &evento); // espera por algum evento

		if(estado == menu){
			if(evento.type == ALLEGRO_EVENT_TIMER){
                al_set_window_title(tela, "Caracóis Alados Famintos - Menu");
				botaoJogar.atualiza(mouseX, mouseY);
				botaoSair.atualiza(mouseX, mouseY);
				al_draw_bitmap(bg_inicio, 0, 0, 0);
				botaoJogar.desenhar();
				botaoSair.desenhar();
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
				mouseX = evento.mouse.x / sx;
				mouseY = evento.mouse.y / sy;
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
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_RESIZE){
				al_resize_display(tela, evento.display.width, evento.display.height);	
				sx = al_get_display_width(tela) / (float)largura;
				sy = al_get_display_height(tela) / (float)altura;
				ALLEGRO_TRANSFORM trans;
				al_identity_transform(&trans);
				al_scale_transform(&trans, sx, sy);
				al_use_transform(&trans);
			}
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
				acabou = true;
			}
		}
		else if(estado == jogando){
			if(evento.type == ALLEGRO_EVENT_TIMER){
                al_set_window_title(tela, "Caracóis Alados Famintos - Jogo");
				contador--;
				if(contador <= 0){ // cria novo caracol
					caminho[aleatorio(0,3)]->adicionarCaracol();
					contador = aleatorio(10, tempoSpawn);
				}
				if(vidas <= 0){
					if(pontos > recorde)
						recorde = pontos;
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
					caminho[i]->verificaColisoes(pontos, vidas, erou, comeu, morreu);
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
				al_draw_textf(arial24, al_map_rgb(255, 255, 255), 107, 467, 0, "%d", pontos);
				if(vidas == 3){
                    al_draw_bitmap(c_vida_1, 95, 487,0);
                    al_draw_bitmap(c_vida_2, 133, 487,0);
                    al_draw_bitmap(c_vida_3, 171, 487,0);
				}
				else if(vidas == 2){
                    al_draw_bitmap(c_vida_1, 95, 487,0);
                    al_draw_bitmap(c_vida_2, 133, 487,0);
				}
				else{
                    al_draw_bitmap(c_vida_1, 95, 487,0);
				}
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
				acabou = true;
			}
			else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
				switch(evento.keyboard.keycode){
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
						al_play_sample(atirou, 2, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						break;

					case ALLEGRO_KEY_W:
						caminho[seletor]->adicionarComida(pizza);
						al_play_sample(atirou, 2, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						break;

					case ALLEGRO_KEY_E:
						caminho[seletor]->adicionarComida(chocolate);
						al_play_sample(atirou, 2, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						break;

					case ALLEGRO_KEY_R:
						caminho[seletor]->adicionarComida(sushi);
						al_play_sample(atirou, 2, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						break;
				}
			}
			else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
				mouseX = evento.mouse.x / sx;
				mouseY = evento.mouse.y / sy;
			}
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_RESIZE){
				al_resize_display(tela, evento.display.width, evento.display.height);	
				sx = al_get_display_width(tela) / (float)largura;
				sy = al_get_display_height(tela) / (float)altura;
				ALLEGRO_TRANSFORM trans;
				al_identity_transform(&trans);
				al_scale_transform(&trans, sx, sy);
				al_use_transform(&trans);
			}
		}
		else if(estado == gameover){
			if(evento.type == ALLEGRO_EVENT_TIMER){
                al_set_window_title(tela, "Caracóis Alados Famintos - Fim de Jogo");
				botaoMenu.atualiza(mouseX, mouseY);
				botaoDesistir.atualiza(mouseX, mouseY);
				al_draw_bitmap(bg_fim,0,0,0);
				botaoMenu.desenhar();
				botaoDesistir.desenhar();
				al_draw_textf(arial24, al_map_rgb(0, 0, 0), (largura/2)-64, 268, 0, "PONTOS: %d", pontos);
				al_draw_textf(arial24, al_map_rgb(255, 255, 255), 40, altura - 50, 0, "RECORDE: %d", recorde);
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
				mouseX = evento.mouse.x / sx;
				mouseY = evento.mouse.y / sy;
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
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_RESIZE){
				al_resize_display(tela, evento.display.width, evento.display.height);	
				sx = al_get_display_width(tela) / (float)largura;
				sy = al_get_display_height(tela) / (float)altura;
				ALLEGRO_TRANSFORM trans;
				al_identity_transform(&trans);
				al_scale_transform(&trans, sx, sy);
				al_use_transform(&trans);
			}
			else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
				acabou = true;
			}
		}
		
	}
	
	return 0;

}
