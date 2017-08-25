//---------------------------------------------------------------------------
// Program:  tic tac toe cli
// Name:     Bango
// Purpose:  This will be an implementation of a tic-tac-toe game.
//           This is a 2 player version of tic-tac-toe where 'X' goes first
//           followed by 'O'. When it is player 1's turn, (s)he places an 'X'
//           on a 3x3 grid; player 2 places an 'O' on the grid. The first
//           player to get 3 characters ('X' or 'O') in a row wins. If 
//           the board fills up with no winner, the game ends in a tie.
//---------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


// Global variables
const char BLANK = '-';
const char X = 'X';
const char O = 'O';
const char TIE = 'T';

//---------------------------------------------------------------------------
// Name: PlayX
// Parameters: game board 2d array
// Returns: void
// Purpose: Asks for a position and places an X on the grid at a position and returns true.
//          Also performs error checking
//---------------------------------------------------------------------------
void PlayX(char board[3][3], string player1)
{
	int row, col;

	// Ask for the position to place an X.
	cout << player1 << ": Enter the row followed by the column for your X (1-3), 0 to exit." << endl;
	cin >> row >> col;

	if (row == 0 || col == 0) {
		board[0][0] = '1';
	} else {

		while (row < 0 || row > 3 || col < 0 || col > 3 || (row >=1 && row <=3 && col >=1 && col <=3 && board[row-1][col-1] != BLANK))
		{
	   		cout << "\nNot a valid play. \n" << player1 << ": Enter the row followed by the column for your X (1-3), 0 to exit." << endl;
       		cin >> row;
			cin >> col;
		}


	   // set the position on the board to X
			board[row-1][col-1] = X;
	}
}

//---------------------------------------------------------------------------
// Name: PlayO
// Parameters:
// Returns:
// Purpose: Similar to the PlayX function
//---------------------------------------------------------------------------
void PlayO(char board[3][3], string player2)
{
	int row = 0;
	int col = 0;

	// Ask for the position to place an O.
	cout << player2 << ": Enter the row followed by the column for your O (1-3), 0 to exit." << endl;
	cin >> row >> col;

	 if (row == 0 || col == 0) {
		board[0][0] = '2';
	} else {

		while (row < 0 || row > 3 || col < 0 || col > 3 || (row >=1 && row <=3 && col >=1 && col <=3 && board[row-1][col-1] != BLANK))
		{
	   		cout << "\nNot a valid play. \n" << player2 << ": Enter the row followed by the column for your O (1-3), 0 to exit." << endl;
       		cin >> row >> col;
		}


	   // set the position on the board to X
			board[row-1][col-1] = O;
	}
}





//---------------------------------------------------------------------------
// Name:  CheckWinner
// Parameters: 2d array for game board
// Returns: char
// Purpose: return 'X' if x wins, 'O' if o wins, 'T' if
//          the game has ended in a tie.
//---------------------------------------------------------------------------

int CheckWinner(char board[3][3]) {

    int done = 0;
    int counter = 0;


    //check for a full board

    for (int i = 0; i < 3; i++)
  {
     for (int j = 0; j < 3; j++)
     {
         if (board[i][j] != BLANK) {
             counter++;
         }
     }
  }

	//check for a winner over all possible winning combinations, check for the exit code, 0, and define the variable 'done' which will tell main what it needs to know to output the right thing.

	if ((board[0][0] == X && board[0][1] == X && board[0][2] == X) || (board[1][0] == X && board[1][1] == X && board[1][2] == X) || (board[2][0] == X && board[2][1] == X && board[2][2] == X) || (board[0][0] == X && board[1][0] == X && board[2][0] == X) || (board[0][1] == X && board[1][1] == X && board[2][1] == X) || (board[0][2] == X && board[1][2] == X && board[2][2] == X) || (board[0][0] == X && board[1][1] == X && board[2][2] == X) || (board[0][2] == X && board[1][1] == X && board[2][0] == X)) {
		done = 1;
	} else if ((board[0][0] == O && board[0][1] == O && board[0][2] == O) || (board[1][0] == O && board[1][1] == O && board[1][2] == O) || (board[2][0] == O && board[2][1] == O && board[2][2] == O) || (board[0][0] == O && board[1][0] == O && board[2][0] == O) || (board[0][1] == O && board[1][1] == O && board[2][1] == O) || (board[0][2] == O && board[1][2] == O && board[2][2] == O) || (board[0][0] == O && board[1][1] == O && board[2][2] == O) || (board[0][2] == O && board[1][1] == O && board[2][0] == O)) {
		done = 2;
	} else if (board[0][0] == '1') {
		done = 4;
	} else if (board[0][0] == '2') {
		done = 5;
	} else if (counter == 9) {
		done = 3;
	}

    return done;

}

