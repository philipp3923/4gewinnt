CC = gcc -Wall -lm

Objektdateien = main.o game.o
Programm = 4gewinnt

$(Programm): $(Objektdateien)
	$(CC) -o $@ $^


main.o : main.c main.h
	$(CC) -c $@ $^
	
game.o : game.c game.h
	$(CC) -c $@ $^



	
all: clean $(Programm) neat

clean:
	rm $(Objektdateien) $(Programm) -f

neat:
	rm $(Objektdateien) -f

run:
	./4gewinnt
