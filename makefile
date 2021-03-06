#makefile for game
#Emily Caggiano, CS3560, homework 5

all: game
	make doc
game: game.o main.o othello.o
	g++ -o game game.o main.o othello.o
main.o: main.cc game.h othello.h
	g++ -c main.cc
game.o: game.cc game.h
	g++ -c game.cc
othello.o: othello.cc othello.h
	g++ -c othello.cc
doc: 
	doxygen Doxyfile
clean:
	-rm *.o
	-rm game
	-rm -rf html
	-rm -rf latex
