#include <stdlib.h>
#include <stdio.h>

#define X 7
#define Y 6

char feld[X][Y] = {0}; 

int main(){
	
}


int setzen(unsigned int x,unsigned int y, char spieler){
	if(x < X && y < Y && feld[x][y] == 0){
		feld[x][y] = spieler;
		return 0;
	}
	return 1;
}
