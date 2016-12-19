#include <iostream>
#include "GameManager.h"

using namespace std;

GameManager::GameManager(){}

void GameManager::run(){
	
	while(_stateMachine.active){
		_stateMachine.update();
		_stateMachine.draw();
		_stateMachine.handleInput();
	}

	cout << "StateMachine works" << endl;
		
}

