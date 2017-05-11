#ifndef CAMINHO_H
#define CAMINHO_H

#include "includes.h"

class Caminho{

    int x0, y0, x1, y1;
    Fila<Caracol*> filaCaracois;
    Fila<Comida*> filaComidas;

    public:
    Caminho(int x0, int y0, int x1, int y1);
    ~Caminho();
    int getX0();
    void setX0(int);
    int getY0();
    void setY0(int);
    int getX1();
    void setX1(int);
    int getY1();
    void setY1(int);
    
    void adicionarCaracol();
    void removerCaracol();
    void desenharCaracois();
    void atualizarCaracois();
    
    void adicionarComida();
    void removerComida();
    void desenharComidas();
    void atualizarComidas();

	void desenhar();
};

#endif
