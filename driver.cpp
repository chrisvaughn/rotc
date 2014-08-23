#include <iostream>
#include <string>
#include "mosquito.h"
#include "cajun.h"
#include "board.h"

using namespace std;

void WELCOME();

char printMenu1();

int printMenu2();

bool printMenu3();

void MoveCajun(GameBoard &, Cajun &, bool &);

void TurnCajun(GameBoard &, Cajun &, string, bool &);

int str2num(string);

int char2num(char);

direction str2enum(string);

void fillArray(GameBoard &, Mosquito[]);
//Description:
//This function will update the records stored in the array myMosquitoes
//from the board data stored in the object myRoom.
//Pre: the number of mosquitoes in myRoom must be smaller than the size
//of the array.
//Post: All data in myMosquitoes are updated.


int main()
{
    char choice;
    char anotherGame = 'Y';
    bool boardChosen;
    bool quit;
    bool AliceMove = true;
    bool ValidCommand = false;
    int roundChosen;

    Cajun X(0, 0, 'E');
    Cajun Y(7, 0, 'S');
    Cajun Z(7, 7, 'W');
    Cajun W(0, 7, 'N');


    Mosquito mosquitoes[9];
    GameBoard theRoom;


    /* Initial Phase */

    string CajunPlayer;
    string MosqPlayer;
    string AliceCommand;
    string BobCommand;
    string subCommand;
    string subDirection;
    string subSelected;

    WELCOME();

    while (anotherGame == 'Y')
    {

        cout << "Player 1 please enter your name: ";
        cin >> CajunPlayer;
        cout << endl;

        cout << "Player 2 please enter your name: ";
        cin >> MosqPlayer;
        cout << endl;

        boardChosen = false;


        while (boardChosen == false)
        {
            theRoom.ClearBoard();
            theRoom.generateObjects(9, 5);
            fillArray(theRoom, mosquitoes);
            roundChosen = printMenu2(); /* set round */
            theRoom.setRound(roundChosen);
            theRoom.DisplayBoard();
            theRoom.DisplayInfo(X, Y, Z, W, mosquitoes);
            choice = printMenu1();
            if ((choice == 'Y') || (choice == 'y'))
                boardChosen = true;
        };


        /* choose to start or quit */
        quit = printMenu3();

        theRoom.DisplayBoard();
        theRoom.DisplayInfo(X, Y, Z, W, mosquitoes);


        while ((theRoom.getCurrentStatus(mosquitoes) == IN_PROGRESS) && (quit == true))
        {

            if (AliceMove)
            {
                ValidCommand = false;

                while (!ValidCommand)
                {
                    cout << endl;
                    cout << CajunPlayer << " please enter your command ";
                    cin >> AliceCommand;
                    cout << endl;

                    subCommand = AliceCommand.substr(0, 1);

                    if (subCommand == "m")
                    {

                        subSelected = AliceCommand.substr(5, 1);
                        cout << endl;

                        if ((subSelected == "X") || (subSelected == "Y") || (subSelected == "Z") || (subSelected == "W"))
                        {
                            ValidCommand = true;

                            if (subSelected == "X")
                            {
                                MoveCajun(theRoom, X, ValidCommand);
                            }

                            else if (subSelected == "Y")
                            {
                                MoveCajun(theRoom, Y, ValidCommand);
                            }

                            else if (subSelected == "Z")
                            {
                                MoveCajun(theRoom, Z, ValidCommand);
                            }

                            else if (subSelected == "W")
                            {
                                MoveCajun(theRoom, W, ValidCommand);
                            }


                            else  ;


                        }

                        else
                        {
                            cout << "You did not select a valid Cajun";
                            cout << endl;

                            ValidCommand = false;

                        }


                    }

                    else if (subCommand == "t")
                    {

                        subSelected = AliceCommand.substr(5, 1);

                        subDirection = AliceCommand.substr(7, 1);

                        if ((subSelected == "X") || (subSelected == "Y") || (subSelected == "Z") || (subSelected == "W"))
                        {

                            ValidCommand = true;

                            if (subSelected == "X")
                                TurnCajun(theRoom, X, subDirection, ValidCommand);

                            else if (subSelected == "Y")
                                TurnCajun(theRoom, Y, subDirection, ValidCommand);

                            else if (subSelected == "Z")
                                TurnCajun(theRoom, Z, subDirection, ValidCommand);

                            else if (subSelected == "W")
                                TurnCajun(theRoom, W, subDirection, ValidCommand);

                            else
                            {
                                cout << "You did not select a valid Cajun";
                                cout << endl;

                                ValidCommand = false;

                            }

                        }

                    }

                    else if (subCommand == "s")
                    {
                        ValidCommand = true;

                        subSelected = AliceCommand.substr(6, 1);

                        if (subSelected == "X")
                            theRoom.cajunSpray(X, mosquitoes);

                        else if (subSelected == "Y")
                            theRoom.cajunSpray(Y, mosquitoes);

                        else if (subSelected == "Z")
                            theRoom.cajunSpray(Z, mosquitoes);

                        else if (subSelected == "W")
                            theRoom.cajunSpray(W, mosquitoes);

                        else
                        {

                            cout << "You did not select a valid Cajun";
                            cout << endl;

                            ValidCommand = false;

                        }

                    }

                    else
                    {

                        cout << "Your command was invalid";
                        cout << endl;

                        ValidCommand = false;
                    }

                }

                AliceMove = false;
                theRoom.DisplayBoard();
                theRoom.DisplayInfo(X, Y, Z, W, mosquitoes);

            }

            else if (!AliceMove)
            {

                ValidCommand = false;

                while (!ValidCommand)
                {
                    cout << MosqPlayer << " please enter a command ";
                    cin >> BobCommand;
                    cout << endl;

                    if (BobCommand.length() < 8)
                    {
                        ValidCommand = false;
                        cout << "You did not enter a valid command" << endl;

                    }

                    else
                    {


                        subCommand = BobCommand.substr(0, 1);
                        subSelected = BobCommand.substr(5, 1);
                        subDirection = BobCommand.substr(7, 2);

                        if (subCommand == "m")
                        {

                            ValidCommand = true;

                            if (theRoom.IsLegalBobMove(mosquitoes, str2num(subSelected), str2enum(subDirection)))
                            {
                                if (mosquitoes[str2num(subSelected)].IsAlive())
                                {

                                    theRoom.setUnit(mosquitoes[str2num(subSelected)].getX(), mosquitoes[str2num(subSelected)].getY(), ' ', 0);
                                    mosquitoes[str2num(subSelected)].move(str2enum(subDirection));
                                    theRoom.setUnit(mosquitoes[str2num(subSelected)].getX(), mosquitoes[str2num(subSelected)].getY(), 'M', 0);


                                }

                                else
                                {

                                    cout << "The mosquito you have selected is dead";
                                    cout << endl;

                                    ValidCommand = false;

                                }

                            }

                            else
                            {

                                cout << "The move you are trying to make is illegal";
                                cout << endl;

                                ValidCommand = false;

                            }

                        }

                    }

                }

                theRoom.incrementRound();
                AliceMove = true;
                theRoom.expiredSpray();
                theRoom.T_Update();
                theRoom.DisplayBoard();
                theRoom.DisplayInfo(X, Y, Z, W, mosquitoes);

            }

            else ;

        }

        if (theRoom.getCurrentStatus(mosquitoes) == BOB_WIN)
        {

            system("cls");

            cout << MosqPlayer << " is the winner." << endl;

        }

        else if (theRoom.getCurrentStatus(mosquitoes) == ALICE_WIN)
        {
            system("cls");

            cout << CajunPlayer << " is the winner." << endl;

        }

        else ;

        cout << "Would like to play another game? (Y or N) ";
        cin >> anotherGame;
        cout << endl;
    }
    return 0;
}


