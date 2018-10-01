// File: game.h (part of the namespace main_savitch_14)

#ifndef MAIN_SAVITCH_GAME
#define MAIN_SAVITCH_GAME
#include <queue> // Provides queue<string>
#include <string> // Provides string

/** The game.h file is the header file for the game.cc
 file which implements all functions that are in the game.h file
 besides the ones that have already been defined within the game.h file.
 The functions listed, within this file, allow us to the game to be played in whole
 while the board is also being displayed within the user's terminal. All files that are defined here also have their documentation here. All files that are defined in the game.cc file will be further documented in the game.cc file.
 */

namespace main_savitch_14
{
	class game
	{
		public:
		//ENUM TYPE
		enum who {HUMAN, NEUTRAL, COMPUTER}; // Possible game outcomes

		// CONSTRUCTOR and DESTRUCTOR
        /** The game constructor for this game, game(), allows the game
         to restart and have a set move_number as 0. This makes the board start at its original positions and have no moves already made for both the white and black pieces.
         */
		game() {move_number = 0;}
        virtual ~game() {}

		// PUBLIC MEMBER FUNCTIONS
		// The play function should not be overridden. IT plays one game, 
		// with the human player moving first and the computer second. 
		// The computer uses an alpha-beta look ahead algorithm to select its 
		// moves. The return value is the winner of the game (or NEUTRAL for
		// a tie).
        /** The play function allows the game to be played one time. It starts with the human player going first and the computer second. This function is further defined within the game.cc file.
         */
		who play(); 

		protected:
		//***********************************************
		// OPTIONAL VIRTUAL FUNCTIONS (overriding these is optional)
		//************************************************
		virtual void display_message(const std::string& message) const; 
		virtual std::string get_user_move() const;
        /** The last_mover function calculates which player made the last move.
         If it returns HUMAN, then the COMPUTER will make the next move. However, if the COMPUTER is returned then the HUMAN will make the next move.
         
         There are no parameters with this function.
         @return (move_number % 2) == 1? HUMAN : COMPUTER) will return the virtual enum value based off of who played last
         */
		virtual who last_mover() const
		{
			return (move_number % 2 == 1? HUMAN : COMPUTER);
		}
        /** the moves_completed functions allows the game to calculate how many
         moves have been made during the game. This returns an integer that holds the value of the number of moves that have been made.
         */
		virtual int moves_completed () const 
		{
			return move_number;
		}
        /** The next_mover function allows the computer to calculate who the next player in the game is. This does the opposite of last_mover function. If it returns the COMPUTER then the computer player will make the next move. However, if it returns HUMAN than the human will make the next move.
         */
		virtual who next_mover() const
		{
			return (move_number % 2 == 0 ? COMPUTER : HUMAN);
		}
        /** The opposite function takes in a who player function and tests to see if they
         are the opposite person than the player. If the player is COMPUTER than the HUMAN would be returned, if the player is HUMAN than the COMPUTER would be returned.
         
         @param player is the enum value of who is the current player.
         @return (player == HUMAN) ? COMPUTER : HUMAN - will return the player who is opposite the parameter
         */
		virtual who opposite(who player) const
		{
			return (player == HUMAN) ? COMPUTER : HUMAN;
		}
		virtual void countingPieces() = 0; 
		virtual void whosTurn() = 0; 
		virtual who winning() const; 

		//**************************************************
		// VIRTUAL FUNCTIONS THAT MUST BE OVERRIDDEND:
		// The oveverriding function shoudl call the original when it finishes.
		//***************************************************
		// Have the next player make a specified move:
		virtual void make_move(const std::string& move) { ++move_number;}
		// Restart the game from the beginning:
		virtual void restart() {move_number = 0;}

		//*****************************************************
		// Pure Virtual Functions
		//*****************************************************
		// (these must be provided for each derived class)
		// Return a pointer to a copy of myself: 
		virtual game* clone() const = 0; 
		// Compute all the moves that the next player can make: 
		virtual void compute_moves(std::queue<std::string>& moves) const = 0; 
		// Display the status of the current game: 
		virtual void display_status() const = 0; 
		// Evaluate a board position: 
		// NOTE: positive values are good for the computer. 
		virtual int evaluate() const = 0; 
		// Return true if the current game is finished:
		virtual bool is_game_over() const = 0; 
		// Return true if the given move is legal for the next player: 
		virtual bool is_legal(const std::string& move) const = 0; 

		int move_number; 				// Number of moves made so far

		private:

		// STATIC MEMBER CONSTANT
		static const int SEARCH_LEVELS = 4; // Levels for look-ahead evaluation 

		// PRIVATE FUNCTIONS (these are the same for every game) 
		int eval_with_lookahead(int look_ahead, int beat_this);
		void make_computer_move(); 
		void make_human_move(); 
	};
}

#endif
