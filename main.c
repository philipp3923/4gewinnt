#include "main.h"


int main(){

    int x;
    int spieler;
    
    clear();
    
    
    printf("---------------------------------------- \n");
    
    printf("********* Herzlich Willkommen ********* \n");
    
    printf("---------------------------------------- \n");
    
    printf("Drücken Sie unten auf Start um das Spiel zu starten: \n");
    printf("***************** Start ***************** \n");
    
	
    int feld[X][Y] = {0};
    
    while(!gewonnen(s1,feld) && !gewonnen(s2,feld)){
        
    printf("Geben Sie die X-Achse ein:");
        scanf("%d", x);
    setzen(x, s1, feld);
    
    feld_ausgabe(feld);
        
    printf("Der Computer spielt: \n");
    setzen(move(feld), s2, feld);
        
    feld_ausgabe(feld);
        
    }
    

//    printf("%i\n",gewonnen(spieler, feld));

}


void feld_ausgabe(int feld[X][Y]){
    for(int y = Y-1; y >= 0; y--){
        for(int x = 0; x < X; x++){
            printf("%i ", feld[x][y]);
        }
        printf("\n");
    }
}

void clear(){    
	system(CLEAR);
}
