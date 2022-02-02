#include <stdlib.h>
#include <stdio.h>

#define X 7
#define Y 6
#define s1 1
#define s2 2

int feld[X][Y] = {0};

int setzen(int x, int spieler);
int gewonnen(int spieler);
int count_row(int x, int spieler);
int count_column(int y, int spieler);
int count_otherdiag(int x, int y, int spieler);
int count_maindiag(int x, int y, int spieler);
void feld_ausgabe();
void clear();


int main(){
    setzen(5, s1);
    setzen(4, s2);
    setzen(4, s1);
    setzen(3, s2);
    setzen(3, s2);
    setzen(3, s1);
    setzen(2, s2);
    setzen(2, s2);
    setzen(2, s2);
    setzen(2, s1);
    feld_ausgabe();
    printf("%i\n",gewonnen(s1));
    
    clear();
    
}

/* Setzt den Char Spieler abhaengig von x auf das Spielfeld
 * Gibt 0 zurueck fuer erfolg, 1 fuer ungueltig
 */
int setzen(int x, int spieler){
    if(x < X && x >= 0){
        int y = 0;
        while(y < Y && feld[x][y] != 0){
                y++;
        }
        if(feld[x][y] == 0){
            feld[x][y] = spieler;
            return 0;
        }
    }
    return 1;
}

int gewonnen(int spieler){
    //check der y Spalten
    for(int x = 0; x < X; x++){
        if(count_row(x, spieler) >= 4){
            return 1;
        }
    }
    //check der x Zeilen
    for(int y = 0; y < Y; y++){
        if(count_column(y, spieler) >= 4){
            return 1;
        }
    }
    
    //check der Diagonalen
    for(int y = Y-1; y >= 0; y--){
        int x = 0;
        if(count_otherdiag(x,y,spieler) >= 4){
            return 1;
        }
    }
    for(int x = 0; x < X; x++){
        int y = Y-1;
        if(count_otherdiag(x,y,spieler) >= 4){
            return 1;
        }
    }
    for(int y = 0; y < Y; y++){
        int x = 0;
        if(count_maindiag(x,y,spieler) >= 4){
            return 1;
        }
    }
    for(int x = 0; x < X; x++){
        int y = 0;
        if(count_maindiag(x,y,spieler) >= 4){
            return 1;
        }
    }
    
    
    return 0;
}

int count_row(int x, int spieler){
    int count = 0;
    for(int y = 0; y < Y; y++){
        if(feld[x][y] == spieler){
            count++;
        }else if(count != 0){
            return count;
        }
    }
    return count;
}

int count_column(int y, int spieler){
    int count = 0;
    for(int x = 0; x < X; x++){
        if(feld[x][y] == spieler){
            count++;
        }else if(count != 0){
            return count;
        }
    }
    return count;
}

int count_maindiag(int x, int y, int spieler){
    int count = 0;
    while(y < Y && x < X){
        if(feld[x][y] == spieler){
            count++;
        }else if(count != 0){
            return count;
        }
        y++;
        x++;
        }
        return count;
}

int count_otherdiag(int x, int y, int spieler){
    int count = 0;
    printf("x:%i, y:%i\n", x, y);
    while(y < Y && y >= 0 && x < X){
        if(feld[x][y] == spieler){
            count++;
        }else if(count != 0){
            return count;
        }
        y--;
        x++;
        }
    return count;
}



void feld_ausgabe(){
    for(int y = Y-1; y >= 0; y--){
        for(int x = 0; x < X; x++){
            printf("%i ", feld[x][y]);
        }
        printf("\n");
    }
}

//konsole loeschen
void clear(){
    
   system("cls");
    
}
