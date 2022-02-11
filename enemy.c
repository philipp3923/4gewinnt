#include "enemy.h"

int move(int feld[X][Y]){
	int testfeld[X][Y] = {0};
	copyfeld(feld, testfeld);
	
	for(int i = 0; i < X; i++){
		setzen(i, s2, testfeld);
		if(gewonnen(s2, testfeld)){
			return i;
		}
		copyfeld(feld, testfeld);
	}
	
	for(int i = 0; i < X; i++){
		setzen(i, s1, testfeld);
		if(gewonnen(s1, testfeld)){
			return i;
		}
		copyfeld(feld, testfeld);
	}
	
	for(int i = 0; i < X; i++){
		if(!setzen(i, s1, testfeld)){
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
