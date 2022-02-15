#include <stdio.h>

#include "enemy.h"

int move(int player, int enemy, int difficulty, int feld[X][Y]){
	int test = -1;
	
	test = winzturn(player, enemy, difficulty, feld);
	test%=10;
	if(test != -1){
		return test;
	}
	
	test = randturn(player, enemy, feld);
	
	return test;
}

int winzturn(int player, int enemy, int z, int feld[X][Y]){
	if(z <= 0){
		return -1;
	}
	
	int test = winturn(enemy, feld);
	if(test != -1){
		#if DEBUG
		printf("WINTURN %i\n",z);
		#endif
		return test + z*10;
	}
	
	test = winturn(player, feld);
	if(test != -1){
		#if DEBUG
		printf("LOOSETURN %i\n",z);
		#endif
		return test + z*10;
	}
	
	int t1feld[X][Y] = {0};
	int t2feld[X][Y] = {0};
	
	int tx[X] = {0};
	
	for(int i = 0; i < X; i++){
		copyfeld(feld, t1feld);
		if(!setzen(i, enemy, t1feld)){
			for(int j = 0; j < X; j++){
				copyfeld(t1feld, t2feld);
				if(!setzen(j, player, t2feld)){
					int newtest = winzturn(player, enemy, z-1, t2feld);
					copyfeld(t1feld, t2feld);
					setzen(test%10, enemy, t2feld);
					if(newtest/10 > test/10 && newtest%10 != -1 && winturn(player, t2feld) == -1){
						test = newtest;
					}
				}
			}
		}
	}
	
	return test;
}

int winturn(int enemy, int feld[X][Y]){
	int t1feld[X][Y] = {0};
	for(int i = 0; i < X; i++){
		//frisches Ausgangsfeld intialisieren
		copyfeld(feld, t1feld);
		
		//Enemy setzen an i erfolgreich
		if(!setzen(i, enemy, t1feld)){
			
			//Enemy gewinnt an i
			if(gewonnen(enemy, t1feld)){
				#if DEBUG
				spielfeld_h(t1feld, i, highestelement(i, t1feld));
				#endif
				return i;
			}
		}
	}	
	
	return -1;
}

int randturn(int player, int enemy, int feld[X][Y]){
	int c = 0;
	
	int t1feld[X][Y] = {0};
	copyfeld(feld, t1feld);
	
	for(int x = 0; x < X; x++){
		if(highestelement(x, t1feld) == enemy){
			c++;
			if(!setzen(x+1, enemy, t1feld)){
				#if DEBUG
				printf("UNTAKTISCH 1\n");
				#endif
				return x+1;
			}
			if(!setzen(x-1, enemy, t1feld)){
				#if DEBUG
				printf("UNTAKTISCH 1\n");
				#endif
				return x-1;
			}
		}
	}
	
	if(c == 0){
		if(feld[3][0] == 0){
			#if DEBUG
			printf("UNTAKTISCH 2\n");
			#endif
			return 3;
		}else{
			#if DEBUG
			printf("UNTAKTISCH 2\n");
			#endif
			return 4;
		}
	}
	
	for(int i = 0; i < X; i++){
		if(!setzen(i, s1, t1feld)){
			#if DEBUG
			printf("UNTAKTISCH 3\n");
			#endif
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
