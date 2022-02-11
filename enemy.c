#include "enemy.h"

int move(int feld[X][Y]){
	int testfeld[X][Y] = {0};
	copyfeld(feld, testfeld);
	
	for(int i = 0; i < X; i++){
		setzen(i, s2, testfeld);
		if(gewonnen(s2, testfeld)){
			return i;
		}
		setzen(i, 0, testfeld);
	}
	
	for(int i = 0; i < X; i++){
		setzen(i, s2, testfeld);
		int f = 0;
		for(int j = 0; j < X; j++){
			setzen(j, s2, testfeld);
			if(gewonnen(s1, testfeld)){
				printf("Verloren durch\n\ts1: %i\n\ts2: %i\n",j,i);
				f++;
			}
			setzen(j, 0, testfeld);
		}
		if(f == 0){
			return i;
		}
		setzen(i, 0, testfeld);
	}
	return 0;
}

void copyfeld(int f1[X][Y], int f2[X][Y]){
	for(int x = 0; x < X; x++){
		for(int y = 0; y < Y; y++){
			f2[x][y] = f1[x][y];
		}
	}

}
