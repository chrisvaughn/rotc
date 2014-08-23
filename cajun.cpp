

#include <iostream>
#include "cajun.h"

using namespace std;



//****************************************************************

Cajun::Cajun()
{

    xPos = 0;
    yPos = 0;
    orientation = 'N';

}

//******************************************************************

Cajun::Cajun(int x, int y, char direction)
{

    xPos = x;
    yPos = y;
    orientation = direction;

}

//******************************************************************

int Cajun::getX()
{

    return xPos;

}

//******************************************************************

int Cajun::getY()
{

    return yPos;

}

//******************************************************************

char Cajun::getDirection()
{

    return orientation;

}


//******************************************************************

void Cajun::move()
{

    if (orientation == 'N')
    {

        xPos = xPos + 1;

    }

    else if (orientation == 'S')
    {

        xPos = xPos - 1;

    }

    else if (orientation == 'E')
    {

        yPos = yPos + 1;

    }

    else if (orientation == 'W')
    {

        yPos = yPos - 1;

    }

    else ;

}

//*****************************************************************

void Cajun::turn(turnDirection mySide)
{

    if (mySide == CLOCKWISE)
    {

        if (orientation == 'N')
        {

            orientation = 'E';

        }

        else if (orientation == 'S')
        {

            orientation = 'W';

        }

        else if (orientation == 'E')
        {

            orientation = 'S';

        }

        else if (orientation == 'W')
        {

            orientation = 'N';

        }

        else ;

    }

    if (mySide == ANTI_CLOCKWISE)
    {


        if (orientation == 'N')
        {

            orientation = 'W';

        }

        else if (orientation == 'S')
        {

            orientation = 'E';

        }

        else if (orientation == 'E')
        {

            orientation = 'N';

        }

        else if (orientation == 'W')
        {

            orientation = 'S';

        }

        else ;

    }

}

//****************************************************************











