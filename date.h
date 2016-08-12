/*	File name:	date.h
	Description:	Date class for the iSwoon program.
	Authors:	Brumbaugh, Danielle; Hall, Andrew; Knoop, Rebeccah;	Schnitzler, Scott
	Assignment #5:	Group #6	*/
#ifndef DATE_H
#define DATE_H
#include "event.h"
#include <vector>

class Date
{
private:
	// Data members.
	int dateNumber;
	int maxDates;
	vector<Event> vEvents;

public:
	// Constructors
	Date() { dateNumber = 0; maxDates = 0; vEvents.push_back(Event(0, "")); }
	Date(int maxDates) { dateNumber = 0; this->maxDates = maxDates; vEvents.push_back(Event(maxDates, "")); }

	// Mutator, addEvent to add events for dates.
	bool addEvent() 
	{
		if (vEvents.at(dateNumber).dateSupported(dateNumber))
		{
			// Declare string and capture description.
			string nDescription = "";
			cout << "Enter a description for the event: ";
			getline(cin, nDescription);

			// Declare an Event with the set parameters.
			Event newEvent(maxDates, nDescription);

			// Add event to vector.
			vEvents.push_back(newEvent);

			// Increment the number of dates.
			dateNumber++;

			// Display message and return.
			cout << "Event added!" << endl;
			return true;
		}
		else
		{
			// If max number of events reached, display error.
			cout << "ERROR: Cannot add another event!" << endl;
			return false;
		}		
	}

	// Mutator, goOnDate to go on date and remove the event.
	bool goOnDate()
	{
		if (dateNumber > 0)
		{
			// Declare a count variable.
			int count = 1;

			// Display the events.
			cout << "==========================" << endl;
			cout << "====== Choose Event ======" << endl;
			cout << "==========================" << endl;

			// For loop to display all dates.
			for (auto i = vEvents.begin() + 1; i != vEvents.end(); i++)
			{
				cout << "(" << count++ << ") " << (*i).getDescription() << endl;
			}
			cout << "==========================" << endl;

			// Get selection.
			count = getSelection(count - 1);

			// Erase the selection.
			vEvents.erase(vEvents.begin() + count);

			// Decrement the date count.
			dateNumber--;

			// Display message and return.
			cout << "Enjoy your date!" << endl;
			return true;
		}
		else
		{
			cout << "ERROR: No events available!" << endl;
			return false;
		}
	}

	//	Helper function, moved from client for additional accessability.
	/*	Function:	getSelection
		Description:	Capture user input, validate, and return the selection.
		Parameters:	Int value for number of menu options.
		Returns:	Int value of selection.
		Authors:	Hall, Andrew	*/
	int getSelection(int numOptions)
	{
		// Function variables.
		string input = "";
		int selection = 0;

		// While loop to validate input.
		while (selection == 0)
		{
			// Capture user selection.
			cout << "Please make a selection: ";
			getline(cin, input);

			// If the input is one char in length and is a digit. Convert to int.
			if (input.length() == 1 && isdigit(input[0]))
				selection = stoi(input);

			// Check if selection is in range.
			if (selection <= 0 || selection > numOptions)
			{
				// Set selection back to zero, display error.
				selection = 0;
				cout << "ERROR: Invalid entry!" << endl;
			}
		}

		// Insert break.
		cout << endl;

		// Return selection.
		return selection;
	}
};

#endif
