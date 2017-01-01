#pragma once
#include "State.h"

class HelpState : public State {

public:
	HelpState();
	State* handleInput();
	void update();
	void draw();
};
