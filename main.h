#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "enemy.h"


#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

void feld_ausgabe(int feld[X][Y]);
void clear();
