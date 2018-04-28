#ifndef INCLUDES_H
#define INCLUDES_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <string>
#include <iostream>
#include <ctime>
#include <cmath>

#include "fila.h"
#include "caracol.h"
#include "comida.h"

using namespace std;

enum comida{chocolate, pizza, hotdog, sushi};

int aleatorio(int min, int max); // retorna um int aleatorio no intervalo de min ate max;

enum estados{menu, jogando, gameOver};

#endif
