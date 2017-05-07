#include "includes.h"

int aleatorio(int min, int max){
	return rand()%(max-min+1) + min;
}
