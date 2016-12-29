#include "LevelState.h"
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

	level->handleInput(c);

	cout << "Level input" << endl;
	return NULL;
}

void LevelState::update(){
	
	//Modify so that it returns a flag indicating if an enemy has rammed into the player
	level->update();

	cout << "Level update" << endl;
}

void LevelState::draw(){

	string clearstring(100, '\n');
	cout << clearstring << endl;

	level->printLevel();
}

void LevelState::exit(){}
