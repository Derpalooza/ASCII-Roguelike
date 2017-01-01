#pragma once
#include <string.h>

/*
  TODO: 
	Check to see if pure virtual functions need to be explicitly named in child classes
	Refactor draw() so that it outputs the clearstring before the custom implementations are made
*/


class State
{
	// Any setup that needs to be done upon entering a new state is handled by the constructor
	
public:
	
	virtual State* handleInput() = 0;		// Handles received inputs and returns the appropriate state
	virtual void update() = 0;			// Handles updates to the state
	virtual void draw();				// Updates the console window
};
