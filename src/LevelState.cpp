#include "LevelState.h"
#include "MenuState.h"
#include "conio.h"
#include <iostream>

using namespace std;

LevelState::LevelState(){

	player = new Player();
	
	levelNumber = 1;
	level = new Level(levelNumber, player);


	cout << "Level init" << endl;
	cout << player->currentHP << "dadasdas" << endl;
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
			level = new Level(action, player);
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
