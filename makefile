#makefile for game
#Emily Caggiano, CS3560, homework 5

all: game
	make archive
game: game.o main.o othello.o
	g++ -o game game.o main.o othello.o
main.o: main.cc game.h othello.h
	g++ -c main.cc
game.o: game.cc game.h
	g++ -c game.cc
othello.o: othello.cc othello.h
	g++ -c othello.cc
archive: archive.tgz
archive.tgz: makefile game.cc colors.h game.h othello.h piece.h main.cc othello.cc main.o game.o othello.o
	cd /home/ecaggian/cs3560_hw/hw5
	tar cvf archive.tar *
	gzip archive.tar
clean:
	-rm *.o
