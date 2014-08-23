 #include <iostream>

	 using namespace std;


#ifndef _turnDirectDEF
#define _turnDirectDEF	 
 enum turnDirection {CLOCKWISE, ANTI_CLOCKWISE};
#endif


 #ifndef _CajunDEF
 #define _CajunDEF
 
 class Cajun
{ 

 //Description: Contains the representation of Cajun and provides operations 
 //such as moving and rotation as described in earlier document.

 private:

     int xPos; //represents the x (resp. y) coordinate of the Cajun
     int yPos;

     char orientation; //represents the direction that the Cajun is facing

 public:

    Cajun();// CONSTRUCTOR
    // initializes a Cajun whose coordinates is (0,0) and it is facing North. 
    //Pre: none
    //Post: all data of the Cajun are initialized

    Cajun(int, int, char); // CONSTRUCTOR
    //initializes a Cajun whose coordinates is (x,y) and it is facing the 
	//direction indicated by myChar
	//Pre: none
    //Post: all data of the Cajun are initialized


	//OBSERVERS

    int getX();
    int getY();
    char getDirection();
    //displays the corresponding data of the Cajun
    //Preconditions and Postcondition are trivial in all three cases.

    //TRANSFORMERS

    void move();
    //Pre: Assume that the move has been checked to be feasible
    //Post: xPos or yPos are updated according to the orientation 
    //of the Cajun.

    void turn(turnDirection); 
    //Pre: none
    //Post: orientation of the Cajun is updated accordingly
    //Range of values for mySide is either CLOCKWISE or ANTI_CLOCKWISE 
    //the data type turnDirection stands for {CLOCKWISE, ANTI_CLOCKWISE}. 

 };
 #endif
