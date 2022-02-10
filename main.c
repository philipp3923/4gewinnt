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
        
    printf("Geben Sie die X-Achse ein:");
        scanf("%d", &x);
        do {
            if((x<1)||(x>6)){
                printf("Geben Sie eine Zahl zwischen 1 und 6 ein! \n");
                scanf("%d", &x);
            }
        } while ((x<1)||(x>6));
        
        setzen(x, s1, feld);
    
        clear();

    printf("Der Computer spielt: \n");
    setzen(move(feld), s2, feld);
        
    printf("\n");
    printf("\n");
    feld_ausgabe(feld);
    printf("\n");
    printf("\n");
    }
    
    clear();
    
    if (gewonnen(s1,feld)==1) {
        printf("\n");
        printf("\n");
        feld_ausgabe(feld);
        printf("\n");
        printf("\n");
        printf("**************************************************** \n");
        printf("***************** Du hast GEWONNEN ***************** \n");
        printf("**************************************************** \n");
        printf("\n");
    } else {
        printf("\n");
        printf("\n");
        feld_ausgabe(feld);
        printf("\n");
        printf("\n");
        printf("**************************************************** \n");
        printf("************ Der Computer hat gewonnen ************* \n");
        printf("**************************************************** \n");
        printf("\n");
        
    }

}


void feld_ausgabe(int feld[X][Y]){
    for(int y = Y-1; y >= 0; y--){
        for(int x = 1; x < X; x++){
            printf("%i ", feld[x][y]);
        }
        printf("\n");
    }
}


void clear(){    
	system(CLEAR);
}
