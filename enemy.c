#include "enemy.h"

int move(int feld[X][Y]){
	int testfeld[X][Y] = {0};
	copyfeld(feld, testfeld);
	
	
	int test = win1turn(s2, feld, testfeld);
	if(test != -1){
		printf("Gewinn im nächsten Zug. Reihe: %i\n", test+1);
		return test;
	}
	
	test = win1turn(s1, feld, testfeld);
	if(test != -1){
		printf("Verloren im nächsten Zug. Reihe: %i\n", test+1);
		return test;
	}
	
	test = win2turn(s1, s2, feld, testfeld);
	if(test != -1){
		printf("Verloren in 2 Zügen. Reihe: %i\n", test+1);
		return test;
	}
	
	test = win2turn(s2, s1, feld, testfeld);
	if(test != -1){
		printf("Gewinn in 2 Zügen. Reihe: %i\n", test+1);
		return test;
	}
	
	
	//#TODO für KI Version 5: Falls keine 2 auf dem Feld: setze in die Mitte, sonst setzte in ein feld daneben.
	
	int c = 0;
	
	for(int x = 0; x < X; x++){
		for(int y = 0; y < Y; y++){
			if(testfeld[x][y] == s2){
				c++;
				if(x < X-1 && testfeld[x+1][y] == 0){
					printf("Zug rechts: %i\n", x+2);
					return x+1;
				}
				if(x > 0 && testfeld[x-1][y] == 0 ){
					printf("Zug links. Reihe: %i\n", x);
					return x-1;
				}
			}
		}
	}
	
	if(c == 0){
		if(testfeld[3][0] == 0){
			printf("Erster Zug. Reihe: 4\n");
			return 3;
		}else{
			
			printf("Erster Zug. Reihe: 5\n");
			return 4;
		}
	}
	
	for(int i = 0; i < X; i++){
		if(!setzen(i, s1, testfeld)){
			printf("Untaktischer Zug. Reihe: %i\n", i);
			return i;
		}
	}
	
	
	
	
	return test;
}

int win1turn(int player,int feld[X][Y], int testfeld[X][Y]){
	for(int i = 0; i < X; i++){
		setzen(i, player, testfeld);
		if(gewonnen(player, testfeld)){
			return i;
		}
		copyfeld(feld, testfeld);
	}
	return -1;
}

int win2turn(int player, int enemy,int feld[X][Y], int testfeld[X][Y]){
	for(int i = 0; i < X; i++){
		setzen(i, player, testfeld);
		for(int j = 0; j < X; j++){
			int testfeld2[X][Y] = {0};
			copyfeld(testfeld, testfeld2);
			setzen(j, enemy, testfeld2);
			for(int k = 0; k < X; k++){
				int testfeld3[X][Y] = {0};
				copyfeld(testfeld2, testfeld3);
				setzen(k, player, testfeld3);
				if(gewonnen(player, testfeld3)){
					return i;
				}
				copyfeld(testfeld2, testfeld3);
			}
			copyfeld(testfeld, testfeld2);
		}
		copyfeld(feld, testfeld);
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
