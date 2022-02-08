#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "main.h"
#define s1 1
#define s2 2

#define LINUX

#ifdef WINDOWS
    void clear(){
        system("cls");
    }
#elif LINUX
    void clear(){
        system("clr");
    }
#else
    void clear(){
        
    }
#endif

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


void feld_ausgabe(){
    for(int y = Y-1; y >= 0; y--){
        for(int x = 0; x < X; x++){
            printf("%i ", feld[x][y]);
        }
        printf("\n");
    }
}

