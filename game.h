#define X 7
#define Y 6

int setzen(int x, int spieler, int feld[X][Y]);
int gewonnen(int spieler, int feld[X][Y]);

int count_row(int x, int spieler, int feld[X][Y]);
int count_column(int y, int spieler, int feld[X][Y]);
int count_otherdiag(int x, int y, int spieler, int feld[X][Y]);
int count_maindiag(int x, int y, int spieler, int feld[X][Y]);

