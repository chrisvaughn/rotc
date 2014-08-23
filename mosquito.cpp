

#include "mosquito.h"

#include <iostream>

using namespace std;




Mosquito::Mosquito()
{

    xPos = 0;
    yPos = 0;

}

//************************************************************

Mosquito::Mosquito(int x, int y)
{

    xPos = x;
    yPos = y;

}

//************************************************************

int Mosquito::getX()
{

    return xPos;

}

//***********************************************************

int Mosquito::getY()
{

    return yPos;

}

//***********************************************************

bool Mosquito::IsAlive()
{

    return alive;

}

//***********************************************************

void Mosquito::setAliveOrDead(bool newState)
{

    alive = newState;

}

//***********************************************************

void Mosquito::setX(int X)
{

    xPos = X;

}

//***********************************************************

void Mosquito::setY(int Y)
{

    yPos = Y;

}

//***********************************************************

void Mosquito::move(direction aDirection)
{

    if (aDirection == N)
    {

        xPos = xPos + 1;

    }

    else if (aDirection == NE)
    {

        xPos = xPos + 1;
        yPos = yPos + 1;

    }

    else if (aDirection == E)
    {

        yPos = yPos + 1;

    }

    else if (aDirection == SE)
    {

        xPos = xPos - 1;
        yPos = yPos + 1;

    }

    else if (aDirection == S)
    {

        xPos = xPos - 1;

    }

    else if (aDirection == SW)
    {

        xPos = xPos - 1;
        yPos = yPos - 1;

    }

    else if (aDirection == W)
    {

        yPos = yPos - 1;

    }

    else if (aDirection == NW)
    {

        xPos = xPos + 1;
        yPos = yPos - 1;

    }

    else ;

}










