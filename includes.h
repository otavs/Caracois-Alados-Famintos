#ifndef INCLUDES_H
#define INCLUDES_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
 
#include <string>
#include <iostream>
#include <ctime>
#include <cmath>

#include "fila.h"
#include "caracol.h"
#include "comida.h"

using namespace std;

enum comida{chocolate, pizza, hotdog, sushi};

int aleatorio(int min, int max); // retorna um int aleatório no intervalo de min até max;

enum estados{menu, jogando, gameover};

#endif
