#include "enemy.h"

int testfeld[X][Y] = {0};

int move(int feld[X][Y]){
	copyfeld(feld, testfeld);
	
	for(int i = 0; i < X; i++){
		
	}
	
}

void copyfeld(int f1[X][Y], int f2[X][Y]){
	for(int x = 0; x < X; x++){
		for(int y = 0; y < Y; y++){
			f2[x][y] = f1[x][y];
		}
	}

}
