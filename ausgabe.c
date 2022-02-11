#include "ausgabe.h"

void spielfeld(int feld[X][Y]){
    for(int y = Y-1; y >= 0; y--){
        for(int x = 0; x < X; x++){
            printf("%i ", feld[x][y]);
        }
        printf("\n");
    }
}


void clear(){    
	system(CLEAR);
}
