#include <stdio.h>
#include <stdlib.h>

#include "enemy.h"

int move(int player, int enemy, int difficulty, int feld[X][Y]){
	int test = -1;
	
	test = winzturn(player, enemy, difficulty, feld);
	if(test != -1){
		#if DEBUG
		printf("ZIELTURN\n");
		#endif
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
		//printf("WINTURN %i\n",z);
		#endif
		return test;
	}
	
	test = winturn(player, feld);
	if(test != -1){
		#if DEBUG
		//printf("LOOSETURN %i\n",z);
		#endif
		return test;
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
					test = winzturn(player, enemy, z-1, t2feld);
					copyfeld(feld, t2feld);
					setzen(test, enemy, t2feld);
					if(test != -1 && winturn(player, t2feld) == -1){
						#if DEBUG
						//printf("ERLAUBT\n");
						//spielfeld_h(t2feld, test, highestelement(test, t2feld));
						#endif
						tx[test]++;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < X; i++){
		#if DEBUG
		if(z ==3){
			printf(" %i ", tx[i]);
		}
		#endif
		if((test == -1 && tx[i] > 0) || (test != -1 && tx[i] > tx[test])){
			test = i;
		}
	}
	
	#if DEBUG
	if(z == 3){
		printf(" E%i, T%i\n", z, test);
	}
	#endif
	
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
				//printf("POS %i ", i);
				//spielfeld_h(t1feld, i, highestelement(i, t1feld));
				#endif
				return i;
			}
		}
	}	
	
	return -1;
}

int randturn(int player, int enemy, int feld[X][Y]){
	int c = rand() % X;
	
	int t1feld[X][Y] = {0};
	
	for(int i = c; i < X+c; i++){
		copyfeld(feld, t1feld);
		if(!setzen(i%X, enemy, t1feld) && winturn(player, t1feld) == -1){
			#if DEBUG
			printf("UNTAKTISCH 3\n");
			#endif
			return i%X;
		}
		//spielfeld(t1feld);
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
