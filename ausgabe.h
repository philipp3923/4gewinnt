#ifndef AUSGABE_H
#define AUSGABE_H

#include "game.h"

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

void spielfeld(int feld[X][Y]);
void spielfeld_h(int feld[X][Y], int hx, int hy);
char intToVisual(int f);
void lastrow();
void clear();

#endif
