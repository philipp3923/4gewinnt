#define X 7
#define Y 6

int setzen(int x, int spieler);
int gewonnen(int spieler);
int count_row(int x, int spieler);
int count_column(int y, int spieler);
int count_otherdiag(int x, int y, int spieler);
int count_maindiag(int x, int y, int spieler);

extern int feld[X][Y];
