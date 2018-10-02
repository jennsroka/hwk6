// Brock Ferrell
// CS2401
// November 23, 2015
// Project7

/** @file
 The main.cc file invokes the an Othello object. This object is then restarted to create a new board
 and reset all of the counters to 0. After that the object is then run using the play() function. This function allows the game to start playing by invoking the game.h and game.cc files and further functions.
 **/

#include "game.h"
#include "othello.h"
using namespace main_savitch_14;


int main()
{
	Othello theGame;
	theGame.restart();
	theGame.play();
}