//**************************************************************************
void WELCOME()
{
    char cont;

    cout << endl << endl << endl;
    cout << "              THE RETURN OF THE CAJUNS";

    cout << endl;
    cout << endl << endl << endl;
    cout << "Directions:" << endl;
    cout << "Player 1 will control the Cajuns and Player 2 will control the Mosquitoes." << endl;
    cout << "A Cajun can move, turn, or spray tabasco to kill Mosquitoes." << endl;
    cout << "A Mosquito can run, by moving in any direction assuming there are no obsticals." << endl;
    cout << endl;
    cout << "THE BOARD" << endl;
    cout << "Each space of the game has one of four occupants" << endl;
    cout << "A CAJUN shown by N,S,E,W - representing the direction the cajun is facing" << endl;
    cout << "A MOSQUITO shown by M" << endl;
    cout << "A OBSTACLE shown by O" << endl;
    cout << "And of course a unnoccupied spot" << endl;
    cout << "Under the gameboard is X,Y,Z,W each followed by" << endl;
    cout << " cooridinates and 0 - 8 each followed by coordinates" << endl;
    cout << "You will use the letters(X,Y,Z,W) and the number(0-8)" << endl;
    cout << "to identify which player you want to move" << endl;
    cout << endl;
    cout << "THE COOMANDS" << endl;
    cout << "CAJUN commands:" << endl;
    cout << "move(i)  - to move a CAJUN in the direction it is facing," << endl;
    cout << "       (i) will be either X,Y,Z,W" << endl << endl;
    cout << "turn(i,d) - to turn a CAJUN (i) - same as above" << endl;
    cout << "       (d) - either 'c' for CLOCKWISE or 'a' for COUNTER-CLICKWISE" << endl << endl;;
    cout << "spray(i) - to spray tabasco (i) - same as above" << endl << endl;
    cout << "MOSQUITO commands:" << endl;
    cout << "move(n,d) - where (n) is 0-8 and (d) is N,NE,E,SE,S,SW,W,NW" << endl;
    cout << "That's all enjoy" << endl;
    cout << endl << endl;
    cout << "Press C to continue ";
    cout << endl;
    cin >> cont;

    system("cls");

}




