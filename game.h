#ifndef GAME_H
#define GAME_H

#define X 7
#define Y 6
#define PLAYER 1
#define ENEMY 2
#define DEBUG 0

#define VIS_PLAYER 'P'
#define VIS_ENEMY 'G'
#define VIS_EMPTY '.'
#define VIS_ERROR '!'

#define COL_ENEMY "\x1b[31m"
#define COL_PLAYER "\x1b[34m"
#define COL_DEFAULT "\x1b[0m"

#define s1 PLAYER
#define s2 ENEMY

int setzen(int x, int spieler, int feld[X][Y]);
int highestelement(int x, int feld[X][Y]);
int gewonnen(int spieler, int feld[X][Y]);

int count_row(int x, int spieler, int feld[X][Y]);
int count_column(int y, int spieler, int feld[X][Y]);
int count_otherdiag(int x, int y, int spieler, int feld[X][Y]);
int count_maindiag(int x, int y, int spieler, int feld[X][Y]);

#endif
