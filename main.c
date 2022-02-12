#include "main.h"



int main(){

    int x = 0;
    unsigned char c1;
    
    clear();
    
    
    printf("\n");
    printf("\n");
    
    printf("---------------------------------------- \n");
    printf("\n");
    printf("********* Herzlich Willkommen ********* \n");
    printf("\n");
    printf("---------------------------------------- \n");
    
    printf("Drücken Sie Enter um das Spiel zu starten: \n");
    printf("\n");
    printf("***************** Drücken Sie Enter ***************** \n");
    c1=getchar();
    clear();
    
    int feld[X][Y] = {0};
    void unten();
        
    while(!gewonnen(s1,feld) && !gewonnen(s2,feld)){
        do{
                printf("Zusetzende Reihe (zwischen 1 und 7): \n");
                scanf("%d", &x);
        }while(setzen(x-1, s1, feld));
        
        gewonnen(s1,feld);
        
        clear();

    {
		int m = move(feld);
		printf("Der Computer setzt in Reihe: %i\n", m+1);
		setzen(m, s2, feld);
    } 
       
    printf("\n");
    printf("\n");
    spielfeld(feld);
    printf("\n");
    printf("\n");
    }
    
    clear();
    
    if (gewonnen(s1,feld)==1) {
        printf("\n");
        printf("\n");
        spielfeld(feld);
        printf("\n");
        printf("\n");
        printf("**************************************************** \n");
        printf("***************** Du hast GEWONNEN ***************** \n");
        printf("**************************************************** \n");
        printf("\n");
    } else {
        printf("\n");
        printf("\n");
        spielfeld(feld);
        printf("\n");
        printf("\n");
        printf("**************************************************** \n");
        printf("************ Der Computer hat gewonnen ************* \n");
        printf("**************************************************** \n");
        printf("\n");
        
    }

}
