#include <iostream>
#include <string>
#include "board.h"

using namespace std;


class Menu
{

public:

    //Constructor

    Menu();

    //Observors

    void DisplayMenu();

    void DisplayRules();

    void DisplayWelcome();

    void gameSetup();

    //Transformers

private:

    bool checkSetup;

}