CC = gcc -Wall -lm

4gewinnt: 4gewinnt.o game.o
	$(CC) -o $@ $^

4gewinnt.o : 4gewinnt.c
	$(CC) -c $@ $^
	
game.o : game.c
	$(CC) -c $@ $^

	
all: clean 4gewinnt run

clean:
	rm *.o 4gewinnt -f

run:
	./4gewinnt
