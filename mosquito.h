
 #include <iostream>
  
    using namespace std;

	#ifndef _DirDEF
    #define _DirDEF
	enum direction {N,NE,E,SE,S,SW,W,NW};
	#endif

 
 #ifndef _MosqDef
 #define _MosqDef
	
 class Mosquito
 {
	 //Description: Represents the mosquito in the game.

 private:
	 
     int xPos;
	 int yPos;
	 //Represents the coordinates of the mosquito. Same ideas as in Cajun

     bool alive;
	 //boolean value which indicate if the mosquito is alive or not

 public:

	 Mosquito(); // Default Constructor
     //Initializes the location to (0,0)
     //Pre: none
	 //Post: The coordinates are set to (0,0).

     Mosquito(int, int); //constructor 
	 //initializes the location to (x,y).
	 //Pre and Post are trivial.

     
     // OBSERVERS 

     int getX();
     int getY();
	 //displays the corresponding data of the Mosquito
     //Preconditions and Postcondition are trivial in all two cases

	 bool IsAlive();
	 //returns variable alive

     // TRANSFORMERS 

     void setX(int);
	 void setY(int);
		 
	 void setAliveOrDead(bool);
	 //updates varialbe alive if it's status changes

	 void move(direction);
     //Pre: Assume that the move has been checked to be feasible
	 //Post: xPos or yPos are unpdated accordingly.

     

 };

#endif
 
