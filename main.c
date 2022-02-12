#include "main.h"



int main(){


	int feld[X][Y] = {0};
    
    clear();
    
    printf("---------------------------------------\n");
    printf("\n");
    printf("********* Herzlich Willkommen *********\n");
    printf("\n");
    printf("---------------------------------------\n");
    
    printf("        P R E S S    E N T E R\n");
    printf("\n");
    printf("********** Drücken Sie Enter **********\n");
    
    char c1;
    c1=getchar();
    clear();
    
    printf("\n");
	printf("\n");
	spielfeld(feld);
	printf("\n");
	printf("\n");
	
    while(!gewonnen(s2,feld)){
        
        int x = 0;
        do{
			printf("Wählen einer Reihe zwischen 1 und 7: \n");
			scanf("%d", &x);
        }while(setzen(x-1, s1, feld));
        
        clear();
		if(gewonnen(s1, feld)){
			printf("\n");
			printf("\n");
			printf("Computer hat gewonnen.\n");
			return 0;
		}
		int m = move(feld);
		printf("Der Computer setzt in Reihe: %i\n", m+1);
		setzen(m, s2, feld);
       
		printf("\n");
		printf("\n");
		spielfeld(feld);
		printf("\n");
		printf("\n");
    }
    
    printf("Sie haben gewonnen.\n");
	return 0;
}
