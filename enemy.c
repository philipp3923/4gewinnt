#include "enemy.h"

int move(int feld[X][Y]){
	int testfeld[X][Y] = {0};
	copyfeld(feld, testfeld);
	
	for(int i = 0; i < X; i++){
		setzen(i, s2, testfeld);
		if(gewonnen(s2, testfeld)){
			printf("Gewinn im nächsten Zug. Reihe: %i\n", i);
			return i;
		}
		copyfeld(feld, testfeld);
	}
	
	for(int i = 0; i < X; i++){
		setzen(i, s1, testfeld);
		if(gewonnen(s1, testfeld)){
			printf("Verloren im nächsten Zug. Reihe: %i\n", i);
			return i;
		}
		copyfeld(feld, testfeld);
	}
	
	for(int i = 0; i < X; i++){
		setzen(i, s1, testfeld);
		for(int j = 0; j < X; j++){
			int testfeld2[X][Y] = {0};
			copyfeld(testfeld, testfeld2);
			setzen(j, s2, testfeld2);
			for(int k = 0; k < X; k++){
				int testfeld3[X][Y] = {0};
				copyfeld(testfeld2, testfeld3);
				setzen(k, s1, testfeld3);
				if(gewonnen(s1, testfeld3)){
					printf("Verloren in 2 Zügen. Reihe: %i\n", k);
					return k;
				}
				copyfeld(testfeld2, testfeld3);
			}
			copyfeld(testfeld, testfeld2);
		}
		copyfeld(feld, testfeld);
	}
	
	for(int i = 0; i < X; i++){
		setzen(i, s2, testfeld);
		for(int j = 0; j < X; j++){
			int testfeld2[X][Y] = {0};
			copyfeld(testfeld, testfeld2);
			setzen(j, s1, testfeld2);
			for(int k = 0; k < X; k++){
				int testfeld3[X][Y] = {0};
				copyfeld(testfeld2, testfeld3);
				setzen(k, s2, testfeld3);
				if(gewonnen(s2, testfeld3)){
					printf("Gewinn in 2 Zügen. Reihe: %i\n", i);
					return i;
				}
				copyfeld(testfeld2, testfeld3);
			}
			copyfeld(testfeld, testfeld2);
		}
		copyfeld(feld, testfeld);
	}
	
	//#TODO für KI Version 5: Falls keine 2 auf dem Feld: setze in die Mitte, sonst setzte in ein feld daneben.
	
	
	
	for(int i = X/2; i < X; i++){
		if(!setzen(i, s1, testfeld)){
			printf("Random gesetzt\n");
			return i;
		}
	}
	
	
	
	
	return -1;
}

void copyfeld(int f1[X][Y], int f2[X][Y]){
	for(int x = 0; x < X; x++){
		for(int y = 0; y < Y; y++){
			f2[x][y] = f1[x][y];
		}
	}

}
