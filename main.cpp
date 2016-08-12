/*	File name:	main.cpp
	Description:	The client file for the iSwoon program.
	Authors:	Hall, Andrew
	Assignment #5:	Group #6	*/
#include "date.h"

// Function prototypes.
void displayMenu();

int main()
{
	// Program variables.
	const int NUM_OPTIONS = 3;
	int selection = 0;
	Date temp(0);	// To access getSelection function. DRY!

	// Get user input for number of dates to set up for.
	cout << "Welcome to iSwoon, how many dates would you like to set up? (Limit 9)" << endl;
	selection = temp.getSelection(9);

	// Create Date class for program.
	Date date(selection);

	// Do while loop to contain program until user quits.
	do
	{
		// Display menu.
		displayMenu();

		// Get user selection.
		selection = date.getSelection(NUM_OPTIONS);

		// Perform task based on user selection. Menu can grow if another case is added and NUM_OPTIONS increased.
		switch (selection)
		{
		case 1:
			date.addEvent(); // Function call for adding a new date.
			break;
		case 2:
			date.goOnDate(); // Function call for going on date.
			break;
		case 3:
			cout << "Thank you for choosing iSwoon!" << endl;
			break;
		default:
			cout << "Invalid selection! Please review the menu." << endl;
		}

		// If user did not choose quit, ask user if they would like to make another selection.
		if (selection != NUM_OPTIONS)
		{
			cout << "==========================" << endl;
			cout << "=== View menu options: ===" << endl;
			cout << "==========================" << endl;
			cout << "(1) Yes" << endl;
			cout << "(2) No" << endl;
			cout << "==========================" << endl;

			// Get selection.
			selection = date.getSelection(2);

			// If user chooses no, set selection to end loop.
			if (selection == 2)
				selection = NUM_OPTIONS;
		}
	} while (selection != NUM_OPTIONS);

	// Close program.
	cout << endl; return 0;
}

/*	Function:	displayMenu
	Description:	Display the user menu.
	Parameters:	None.
	Returns:	None.
	Authors:	Hall, Andrew	*/
void displayMenu()
{
	// Display menu.
	cout << "==========================" << endl;
	cout << "========= iSwoon =========" << endl;
	cout << "==========================" << endl;
	cout << "(1) Add New Date" << endl;
	cout << "(2) Go On Date" << endl;
	cout << "(3) Quit iSwoon" << endl;
	cout << "==========================" << endl;
}
