#include <stdlib.h>
#include <stdio.h>

#include "ausgabe.h"

void spielfeld(int feld[X][Y]){
    for(int y = Y-1; y >= 0; y--){
        for(int x = 0; x < X; x++){
            printf(" %i ", feld[x][y]);
        }
        printf("\n");
    }
}

void spielfeld_h(int feld[X][Y], int hx, int hy){
	for(int y = Y-1; y >= 0; y--){
        for(int x = 0; x < X; x++){
			if(hx == x && hy == y){
				printf("[%i]", feld[x][y]);
			}else{
				printf(" %i ", feld[x][y]);
			}
        }
        printf("\n");
    }
}
void clear(){    
	system(CLEAR);
}
