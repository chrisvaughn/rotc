#include "board.h"
#include <iostream>
#include <ctime>

using namespace std;

GameBoard::GameBoard ()
{

    for (int i = 0; i <= MAX_ROWS - 1; i++)
    {

        for (int j = 0; j <= MAX_COL - 1; j++)
        {

            Board[i][j].occupant = ' ';
            Board[i][j].tabasco = 0;

        }
    }

    Board[0][0].occupant = 'E';
    Board[0][7].occupant = 'N';
    Board[7][0].occupant = 'S';
    Board[7][7].occupant = 'W';

}

//****************************************************************

void GameBoard::DisplayInfo(Cajun A, Cajun B, Cajun C, Cajun D, Mosquito mosquitos[])
{

    cout << endl;
    cout << "Cajuns:" << endl;
    cout << endl;
    cout << "X: (" << A.getX() + 1 << "," << A.getY() + 1 << ") ";
    cout << "Y: (" << B.getX() + 1 << "," << B.getY() + 1 << ") ";
    cout << "Z: (" << C.getX() + 1 << "," << C.getY() + 1 << ") ";
    cout << "W: (" << D.getX() + 1 << "," << D.getY() + 1 << ") ";
    cout << endl;
    cout << endl;

    cout << "Mosquitoes:" << endl;
    for (int i = 0; i < 9; i++)
    {
        if (mosquitos[i].IsAlive())
        {
            cout << i << ": (" << mosquitos[i].getX() + 1 << "," << mosquitos[i].getY() + 1 << ") ";

        }

    }
    cout << endl;
    cout << endl;

    cout << "Current Round number: " << currRound + 1 << endl;
    cout << endl;

    cout << "Maximum number of rounds: " << MaxRounds << endl;
    cout << endl;

}

//**************************************************************

void GameBoard::DisplayBoard()
{



    system("clear");


    for (int i = 0; i < MAX_COL - 1; i++)
    {

        cout << "____";

    }

    cout << "_____";
    cout << endl;


    for (int k = MAX_ROWS - 1; k >= 0; k--)
    {

        for (int l = 0; l < MAX_COL; l++)
        {

            cout << "| " << Board[k][l].occupant << " ";


        }

        cout << "|" << endl;

        for (int m = 0; m < MAX_COL; m++)
        {

            cout << "|___";

        }

        cout << "|" << endl;
    }



}

//*************************************************************

StatusType GameBoard::getCurrentStatus(Mosquito mosqArray[])
{
    bool allDead;


    for (int i = 0; i < MAX_MOSQ; i++)
    {
        if (mosqArray[i].IsAlive() == true)
            allDead = false;

    }

    if (currRound == MaxRounds)
    {
        return BOB_WIN;

    }

    else if (allDead)
    {
        return ALICE_WIN;
    }

    else
    {

        return IN_PROGRESS;

    }


}

//*************************************************************


bool GameBoard::IsLegalAliceMove(Cajun A)
{

    if (A.getDirection() == 'N' &&
        ((Board[A.getX() + 1][A.getY()].occupant == ' ') ||
         (Board[A.getX() + 1][A.getY()].occupant == 'T')))
    {
        return true;
    }

    else if (A.getDirection() == 'S' &&
             ((Board[A.getX() - 1][A.getY()].occupant == ' ') ||
              (Board[A.getX() - 1][A.getY()].occupant == 'T')))
    {
        return true;
    }

    else if (A.getDirection() == 'E' &&
             ((Board[A.getX()][A.getY() + 1].occupant == ' ') ||
              (Board[A.getX()][A.getY() + 1].occupant == 'T')))
    {
        return true ;
    }
    else if (A.getDirection() == 'W' &&
            ((Board[A.getX()][A.getY() - 1].occupant == ' ') ||
              (Board[A.getX()][A.getY() - 1].occupant == 'T')))
    {
        return true;
    }

    else
    {
        return false;
    }

}

//***************************************************************

