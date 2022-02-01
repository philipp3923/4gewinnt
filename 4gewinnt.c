#include <stdlib.h>
#include <stdio.h>

#define X 7
#define Y 6
#define s1 1
#define s2 2

unsigned int feld[X][Y] = {0}; 

int setzen(unsigned int x, unsigned int spieler);
int gewonnen(unsigned int spieler);
void feld_ausgabe();

int main(){
	setzen(1, s1);
	setzen(1, s1);
	setzen(0, s1);
	setzen(3, s1);
	setzen(4, s1);
	feld_ausgabe();
	printf("%i\n",gewonnen(s1));
}

/* Setzt den Char Spieler abhaengig von x auf das Spielfeld
 * Gibt 0 zurueck fuer erfolg, 1 fuer ungueltig
 */
int setzen(unsigned int x, unsigned int spieler){
	if(x < X){
		int y = 0;
		while(y < Y && feld[x][y] != 0){
				y++;
		}
		if(feld[x][y] == 0){
			feld[x][y] = spieler;
			return 0;
		}
	}
	return 1;
}

int gewonnen(unsigned int spieler){
	//check der y Spalten
	for(int x = 0; x < X; x++){		
		int count = 0;	
		for(int y = 0; y < Y; y++){
			printf("[%i, %i]: %i\n", x,y,feld[x][y]);
			if(feld[x][y] == spieler){
				count++;
			}else{
				break;
			}
		}
		if(count >= 4){
			return 1;
		}
	}
	
	return 0;
}

void feld_ausgabe(){
	for(int y = Y-1; y >= 0; y--){	
		for(int x = 0; x < X; x++){
			printf("%i ", feld[x][y]);
		}
		printf("\n");
	}
}
