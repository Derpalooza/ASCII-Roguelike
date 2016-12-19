#pragma once
#include <string.h>

/*
  TODO: Rework the template so that we can switch between states more easily.
        We'll probably be able to do this by switching handleInput from void to State*
*/


class State
{
	// Any setup that needs to be done upon entering a new state is handled by the constructor
	
public:
	
	virtual void handleInput() = 0;		// Handles received inputs
	virtual void update() = 0;			// Handles updates to the state
	virtual void draw() = 0;			// Updates the console window
	virtual void exit() = 0;			// Any setup that needs to be done upon leaving a  state

};