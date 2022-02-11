CC = gcc -Wall -lm

Objektdateien = main.o game.o enemy.o ausgabe.o
Programm = 4gewinnt

$(Programm): $(Objektdateien)
	$(CC) -o $@ $^

main.o : main.c main.h
	$(CC) -c $^
	
game.o : game.c game.h
	$(CC) -c $^

enemy.o : enemy.c enemy.h
	$(CC) -c $^
	
ausgabe.o : ausgabe.c ausgabe.h
	$(CC) -c $^


	
all: clean $(Programm) neat run

mac: $(Programm) run

neat:
	rm $(Objektdateien) *.gch -f

clean:
	rm $(Objektdateien) *.gch $(Programm) -f

run:
	./4gewinnt
