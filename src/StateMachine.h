#pragma once 
#include "State.h"

class StateMachine
{
public:
	StateMachine();
	void handleInput();
	void update();
	void draw();
	bool active;
private:
	State* _state;
};