//---------------------------------------------------------------------------
// Name: ConfirmPlayAgain
// Parameters: none
// Returns: bool
// Purpose: Once the game has ended, this function asks if the player wants to
//          play again.
//---------------------------------------------------------------------------
bool ConfirmPlayAgain() {
    char x;
    bool again;
    cout << "Would you like to play again? (y/n) ";
        cin >> x;

        if (x == 'y' || x == 'Y') {
            again = true;
            cout << "\n=======================\n\n";
        } else {
            again = false;
        }

        return again;
}




//---------------------------------------------------------------------------
// Name: PrintBoard
// Parameters: 2d array game board
// Returns: void
// Purpose: Output current tic-tac-toe game board
//---------------------------------------------------------------------------
void PrintBoard(char board[3][3]) {


  for (int i = 0; i < 3; i++)
  {
     cout << "\n";
     for (int j = 0; j < 3; j++)
     {
         cout << board[i][j];
	 }
  }



}

//---------------------------------------------------------------------------
// Name: InitializeBoard
// Parameters: 2d array game board
// Returns: void
// Purpose: Sets tic-tac-toe game board to blank
//---------------------------------------------------------------------------
void InitializeBoard(char board[3][3])
{

  for (int i = 0; i < 3; i++)
  {
     for (int j = 0; j < 3; j++)
     {
	    board[i][j] = BLANK;
	 }
  }
}



// Main should be used to call the functions above to complete the tic-tac-toe game.
int main ()
{
    char board[3][3];
    bool again = true;
    char done = 0;
    int counter = 0;
    string player1;
    string player2;

	cout << " ________________________________" << endl;
	cout << "|                                |" << endl;
	cout << "| Logan B.A. Swango -- 010636621 |" << endl;
	cout << "|      Project 4: Tic Tac Toe    |" << endl;
	cout << "|            3/7/2013            |" << endl;
	cout << "|________________________________|" << endl;

    while (again) {

        InitializeBoard(board);

        cout << "Player 1, please enter your name: ";
                getline(cin, player1);

                while (!cin) {
                        cin.clear();
                        cout << "Invalid input Player 1, please enter your name: ";
                        getline(cin, player1);
                }
        cout << "Player 2, please enter your name: ";
                getline(cin, player2);

                while (!cin) {
                        cin.clear();
                        cout << "Invalid input Player 2, please enter your name: ";
                        getline(cin, player2);
                }




        while (done == 0) {

            PrintBoard(board);
            if (counter % 2 == 0) {
                cout << "\n";
                PlayX(board, player1);
            } else {
                cout << "\n";
                PlayO(board, player2);
            }
            counter++;
            done = CheckWinner(board);
                if (done == 1) {
                    PrintBoard(board);
                    cout << "\n" << player1 << " wins!" << endl;
                } else if (done == 2) {
                    PrintBoard(board);
                    cout << "\n" << player2 << " wins!" << endl;
                } else if (done == 3) {
                    PrintBoard(board);
                    cout << "\nThe match has ended in a tie!" << endl;
                } else if (done == 4) {
					cout << "\n" << player1 << " has forefeited the match!" << endl;
				} else if (done == 5) {
					cout << "\n" << player2 << " has forefeited the match!" << endl;
				}


            }

        if (done == 1 || done == 2 || done == 3 || done == 4 || done == 5) {
                again = ConfirmPlayAgain();
        }
        if (again) {
            done = 0;
            counter = 0;
        }
    }



return 0;
}
