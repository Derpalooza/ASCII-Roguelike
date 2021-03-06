#pragma once
#include "State.h"
#include "Level.h"
#include "Player.h"

class LevelState : public State{
public:
	LevelState();
	State* handleInput();
	void update();
	void draw();
	~LevelState();

private:
	Level* level;
	Player* player;
	int levelNumber;
};
