 #include <iostream>
 #include "mosquito.h"
 #include "cajun.h"

    using namespace std;

	enum StatusType {ALICE_WIN, BOB_WIN, IN_PROGRESS};

 struct Unit
 {
	char occupant;
	//' ' (BLANK unoccupied) OR one of the four Cajuns named as E,S,N,W OR
	//one fo the nine Mosquitoes named as 0,1,...,8 OR
	//an Obstacle (O) or Tabasco (T)

	int tabasco;
	//0 or 1 or  .. or M, where M is the maximum strength of the Tabasco
 
 };


 int const MAX_ROWS = 8;
 int const MAX_COL = 8;
 int const MAX_TAB_SQUARES = 3;
 int const MAX_TAB_STREN = 2;
 int const MAX_MOSQ = 9;
 int const MAX_OBST = 6;

 class GameBoard
 {
   
   //Description: Contains the representation of the room 
   //and provides operations such as to display the board,
   //update the board, verify if a move is legal, and 
   //determine the status of the game.

 private:

	

     StatusType CurrentStatus;
     //{ALICE_WIN, BOB_WIN, IN_PROGRESS}

	 int MaxRounds;
	 //Maximum number of rounds

	 int currRound;

	 
 public:

	  Unit Board[MAX_ROWS][MAX_COL];
     //will represent the game board. The game board starts empty.
	 
	 GameBoard();// CONSTRUCTOR
     //initializes all units
	 //Pre: none
	 //Post: the gameBoard is initialized with the four Cajuns
	 //located at the four corners. For the 8 by 8 board, see the
	 //example below:

   /*SuuuuuuW
     uuuuuuuu
     uuuuuuuu
     uuuuuuuu
     uuuuuuuu
     uuuuuuuu
     uuuuuuuu
     EuuuuuuN
   */


     //X is the cajun that are facing E
     //Y is the cajun that are facing N
     //Z is the cajun that are facing W
     //W is the cajun that are facing S

	 
	 void DisplayInfo(Cajun, Cajun, Cajun, Cajun, Mosquito[]);
     //Description: It displays the locations of Cajuns and Mosquitoes
	 //Pre: There is at least one Cajun or Mosquito on board
	 //Post: Return the locations of all Cajuns and Mosquitoes on board.

	 /*
     Eg. A sample output will look like:

     Cajuns:

     X: (1,2) Y: (3,4) Z: (5,6)  W: (7,8)

     Mosquitoes:

     0: (1,4) 1: (3,2) 2: (0,0)  8: (8,8)

     Current Round number: 45

     Maximum number of rounds: 100
     */
     
	 //Note: Some mosquitoes may have died and their info. will NOT be
     //displayed. 
 

     void DisplayBoard();
	 //Description: displays the current gameBoard
	 //Pre: output is empty
	 //Post: output = the gameBoard is displayed on the screen, using
	 //the convention as desribed in assignment #2 (See the example
	 //with the following figure in assignment 2)

     /*
	 SuuuuOOuuW 
     uuumuuOuuu 
     umuuuuOmuu 
     uuuuumuuuO 
     EuuOOOOuuN
	 */

     StatusType getCurrentStatus(Mosquito[]);
	 //Description: Returns the status of the game; that is, 
	 //it examines the board to determine if the game is over with a Alice win, 
	 //a Bob win or if the game is in progress.
	 //Pre: none
	 //Post: function value = status code (ALICE_WIN, BOB_WIN, IN_PROGRESS)


	 bool IsLegalAliceMove(Cajun);
	 //Description: checks to see if the cajun can move
	 //Pre: A holds a legal position on board
	 //Post: TRUE is returned if the move M is feasible
	 //FALSE is returned if the move is not feasible
	 //Note: Cajuns can always turn. This function only check if the Cajun 
	 //can move 1 unit along the direction it faces.


	 bool IsLegalBobMove(Mosquito[], int, direction);
	 //Description: checks to see if the mosquito can move
	 //Pre: index is a valid array index of the mosquito in question
	 //and the mosquito is on the board.
	 //Post: TRUE is returned if the move is feasible
	 //FALSE is returned if the move is not feasible

	 
	 Unit getUnit (int, int);
	 //Description: Returns the unit board[x][y].
	 //Pre: x and y are in the correct range
	 //Post: return the unit board[x][y]


	 void setUnit (int, int, char, int);
	 //Description:
	 //Pre: x and y are in the correct range
	 //Post: reset the data in board[x][y] so that occupant = newOccupant
	 //and Tabasco = newTabasco;

     // TRANSFORMERS

	 void cajunSpray(Cajun, Mosquito[]);
	 //Description: This function will update the board after aCajun spray
	 //the Tabasco.  Note that a separate process will be needed to update
	 //the correponding mosquitoes' record (if it kills some mosquitoes)
	 //Pre: None
	 //Post: The data on the board are all updated according the rules 
	 //specified in assigment #2.
	 
	 void expiredSpray();
	 //Description: will check to see if spray has expired
	 //if it has will turn 'T' into ' '
	 //Pre: must run decrementSpray()
	 //Post: all 'T' on the Board must have a strength 
	 //of >= 1

	 
	 void T_Update();
	 //Description: will display a 'T' if it wasn't able to on previous round
	 //ex. if a Cajun was in the middle of the spray
	 //when the cajun is moved a T will appear


	 void generateObjects(int, int);
	 //Description: assign Mosquitoes and Obstacles on the board via a random
	 //number generator.
	 //Pre: Assume that there are sufficient spaces for the allocation of all
	 //these objects.
	 //Post: the board data are updated accordingly.


	 void setRound(int);
	 //Description: Set the maximum number of rounds allowed
	 //Pre:
	 //Post:


	 void incrementRound();
	 //Description: Increase the number of round by 1
	 //Pre:
	 //Post:


	 void ClearBoard();
	 //Descriptions: Resets all positions on the gameBoard to the same configuration
	 //as applying the constructor.
	 //Pre: none
	 //Post: Same as constructor.


 };
