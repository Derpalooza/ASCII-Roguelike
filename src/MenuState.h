#pragma once 
#include "State.h"

class MenuState : public State {

public:

	MenuState();
	void handleInput();
	void update();
	void draw();
	void exit();

};