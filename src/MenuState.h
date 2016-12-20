#pragma once
#include <string> 
#include "State.h"

class MenuState : public State {

public:

	MenuState();
	State* handleInput();
	void update();
	void draw();
	void exit();
private:	
	void printTitle();
	void changeSelected(char input);
	std::string menuOptions[3];
	int selected;
};
