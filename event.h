/*	File name:	event.h
	Description:	Event class for the iSwoon program.
	Authors:	Hall, Andrew
	Assignment #5:	Group #6	*/
#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>
using namespace std;

class Event
{
private:
	// Data members.
	int allowedDates;
	string description;
public:
	// Constructors.
	Event() { allowedDates = 0; description = ""; }
	Event(int allowedDates, string description) { this->allowedDates = allowedDates; this->description = description; }

	// Accessors.
	bool dateSupported(int dateNumber) const { if (dateNumber < allowedDates) return true; else return false; }
	string getDescription() const { return description; }
};

#endif
