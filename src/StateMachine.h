#pragma once 
#include "State.h"

class StateMachine
{
public:
	StateMachine();
	void handleInput();
	void update();
	void draw();

private:
	State* _state;
	bool _active;
};