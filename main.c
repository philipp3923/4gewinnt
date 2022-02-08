#include "main.h"


int main(){
<<<<<<< HEAD
	int feld[X][Y] = {0};
	clear();
    setzen(5, s1, feld);
    setzen(4, s2, feld);
    setzen(4, s1, feld);
    setzen(3, s2, feld);
    setzen(3, s2, feld);
    setzen(3, s1, feld);
    setzen(2, s2, feld);
    setzen(2, s2, feld);
    setzen(2, s2, feld);
    setzen(2, s1, feld);
    feld_ausgabe(feld);
    printf("%i\n",gewonnen(s1, feld));
=======
    clear();
    
    
    printf("---------------------------------------- \n");
    
    printf("********* Herzlich Willkommen ********* \n");
    
    printf("---------------------------------------- \n");
    
    printf("Drücken Sie unten auf Start um das Spiel zu starten: \n");
    printf("***************** Start ***************** \n");
    
    
    
    
	
    setzen(5, s1);
    setzen(4, s2);
    setzen(4, s1);
    setzen(3, s2);
    setzen(3, s2);
    setzen(3, s1);
    setzen(2, s2);
    setzen(2, s2);
    setzen(2, s2);
    setzen(2, s1);
    feld_ausgabe();
    printf("%i\n",gewonnen(s1));
>>>>>>> 226bbf7 (anzige)
    
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
