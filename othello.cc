// Brock Ferrell
// CS2401
// November 23, 2015
// Project7

#include "othello.h"

namespace main_savitch_14
{
    /** @file
     The othello.cc file invokes all of the functions from the othello.h file
     **/

/** This function sets up the board display to have 8 columns and 8 rows with blue dividing lines
and two black pieces and two white pieces in the starting postitions.
It also outputs the prompt for the user to enter their move with a letter and a number
 **/
void Othello::display_status()const
{
  cout << BLUE << "   _______ _______ _______ _______ _______ _______ _______ _______\n";
  cout << BLUE << "   |  A  | |  B  | |  C  | |  D  | |  E  | |  F  | |  G  | |  H  |" << endl;

  for (int y = 0; y < 8; y++)
  {
    cout << BLUE << "  " << y + 1 << BLUE << '|' << RESET;
    for (int x = 0; x < 8; x++)
    {
      if (!gameBoard[x][y].is_black() && !gameBoard[x][y].is_white())
      {
        cout << B_RED << "     " << RESET;
      }
      else if (gameBoard[x][y].is_black())
      {
        cout << B_BLACK << WHITE << BOLD << "  B  " << RESET;
      }
      else if (gameBoard[x][y].is_white())
      {
        cout << B_WHITE << BLACK << BOLD << "  W  " << RESET;
      }

      if (x == 7)
      {
        cout << BLUE << "|     " << RESET;
      }
      else if (y < 8 && x <= 6)
      {
        cout << BLUE << "| |" << RESET;
      }
    }
    if (y < 8)
    {
      cout << BLUE << endl << "   |_____| |_____| |_____| |_____| |_____| |_____| |_____| |_____|\n";
    }
  }
  cout << "\nEnter a move in the format(letter,number) (Ex: A3)" << endl;
}

/**This function uses determines what color piece to place on the board, and how it will affect the other pieces 
around it. It also increments the move number by one to keep track of the number of moves that have been made 
by each player.**/
void Othello::make_move(const string& move) {

  int c, r;
  c = int(toupper(move[0]) - 'A');
  r = int(move[1] - '1');

  if (next_mover() == HUMAN) {
    if (move == "s" || move == "S") {
      make_skips();
    }

    else if (gameBoard[c + 1][r].is_white()) {
      do {
        gameBoard[c][r].set_black();
        c++;
      } while (gameBoard[c][r].is_white());
    }

    else if (gameBoard[c - 1][r].is_white()) {
      do {
        gameBoard[c][r].set_black();
        c--;
      } while (gameBoard[c][r].is_white());
    }

    else if (gameBoard[c][r + 1].is_white()) {
      do {
        gameBoard[c][r].set_black();
        r++;
      } while (gameBoard[c][r].is_white());
    }

    else if (gameBoard[c][r - 1].is_white()) {
      do {
        gameBoard[c][r].set_black();
        r--;
      } while (gameBoard[c][r].is_white());
    }

    else if (gameBoard[c + 1][r - 1].is_white()) {
      do {
        gameBoard[c][r].set_black();
        c++;
        r--;
      } while (gameBoard[c][r].is_white());
    }

    else if (gameBoard[c - 1][r - 1].is_white()) {
      do {
        gameBoard[c][r].set_black();
        c--;
        r--;
      } while (gameBoard[c][r].is_white());
    }

    else if (gameBoard[c - 1][r + 1].is_white()) {
      do {
        gameBoard[c][r].set_black();
        c--;
        r++;
      } while (gameBoard[c][r].is_white());
    }

    else if (gameBoard[c + 1][r + 1].is_white()) {
      do {
        gameBoard[c][r].set_black();
        c++;
        r++;
      } while (gameBoard[c][r].is_white());
    }
  }

  if (next_mover() == COMPUTER) {
    if (move == "s" || move == "S") {
      make_skips();
    }

    else if (gameBoard[c + 1][r].is_black()) {
      do {
        gameBoard[c][r].set_white();
        c++;
      } while (gameBoard[c][r].is_black());
    }

    else if (gameBoard[c - 1][r].is_black()) {
      do {
        gameBoard[c][r].set_white();
        c--;
      } while (gameBoard[c][r].is_black());
    }

    else if (gameBoard[c][r + 1].is_black()) {
      do {
        gameBoard[c][r].set_white();
        r++;
      } while (gameBoard[c][r].is_black());
    }

    else if (gameBoard[c][r - 1].is_black()) {
      do {
        gameBoard[c][r].set_white();
        r--;
      } while (gameBoard[c][r].is_black());
    }

    else if (gameBoard[c + 1][r - 1].is_black()) {
      do {
        gameBoard[c][r].set_white();
        c++;
        r--;
      } while (gameBoard[c][r].is_black());
    }

    else if (gameBoard[c - 1][r - 1].is_black()) {
      do {
        gameBoard[c][r].set_white();
        c--;
        r--;
      } while (gameBoard[c][r].is_black());
    }

    else if (gameBoard[c - 1][r + 1].is_black()) {
      do {
        gameBoard[c][r].set_white();
        c--;
        r++;
      } while (gameBoard[c][r].is_black());
    }

    else if (gameBoard[c + 1][r + 1].is_black()) {
      do {
        gameBoard[c][r].set_white();
        c++;
        r++;
      } while (gameBoard[c][r].is_black());
    }
    skips = 0;
  }
  move_number++;
}

/**This function resets the game and the board. It places two white pieces and two black pieces on the board in the 
appropriate position. It also sets the number of skips back to zero, the number of open spots to 60, and the number
of black and white pieces to 2.**/
void Othello::restart() {

  gameBoard[3][3].set_white();
  gameBoard[3][4].set_black();
  gameBoard[4][3].set_black();
  gameBoard[4][4].set_white();

  white = 2;
  black = 2;
  skips = 0;
  openSpots = 60;
}

/**This function checks to make sure that the move input by the player is legal. It checks if the board space is empty,
and also if the surrounding pieces are black or white. Based on these parameter, it returns a bool true or false
to determine if the move is legal or illegal. @param move is a constant string variable input by the user
@return is true or false depending on if the move is allowed or not**/
bool Othello::is_legal(const string& move)const {

  int c, r;
  c = int(toupper(move[0]) - 'A');
  r = int(move[1] - '1');

// BLACK'S TURN
  if (next_mover() == HUMAN) {
    if (gameBoard[c][r].is_blank()) {
      if (gameBoard[c][r - 1].is_white()) {
        do {
          r--;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());

      }

      if (gameBoard[c][r + 1].is_white()) {
        do {
          r++;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());

      }

      if (gameBoard[c + 1][r].is_white()) {
        do {
          c++;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());

      }

      if (gameBoard[c - 1][r].is_white()) {
        do {
          c--;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());
      }

      if (gameBoard[c + 1][r - 1].is_white()) {
        do {
          c++;
          r--;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());
      }

      if (gameBoard[c - 1][r - 1].is_white()) {
        do {
          c--;
          r--;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());
      }

      if (gameBoard[c - 1][r + 1].is_white()) {
        do {
          c--;
          r++;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());
      }

      if (gameBoard[c + 1][r + 1].is_white()) {
        do {
          c++;
          r++;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());
      }
    } else {
      return false;
    }
  }

// WHITE'S TURN
  if (next_mover() == COMPUTER) {
    if (gameBoard[c][r].is_blank()) {
      if (gameBoard[c][r - 1].is_white()) {
        do {
          r--;
          if (gameBoard[c][r].is_black()) {
            return true;
          }
        } while (gameBoard[c][r].is_white());
      }

      if (gameBoard[c][r + 1].is_black()) {
        do {
          r++;
          if (gameBoard[c][r].is_white()) {
            return true;
          }
        } while (gameBoard[c][r].is_black());
      }

      if (gameBoard[c + 1][r].is_black()) {
        do {
          c++;
          if (gameBoard[c][r].is_white()) {
            return true;
          }
        } while (gameBoard[c][r].is_black());
      }

      if (gameBoard[c - 1][r].is_black()) {
        do {
          c--;
          if (gameBoard[c][r].is_white()) {
            return true;
          }
        } while (gameBoard[c][r].is_black());
      }

      if (gameBoard[c + 1][r - 1].is_black()) {
        do {
          c++;
          r--;
          if (gameBoard[c][r].is_white()) {
            return true;
          }
        } while (gameBoard[c][r].is_black());

      }

      if (gameBoard[c - 1][r - 1].is_black()) {
        do {
          c--;
          r--;
          if (gameBoard[c][r].is_white()) {
            return true;
          }
        } while (gameBoard[c][r].is_black());
      }

      if (gameBoard[c - 1][r + 1].is_black()) {
        do {
          c--;
          r++;
          if (gameBoard[c][r].is_white()) {
            return true;
          }
        } while (gameBoard[c][r].is_black());
      }

      if (gameBoard[c + 1][r + 1].is_black()) {
        do {
          c++;
          r++;
          if (gameBoard[c][r].is_white()) {
            return true;
          }
        } while (gameBoard[c][r].is_black());
      }
    } else {
      return false;
    }
  }
}

/**this function counts the number of black and white pieces currently on the board. It also displays the total number
of moves that have been completed, the number of open spots, and the number of black and white pieces on the board.**/ 
void Othello::countingPieces() {

  int black = 0;
  int white = 0;

  for (int b = 0; b < 8; b++) {
    for (int a = 0; a < 8; a++) {
      if (gameBoard[a][b].is_white()) {
        white++;
      } else if (gameBoard[a][b].is_black()) {
        black++;
      }
    }
  }
  cout << "Total move: " << moves_completed() << endl;
  openSpots = 64 - (black + white);
  cout << "Black: "  << black << " ---" << " White: " << white;
  cout << endl;
}

/**This function determines if the game is over by determining if the number of skips is equal to two, if there are no 
open spots, or the number of the opposing pieces on the board is equal to zero. It then alerts the user that the game 
is over**/
bool Othello::is_game_over()const {

  if (skips == 2 || openSpots == 0 || black == 0 || white == 0) {
    cout << "The game is over.\n";
    return true;
  }
  else {
    return false;
  }
}

/**This function determines whos turn it is, based on who made the previous move. It then outputs this to the screen
to let the user know that it is their turn**/
void Othello::whosTurn() {
  if (next_mover() == COMPUTER) {
    cout << "\nWhite's Turn!" << endl;
  }

  if (next_mover() == HUMAN) {
    cout << "\nBlack's Turn!" << endl;
  }
}

/**This function counts the number of skips that have been done by the user**/
void Othello::make_skips() {
  skips++;
}

/**This function determines who is currently winning the game by determining if the number of white or black pieces is 
greater, and determining who is winning, or if it is a tie**/
game::who Othello::winning()const {

  if (black > white) {
    return last_mover();
  } else if (white > black) {
    return next_mover();
  } else {
    return NEUTRAL;
  }

}

/**This function evaluates the best move for the computer to do from the computed moves that it can make**/
int Othello::evaluate()const {

  int tmp_white = w;
  int tmp_black = b;

  if (gameBoard[0][0].is_white() || gameBoard[7][7].is_white() || gameBoard[0][7].is_white() || gameBoard[7][0].is_white()) {
    tmp_white += 5;
  }
  if (gameBoard[0][0].is_black() || gameBoard[7][7].is_black() || gameBoard[0][7].is_black() || gameBoard[7][0].is_black()) {
    tmp_black += 5;
  }

  if (b > w) {
    return b;
  } else if (w > b) {
    return w;
  }
}

/**This function computes the moves that are possible for the computer to make**/
void Othello::compute_moves(std::queue<std::string>& moves)const {
  string r;
  string c;
  string move;

  for (int i = 0; i < 8; i++) {
    c = i + 'A';
    for (int j = 0; j < 8; j++) {
      r = j + '1';
      move = c + r;
      if (is_legal(move)) {
        moves.push(move);
      }
      else {

      }
    }
  }
}

}
