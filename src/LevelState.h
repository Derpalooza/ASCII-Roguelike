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
//	Level* level;
//	int levelNumber;
};
