#include <stdlib.h>
#include <stdio.h>

#define X 7
#define Y 6
#define s1 1
#define s2 2

unsigned int feld[X][Y] = {0}; 

int setzen(unsigned int x, unsigned int spieler);
int gewonnen(unsigned int spieler);
int count_row(int x, int spieler);
int count_column(int y, int spieler);
void feld_ausgabe();


int main(){
	setzen(1, s1);
	setzen(1, s1);
	setzen(1, s1);
	setzen(1, s1);
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
		if(count_row(x, spieler) >= 4){
			return 1;
		}
	}
	//check der x Zeilen
	for(int y = 0; y < Y; y++){		
		if(count_column(y, spieler) >= 4){
			return 1;
		}
	}
	
	//check der Diagonalen
	for(int i = 1; i < Y; i++){
		int x = 0;
		int y = i;
		int count = 0;
		while(y < Y && x < X){
			if(feld[x][y] == spieler){
				count++;
			}else if(count != 0){
				break;
			}
			y++;
			x++;
		}
		if(count >= 4){
			return 1;
		}
	}
	
	return 0;
}

int count_row(int x, int spieler){
	int count = 0;	
	for(int y = 0; y < Y; y++){
		if(feld[x][y] == spieler){
			count++;
		}else if(count != 0){
			return count;
		}
	}
	return count;
}

int count_column(int y, int spieler){
	int count = 0;	
	for(int x = 0; x < X; x++){
		if(feld[x][y] == spieler){
			count++;
		}else if(count != 0){
			return count;
		}
	}
	return count;
}





void feld_ausgabe(){
	for(int y = Y-1; y >= 0; y--){	
		for(int x = 0; x < X; x++){
			printf("%i ", feld[x][y]);
		}
		printf("\n");
	}
}
