#include "LevelState.h"
#include "MenuState.h"
#include "conio.h"
#include <iostream>

using namespace std;

LevelState::LevelState(){

	levelNumber = 1;
	level = new Level(levelNumber);


	cout << "Level init" << endl;
}

State* LevelState::handleInput(){
	
	char c;
	c = getch();

	int action = level->movePlayer(c);
	
	switch (action){
		case 0:
			return NULL;
		case -1:
			return new MenuState;
		default:
			delete level;
			level = new Level(action);
			return NULL;
	
	}
}

void LevelState::update(){
	
	//Modify so that it returns a flag indicating if an enemy has rammed into the player
	level->updateEnemies();

	cout << "Level update" << endl;
}

void LevelState::draw(){
	State::draw();
	level->printLevel();
}

void LevelState::exit(){}
