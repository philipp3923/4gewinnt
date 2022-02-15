#include <stdio.h>

#include "main.h"


int main(){

	int feld[X][Y] = {0};
    
    clear();
    
    printf("---------------------------------------\n");
    printf("\n");
    printf("********* Herzlich Willkommen *********\n");
    printf("\n");
    printf("---------------------------------------\n");
    printf("\n");
    printf("********* V I E L  S P A S S **********\n");
    printf("\n");
	
    while(!gewonnen(s2,feld)){
        
        int x = 0;
        do{
			printf("Wählen einer Reihe zwischen 1 und 7: ");
			scanf("%d", &x);
        }while(setzen(--x, s1, feld));
        
        #if !(DEBUG)
        clear();
        #endif
        
        printf("Spieler setzt in Reihe: %i", x+1);
        printf("\n");
		printf("\n");
        spielfeld_h(feld, x, highestelement(x, feld));
		printf("\n");
		printf("\n");
        
		if(gewonnen(s1, feld)){
			printf("\n");
			printf("\n");
			spielfeld(feld);
			printf("\n");
			printf("\n");
			printf("Sie haben gewonnen.\n");
			return 0;
		}
		x = move(feld);
		setzen(x, s2, feld);
       
        printf("Gegner setzt in Reihe: %i", x+1);
		printf("\n");
		printf("\n");
        spielfeld_h(feld, x, highestelement(x, feld));
		printf("\n");
		printf("\n");
    }
    
    printf("Computer hat gewonnen.\n");
	return 0;
}
