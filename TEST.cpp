#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <string>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

enum comida{chocolate, pizza, hotdog, sushi};

int aleatorio(int min, int max); // retorna um int aleatório no intervalo de min até max;
template <class T>
class Fila{
	private:
		T *vetor;
		int primeiro, ultimo, tam, numElementos;
	public:
		Fila(int);				// construtor
		bool vazia();			// verifica se está vazia
		bool cheia();			// verifica se está cheia
		bool insere(T);			// insere elemento no fim
		bool remove();			// remove primeiro elemento
		T primeiroElem();		// retorna o valor do primeiro elemento
		int getTam();			// retorna o tamanho máximo da fila
		int getNumElementos();	// retorna o numero de elementos atualmente na fila
		T operator[](int);		// retorna o i-ésimo elemento da fila (começando por 0)
};

template <class T>
Fila<T>::Fila(int tam){
	this->vetor = new T[tam];
	this->primeiro = -1;
	this->ultimo = -1;
	this->tam = tam;
	this->numElementos = 0;
}

template <class T>
bool Fila<T>::vazia(){
	if(this->numElementos == 0)
		return true;
	return false;
}

template <class T>
bool Fila<T>::cheia(){
	if(this->numElementos == this->tam)
		return true;
	return false;
}

template <class T>
bool Fila<T>::insere(T elem){
	if(this->cheia())
		return false;
	if(this->primeiro == -1)
		this->primeiro++;
	this->ultimo++;
	if(this->ultimo == this->tam)
		this->ultimo = 0;
	this->vetor[this->ultimo] = elem;
	this->numElementos++;
	return true;
}

template <class T>
bool Fila<T>::remove(){
	if(this->vazia())
		return false;
	this->primeiro++;
	if(this->primeiro == this->tam)
		this->primeiro = 0;
	this->numElementos--;
	return true;
}

template <class T>
T Fila<T>::primeiroElem(){
	return this->vetor[this->primeiro];
}

template <class T>
int Fila<T>::getTam(){
	return this->tam;
}

template <class T>
int Fila<T>::getNumElementos(){
	return this->numElementos;
}

template <class T>
T Fila<T>::operator[](int i){
	if(i < this->tam-this->primeiro)
		return this->vetor[this->primeiro+i];
	else
		return this->vetor[i-(this->tam-this->primeiro)];
}

class Caracol{

    int x, y, velocidade, altura, largura;
    ALLEGRO_BITMAP *imagem;
    int desejo;

    public:
    Caracol();
    Caracol(int x, int y, int velocidade, int altura, int largura);
    ~Caracol();
    void andar();
    void desenhar();

	int getX();
	void setX(int);
	int getY();
	void setY(int);
	int getVelocidade();
	void setVelocidade(int);
	int getAltura();
	void setAltura(int);
	int getLargura();
	void setLargura(int);
	int getDesejo();
	void setDesejo(int);

};

Caracol::Caracol(){
	this->x = 7;
    this->y = 7;
    this->velocidade = 7;
    this->altura = 7;
    this->largura = 7;

    // this->desejo = aleatorio(0, 3); // aleatório!
	this->desejo = hotdog;
	
    if(desejo == chocolate)
        imagem = al_load_bitmap("c_chocolate.png");
    else if(desejo == sushi)
        imagem = al_load_bitmap("c_sushi.png");
    else if(desejo == pizza)
        imagem = al_load_bitmap("c_pizza.png");
    else if(desejo == hotdog){
        imagem = al_load_bitmap("c_hotdog.png");
    }
	cout << "CRIOU\n";
}

Caracol::Caracol(int x, int y, int velocidade, int altura, int largura){
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;
    this->altura = altura;
    this->largura = largura;

    // this->desejo = aleatorio(0, 3); // aleatório!
	this->desejo = hotdog;
	
    if(desejo == chocolate)
        imagem = al_load_bitmap("c_chocolate.png");
    else if(desejo == sushi)
        imagem = al_load_bitmap("c_sushi.png");
    else if(desejo == pizza)
        imagem = al_load_bitmap("c_pizza.png");
    else if(desejo == hotdog){
        imagem = al_load_bitmap("c_hotdog.png");
    }
}

Caracol::~Caracol(){
	al_destroy_bitmap(imagem);
	
}
    

void Caracol::andar(){
    x += velocidade;
}

void Caracol::desenhar(){
	if(!imagem) cout << "olA";
	if(imagem) cout << "olAA";
    al_draw_bitmap(imagem, x-largura/2, y-altura/2, 0);
    //al_convert_mask_to_alpha(imagem, al_map_rgb(255, 0, 0));
}

// getters e setters:

int Caracol::getX(){
	return x;
}
void Caracol::setX(int x){
	this->x = x;
}

int Caracol::getY(){
	return y;
}
void Caracol::setY(int y){
	this->y = y;
}

int Caracol::getVelocidade(){
	return velocidade;
}
void Caracol::setVelocidade(int v){
	velocidade = v;
}

int Caracol::getAltura(){
	return altura;
}
void Caracol::setAltura(int a){
	altura = a;
}

int Caracol::getLargura(){
	return largura;
}
void Caracol::setLargura(int l){
	largura = l;
}

int Caracol::getDesejo(){
	return desejo;
}
void Caracol::setDesejo(int desejo){
	this->desejo = desejo;
	if(desejo == chocolate)
        imagem = al_load_bitmap("c_chocolate.png");
    else if(desejo == sushi)
        imagem = al_load_bitmap("c_sushi.png");
    else if(desejo == pizza)
        imagem = al_load_bitmap("c_pizza.png");
    else if(desejo == hotdog)
        imagem = al_load_bitmap("c_hotdog.png");
}

int main(){

	// declaração de variáveis
	int largura = 960; // largura da tela
	int altura = 540; // altura da tela
	bool acabou = false; // variável que controla o loop do jogo
	int numCaminhos = 4; // número de caminhos
	int fps = 60;
	int numCaracois = 10;

	// declaração de variáveis da allegro
	ALLEGRO_DISPLAY *tela = NULL;
	ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
	ALLEGRO_TIMER *timer = NULL;

	srand(time(NULL)); // gera uma seed baseada na hora atual para gerar números aleatórios pela funcao rand() 

	al_init(); // inicializa a allegro
    al_install_keyboard();
	al_init_image_addon();

	tela = al_create_display(largura, altura); //cria a janela
	
	timer = al_create_timer(1.0 / fps);
	
	filaEventos = al_create_event_queue(); // cria a fila de eventos
 
	// registra fontes de eventos na fila de eventos
	al_register_event_source(filaEventos, al_get_display_event_source(tela));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	al_register_event_source(filaEventos, al_get_timer_event_source(timer));
	
	Fila<Caracol> fila(5);
	Caracol c(100, 100, 1, 100, 100);
	fila.insere(c);
	fila.insere(c);
	Caracol b = fila[1];
	cout << b.getAltura();
	
	while(1){
		;
	}
	

	return 0;

}

