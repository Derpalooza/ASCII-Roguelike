#include "LevelState.h"
#include "conio.h"
#include <iostream>

using namespace std;

LevelState::LevelState(){
	/*
	levelNumber = 1;
	level = new Level(levelNumber);
	*/

	cout << "Level init" << endl;
}

State* LevelState::handleInput(){
	
	char c;
	c = getch();
	
	/*
	level->handleInput(c);
	return NULL;
	*/

	cout << "Level input" << endl;
	return NULL;
}

void LevelState::update(){
	//Level* newLevel = level->update();

	cout << "Level update" << endl;
}

void LevelState::draw(){
	//level->printLevel();

	cout << "Level draw" << endl;
}

void LevelState::exit(){}