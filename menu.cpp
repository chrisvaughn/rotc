#include <iostream>
#include <string>
#include "menu.h"

   using namespace std;

//////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////

 void Menu::DisplayWelcome()
 {

    char proceed;  
	 
	// system("banner \"The Return\" \"  of the\" \"  CAJUNS\"");

	cout<<"Please enter \'C\' to continue: ";

	 cin>>proceed;

	 cout<<endl;

	 if (proceed != 'C' || proceed != 'c')
	 {

      while (proceed != 'C' || proceed != 'c')
	   {

	      cout<<"Sorry your input was invalid"<<endl;
			
			cout<<"Please press \'C\': ";

			cin>>proceed;

			cout<<endl;

		}

		
	 }	
		
	else 
	{ 
		
	   system("cls");
		
	}

 }

//********************************************************
//
//********************************************************

 void Menu::DisplayMenu()
 {

	 int menu_selection;

	 cout<<"PLEASE SELECT A NUMBER"<<endl;

	 cout<<endl;

	 cout<<"1 - Rules & Instructions"<<endl;

	 cout<<"2 - Game Setup"<<endl;

	 cout<<"3 - Start Game"<<endl;

	 cout<<"4 - EXIT"<<endl;

	 cout<<"Enter selection: ";

	 cin>>menu_selection;

	 cout<<endl;

	 cout<<"** NOTE: You must go through \"GAME SETUP\" before starting a game"<<endl;

	 if (menu_selection != 1 || menu_selection != 2 || menu_selection != 3 || menu_selection != 4)
	 {

		 while ((menu_selection != 1 || menu_selection != 2 || menu_selection != 3 || menu_selection != 4)
		 {

			 cout<<menu_selection<<" is invalid please choose from 1, 2, 3, or 4 ";

			 cin>>menu_selection;

			 cout<<endl;

		 }

	 }

    switch (menu_selection)
	{

	 case 1:

		 system("cls");
		 
		 DisplayRules();

	 case 2:

		 system("cls");
		 
		 gameSetup();

	 case 3:

		 system("cls");
		 
		 if (checkSetup)
		 {

			 break;

		 }

		 else 
		 {

			 cout<<"You must enter Game Setup before starting a game"<<endl;

			 system("cls");

			 DisplayMenu();

		 }

	 case 4:

		 exit(1);

	 }

 }
