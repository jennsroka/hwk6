// Brock Ferrell
// CS2401
// November 23, 2015
// Project7

/** The piece.h file creates a piece object that starts with no color. Once the piece is assigned a color it will remain black or white until the flip function is invoked by the game and othello classes. There is no further declarations of this file besides what is below.
 */

#ifndef PIECE_H
#define PIECE_H
enum color {black, white, blank};

class piece {
public:
    /** The piece constructor creates an object of the piece type with the color being primarily set to blank.
     
     There are no parameters or return values in this function. 
     */
	piece() {theColor = blank;}

    /** The function flip allows the piece to switch between black and white. If the original color is white then it will be "flipped" or set to black. But if the original color is black then it will be "flipped" or set to white.
        There are no paramenters or returns with this function.
     */
	void flip()
	{
		if (theColor == white) {
			theColor = black;
		}
		else if (theColor == black) {
			theColor = white;
		}
	}

    /** The is_blank function tests to see if the color of the piece object is blank.
     @return true or false based on whether the color of the piece is blank or colored.
     */
	bool is_blank()const {return theColor == blank;}
	bool is_black()const {return theColor == black;}
	bool is_white()const {return theColor == white;}
	void set_white() {theColor = white;}
	void set_black() {theColor = black;}

private:
	color theColor;

};

#endif

