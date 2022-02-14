#ifndef ENEMY_H
#define ENEMY_H

#include "game.h"
#include "ausgabe.h"

int move(int feld[X][Y]);
int win1turn(int player, int feld[X][Y], int testfeld[X][Y]);
int win2turn(int player, int enemy,int feld[X][Y], int testfeld[X][Y]);
void copyfeld(int f1[X][Y], int f2[X][Y]);

#endif