bool GameBoard::IsLegalBobMove(Mosquito mosArray[], int index, direction d)
{

    int x;
    int y;

    x = mosArray[index].getX();
    y = mosArray[index].getY();


    if ((d == N) && (Board[x + 1][y].occupant == ' '))

        return true;

    else if ((Board[x + 1][y + 1].occupant == ' ') && (d == NE))

        return true;

    else if ((Board[x][y + 1].occupant == ' ') && (d == E))

        return true;

    else if ((Board[x - 1][y + 1].occupant == ' ') && (d == SE))

        return true;

    else if ((Board[x - 1][y].occupant == ' ') && (d == S))

        return true;

    else if ((Board[x - 1][y - 1].occupant == ' ') && (d == SW))

        return true;

    else if ((Board[x][y - 1].occupant == ' ') && (d == W))

        return true;

    else if ((Board[x + 1][y - 1].occupant == ' ') && (d == NW))

        return true;

    else

        return false;

}

//******************************************************************************


Unit GameBoard::getUnit (int x, int y)
{

    Unit tempUnit;

    tempUnit.occupant = Board[x][y].occupant;
    tempUnit.tabasco = Board[x][y].tabasco;

    return (tempUnit);

}

//**************************************************************************

void GameBoard::setUnit(int x, int y, char newOccupant, int newTabasco)
{

    Board[x][y].occupant = newOccupant;
    Board[x][y].tabasco = newTabasco;


}

//*************************************************************************

void GameBoard::cajunSpray(Cajun aCajun, Mosquito mosqArray[])
{

    int x;
    int y;

    x = aCajun.getX();
    y = aCajun.getY();

    if (aCajun.getDirection() == 'N')
    {
        x = x + 1;
    }

    else if (aCajun.getDirection() == 'S')
    {
        x = x - 1;
    }

    else if (aCajun.getDirection() == 'E')
    {
        y = y + 1;
    }

    else if (aCajun.getDirection() == 'W')
    {
        y = y - 1;
    }

    else;


    for (int i = 0; i < MAX_TAB_SQUARES; i++)
    {

        if (aCajun.getDirection() == 'N')
        {

            if (Board[x][y].occupant == ' ')
            {
                Board[x][y].occupant = 'T';
                Board[x][y].tabasco = MAX_TAB_STREN;
                x++;
            }

            else if (Board[x][y].occupant == 'M')
            {
                Board[x][y].occupant = 'T';
                Board[x][y].tabasco = MAX_TAB_STREN;

                for (int k = 0; k < 9; k++)
                {
                    if ((mosqArray[k].getX() == x) && (mosqArray[k].getY() == y))
                    {
                        mosqArray[k].setAliveOrDead(false);
                    }

                }

                x++;

            }

            else if ((Board[x][y].occupant == 'X') || (Board[x][y].occupant == 'Z') || (Board[x][y].occupant == 'W'))
            {

                Board[x][y].tabasco = MAX_TAB_STREN;
                x++;

            }

            else ;

        }

        else if (aCajun.getDirection() == 'S')
        {


            if (Board[x][y].occupant == ' ')
            {
                Board[x][y].occupant = 'T';
                Board[x][y].tabasco = MAX_TAB_STREN;
                x--;
            }

            else if (Board[x][y].occupant == 'M')
            {
                Board[x][y].occupant = 'T';
                Board[x][y].tabasco = MAX_TAB_STREN;

                for (int k = 0; k < 9; k++)
                {
                    if ((mosqArray[k].getX() == x) && (mosqArray[k].getY() == y))
                    {
                        mosqArray[k].setAliveOrDead(false);
                    }

                }

                x--;

            }

            else if ((Board[x][y].occupant == 'X') || (Board[x][y].occupant == 'Z') || (Board[x][y].occupant == 'Y'))
            {

                Board[x][y].tabasco = MAX_TAB_STREN;
                x--;

            }

            else ;

        }

        else if (aCajun.getDirection() == 'E')
        {

            if (Board[x][y].occupant == ' ')
            {
                Board[x][y].occupant = 'T';
                Board[x][y].tabasco = MAX_TAB_STREN;
                y++;
            }

            else if (Board[x][y].occupant == 'M')
            {
                Board[x][y].occupant = 'T';
                Board[x][y].tabasco = MAX_TAB_STREN;

                for (int k = 0; k < 9; k++)
                {
                    if ((mosqArray[k].getX() == x) && (mosqArray[k].getY() == y))
                    {
                        mosqArray[k].setAliveOrDead(false);
                    }

                }

                y++;

            }

            else if ((Board[x][y].occupant == 'Y') || (Board[x][y].occupant == 'Z') || (Board[x][y].occupant == 'W'))
            {

                Board[x][y].tabasco = MAX_TAB_STREN;
                y++;

            }

            else ;

        }

        else if (aCajun.getDirection() == 'W')
        {

            if (Board[x][y].occupant == ' ')
            {
                Board[x][y].occupant = 'T';
                Board[x][y].tabasco = MAX_TAB_STREN;
                y--;
            }

            else if (Board[x][y].occupant == 'M')
            {
                Board[x][y].occupant = 'T';
                Board[x][y].tabasco = MAX_TAB_STREN;

                for (int k = 0; k < 9; k++)
                {
                    if ((mosqArray[k].getX() == x) && (mosqArray[k].getY() == y))
                    {
                        mosqArray[k].setAliveOrDead(false);
                    }

                }

                y--;

            }

            else if ((Board[x][y].occupant == 'X') || (Board[x][y].occupant == 'Y') || (Board[x][y].occupant == 'W'))
            {

                Board[x][y].tabasco = MAX_TAB_STREN;
                y--;

            }

            else ;

        }

        else ;

    }



}

