#pragma once
#include "State.h"

class HelpState : public State {

public:
	HelpState();
	void handleInput();
	void update();
	void draw();
	void exit();	

};
