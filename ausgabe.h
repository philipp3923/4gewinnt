#include <stdlib.h>
#include <stdio.h>
#include "game.h"

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

void spielfeld(int feld[X][Y]);
void clear();
