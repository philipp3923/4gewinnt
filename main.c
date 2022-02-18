#include <stdio.h>

#include "main.h"


int main(){
	
	int feld[X][Y] = {0};
    int difficulty = 3;
	
	#if DEBUG
	printf("DEBUG MODE\n");
	int dfeld[X][Y] = {
		{3, 1, 3, 3, 3, 2},
		{3, 3, 3, 3, 3, 1},
		{3, 3, 3, 1, 3, 1},
		{3, 3, 3, 3, 1, 2},
		{3, 3, 3, 3, 3, 2},
		{3, 3, 3, 3, 3, 3},
		{3, 3, 0, 0, 0, 0}
	};
	
	int feld1[X][Y] = {
		{1, 1, 2, 2, 1, 0},
		{1, 2, 1, 2, 0, 0},
		{1, 2, 0, 0, 0, 0},
		{2, 2, 2, 1, 1, 0},
		{1, 1, 2, 2, 2, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0}
	};
	
	int feld2[X][Y] = {
		{1, 1, 1, 2, 1, 0},
		{2, 2, 1, 1, 1, 2},
		{2, 1, 1, 0, 0, 0},
		{1, 2, 2, 2, 1, 2},
		{2, 0, 0, 0, 0, 0},
		{2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0}
	};
	copyfeld(dfeld, feld);
	
	//printf("Gewonnen: %i\n", gewonnen(1,dfeld));
	//spielfeld(dfeld);
	#endif
    
    #if !(DEBUG)
    clear();
    #endif

    
    printf("---------------------------------------\n");
    printf("\n");
    printf("+++++++++++++ Vier Gewinnt ++++++++++++\n");
    printf("\n");
    printf("---------------------------------------\n");
    printf("\n");
    printf("********* V I E L  S P A S S **********\n");
    printf("\n");
	
    while(!gewonnen(s2,feld)){
        if(voll(feld)){
			printf("\n\n");
			spielfeld(feld);
			printf("\n\n");
			printf("Untentschieden.\n");
			return 0;
		}
        int x = 0;
        do{
			printf("Wählen einer Reihe zwischen 1 und 7: ");
			scanf("%d", &x);
			

			int c;
			while ((c = getchar()) != '\n' && c != EOF);
        
        }while(setzen(--x, s1, feld));
        
        #if !(DEBUG)
        clear();
        #endif
        
        printf("Spieler setzt in Reihe: %i", x+1);
        printf("\n\n");
		spielfeld_h(feld, x, highestelement(x, feld));
		printf("\n\n");
        
		if(gewonnen(s1, feld)){
			printf("\n\n");
			spielfeld_h(feld, x, highestelement(x, feld));
			printf("\n\n");
			printf("Sie haben gewonnen.\n");
			return 0;
		}
		if(voll(feld)){
			printf("\n\n");
			spielfeld(feld);
			printf("\n\n");
			printf("Untentschieden.\n");
			return 0;
		}
		x = move(PLAYER, ENEMY, difficulty, feld);
		setzen(x, s2, feld);
       
        printf("Gegner setzt in Reihe: %i", x+1);
		printf("\n\n");
		spielfeld_h(feld, x, highestelement(x, feld));
		printf("\n\n");
    }
    
    printf("Computer hat gewonnen.\n");
	return 0;
}
