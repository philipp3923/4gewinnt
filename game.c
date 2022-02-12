#include <stdlib.h>
#include <stdio.h>
#include "game.h"

/* Setzt den Char Spieler abhaengig von x auf das Spielfeld
 * Gibt 0 zurueck fuer erfolg, 1 fuer ungueltig
 */
int setzen(int x, int spieler, int feld[X][Y]){
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

int gewonnen(int spieler, int feld[X][Y]){
    //check der y Spalten
    for(int x = 0; x < X; x++){
        if(count_row(x, spieler, feld)){
            return 1;
        }
    }
    //check der x Zeilen
    for(int y = 0; y < Y; y++){
        if(count_column(y, spieler, feld)){
            return 1;
        }
    }
    
    //check der Diagonalen
    for(int y = Y-1; y >= 0; y--){
        int x = 0;
        if(count_otherdiag(x,y,spieler, feld)){
            return 1;
        }
    }
    for(int x = 0; x < X; x++){
        int y = Y-1;
        if(count_otherdiag(x,y,spieler, feld)){
            return 1;
        }
    }
    for(int y = 0; y < Y; y++){
        int x = 1;
        if(count_maindiag(x,y,spieler, feld)){
            return 1;
        }
    }
    for(int x = 0; x < X; x++){
        int y = 0;
        if(count_maindiag(x,y,spieler, feld)){
            return 1;
        }
    }
    
    
    return 0;
}

int count_row(int x, int spieler, int feld[X][Y]){
    int count = 0;
    for(int y = 0; y < Y; y++){
        if(feld[x][y] == spieler){
            count++;
        }else if(count >= 4){
			return 1;
		}else{
            count = 0;
        }
    }
    return 0;
}

int count_column(int y, int spieler, int feld[X][Y]){
    int count = 0;
    for(int x = 0; x < X; x++){
        if(feld[x][y] == spieler){
            count++;
        }
        else if(count >= 4){
			return 1;
		}else{
            count = 0;
        }
    }
    return 0;
}

int count_maindiag(int x, int y, int spieler, int feld[X][Y]){
    int count = 0;
    while(y < Y && x < X){
        if(feld[x][y] == spieler){
            count++;
        }else if(count >= 4){
			return 1;
		}else{
            count = 0;
        }
        y++;
        x++;
        }
        return 0;
}

int count_otherdiag(int x, int y, int spieler, int feld[X][Y]){
    int count = 0;
    while(y < Y && y >= 0 && x < X){
        if(feld[x][y] == spieler){
            count++;
        }else if(count >= 4){
			return 1;
		}else{
            count = 0;
        }
        y--;
        x++;
        }
    return 0;
}