//***************************************************************************
char printMenu1()
{

    char Y_N;

    cout << "Do you wish to continue the game with the above game board? (Y or N) ";
    cin >> Y_N;
    cout << endl;

    return Y_N;

}


//***************************************************************************
int printMenu2()
{

    bool valid = false;
    int num;

    while (!valid)
    {
        cout << "Please enter the number of rounds you wish the game to last. ";
        cin >> num;
        cout << endl;

        if (num <= 0)
            valid = false;

        else
            valid = true;

    }

    return num;

}


//****************************************************************************
bool printMenu3()
{

    char selection;
    bool invalid = true;

    while (invalid)
    {

        cout << "Press 'C' to continue to the game, or 'Q' to quit. ";
        cin >> selection;
        cout << endl;


        if ((selection == 'C') || (selection == 'c'))
        {
            invalid = false;
            return true;
        }


        else if ((selection == 'Q') || (selection == 'q'))
        {
            invalid = false;
            return false;
        }

        else
        {

            cout << "Your entry was invalid!!";
            cout << endl << endl;;
            invalid = true;


        }

    }
    return false;

}

//***********************************************************************************************

void MoveCajun(GameBoard &theRoom, Cajun &A, bool &ValidCommand)
{

    char blank = ' ';

    if (theRoom.IsLegalAliceMove(A))
    {

        theRoom.setUnit(A.getX(), A.getY(), blank, 0);
        A.move();
        theRoom.setUnit(A.getX(), A.getY(), A.getDirection(), 0);

    }

    else
    {
        cout << "Sorry you can not move that Cajun";
        cout << endl;

        ValidCommand = false;

    }


}

//******************************************************************************************

void TurnCajun(GameBoard &room, Cajun &A, string direction, bool &ValidCommand)
{

    if (direction == "a")
    {

        A.turn(ANTI_CLOCKWISE);

        room.setUnit(A.getX(), A.getY(), A.getDirection(), room.getUnit(A.getX(), A.getY()).tabasco);
    }

    else if (direction == "c")
    {

        A.turn(CLOCKWISE);

        room.setUnit(A.getX(), A.getY(), A.getDirection(), room.getUnit(A.getX(), A.getY()).tabasco);
    }

    else
    {

        cout << "You have selected a invalid direction to turn";
        cout << endl;

        ValidCommand = false;

    }

}

//***************************************************************

int str2num(string mosq)
{

    int num;

    if (mosq == "0")
        num = 0;

    else if (mosq == "1")
        num = 1;

    else if (mosq == "2")
        num = 2;

    else if (mosq == "3")
        num = 3;

    else if (mosq == "4")
        num = 4;

    else if (mosq == "5")
        num = 5;

    else if (mosq == "6")
        num = 6;

    else if (mosq == "7")
        num = 7;

    else if (mosq == "8")
        num = 8;

    else
        num = -1;

    return num;

}

//**********************************************************************************

direction str2enum(string direct)
{
    direction temp;

    if (direct == "N)")
        temp = N;

    else if (direct == "NE")
        temp = NE;

    else if (direct == "E)")
        temp = E;

    else if (direct == "SE")
        temp = SE;

    else if (direct == "S)")
        temp = S;

    else if (direct == "SW")
        temp = SW;

    else if (direct == "W)")
        temp = W;

    else if (direct == "NW")
        temp = NW;

    else ;

    return temp;

}

//**************************************************************************************

void fillArray(GameBoard &myRoom, Mosquito myMosquitoes[])
{
    int mosqindex = -1;

    for (int i = 0; i <= MAX_ROWS; i++)
    {

        for (int j = 0; j <= MAX_COL; j++)
        {

            if (myRoom.Board[i][j].occupant == 'M')
            {
                mosqindex++;

                myMosquitoes[mosqindex].setX(i);
                myMosquitoes[mosqindex].setY(j);
                myMosquitoes[mosqindex].setAliveOrDead(true);

            }

        }

    }

}
