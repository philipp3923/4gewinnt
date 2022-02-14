#include <stdlib.h>
#include <stdio.h>

#include "ausgabe.h"

void spielfeld(int feld[X][Y]){
    for(int y = Y-1; y >= 0; y--){
        for(int x = 0; x < X; x++){
            printf(" %c ", intToVisual(feld[x][y]));
        }
        printf("\n");
    }
    lastrow();
}



void spielfeld_h(int feld[X][Y], int hx, int hy){
	for(int y = Y-1; y >= 0; y--){
        for(int x = 0; x < X; x++){
			if(hx == x && hy == y){
				printf("[%c]", intToVisual(feld[x][y]));
			}else{
				printf(" %c ", intToVisual(feld[x][y]));
			}
        }
        printf("\n");
    }
    lastrow();
}

char intToVisual(int f){
	switch(f){
		case PLAYER: return VIS_PLAYER;
		case ENEMY: return VIS_ENEMY;
		case 0: return VIS_EMPTY;
		default: return VIS_ERROR;
	}
}

void lastrow(){
	for(int i=1; i <= X; i++){
		printf(".%i.", i);
	}
	printf("\n");
}

void clear(){    
	system(CLEAR);
}