//***************************************************************

void GameBoard::expiredSpray()
{

    for (int i = 0; i < MAX_ROWS; i++)
    {

        for (int j = 0; j < MAX_COL; j++)
        {

            if ((Board[i][j].tabasco == 0) && (Board[i][j].occupant == 'T'))

                Board[i][j].occupant = ' ';


        }

    }

}


//*****************************************************************

void GameBoard::T_Update()
{

    for (int i = 0; i < MAX_ROWS; i++)
    {

        for (int j = 0; j < MAX_COL; j++)
        {

            if ((Board[i][j].tabasco > 0) && (Board[i][j].occupant == ' '))

                Board[i][j].occupant = 'T';


        }

    }

}


//****************************************************************

void GameBoard::generateObjects(int noOfMosq, int noOfObst)
{

    int randRow, randCol;

    bool Validspace;

    srand((int)time(NULL));  // Seed the random number generator.
    // I aqm using the time so that the nums are different
    // everytime the program is ran


    for (int howManyMosq = 0; howManyMosq < noOfMosq; howManyMosq++)
    {
        Validspace = false;

        while (!Validspace)
        {
            randRow = rand() % MAX_ROWS;            // Generate random row
            randCol = rand() % MAX_COL; // Generate random column

            if ((Board[randRow][randCol].occupant == ' ') && (randRow <= 8) && (randCol <= 8))
            {
                Board[randRow][randCol].occupant = 'M';
                Validspace = true;

            }

        }

    }

    for (int howManyObst = 0; howManyObst < noOfObst; howManyObst++)
    {
        Validspace = false;

        while (!Validspace)
        {
            randRow = rand() % MAX_ROWS;            // Generate random row
            randCol = rand() % MAX_COL; // Generate random column

            if ((Board[randRow][randCol].occupant == ' ') && (randRow <= 8) && (randCol <= 8))
            {
                Board[randRow][randCol].occupant = 'O';
                Validspace = true;

            }

        }

    }

}

//*******************************************************************

void GameBoard::setRound(int a)
{

    MaxRounds = a;
    currRound = 0;

}

//********************************************************************

void GameBoard::incrementRound()
{

    currRound++;

    for (int i = 0; i < MAX_ROWS; i++)
    {

        for (int j = 0; j < MAX_COL; j++)
        {

            if (Board[i][j].tabasco != 0)

                Board[i][j].tabasco = Board[i][j].tabasco - 1;

        }

    }

}

//*******************************************************************

void GameBoard::ClearBoard()
{

    for (int i = 0; i < MAX_ROWS; i++)
    {

        for (int j = 0; j < MAX_COL; j++)
        {

            Board[i][j].occupant = ' ';
            Board[i][j].tabasco = 0;

        }
    }

    Board[0][0].occupant = 'E';
    Board[0][7].occupant = 'N';
    Board[7][0].occupant = 'S';
    Board[7][7].occupant = 'W';

}
