#ifndef ENEMY_H
#define ENEMY_H

#include "game.h"
#include "ausgabe.h"

int move(int player, int enemy, int difficulty, int feld[X][Y]);
int winzturn(int player, int enemy, int z, int feld[X][Y]);
int randturn(int player, int enemy, int feld[X][Y]);
void copyfeld(int f1[X][Y], int f2[X][Y]);

#endif
