#pragma once
#include "State.h"

class LevelState : public State{
public:
	LevelState();
	State* handleInput();
	void update();
	void draw();
	void exit();		

private:
	//Make a vector of level classes
	//Level level;
	//int levelNumber;
};
