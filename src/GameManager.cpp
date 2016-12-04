#include <iostream>
#include "GameManager.h"

using namespace std;

GameManager::GameManager(){}

void GameManager::run(){

	_stateMachine.handleInput();
	_stateMachine.update();
	_stateMachine.draw();


	cout << "StateMachine works" << endl;
		
}

