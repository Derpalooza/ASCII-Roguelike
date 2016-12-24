#include <iostream>
#include "StateMachine.h"
#include "State.h"
#include "MenuState.h"

using namespace std;

StateMachine::StateMachine(){
	//Initialize state to "Menu"
	
	cout << "Rogue Engine." << endl;
	_state = new MenuState();
	active = true;

}

void StateMachine::handleInput(){
	State* newState = _state->handleInput();

	if (newState != NULL){
		_state = newState;
	}
}

void StateMachine::update(){
	cout << "update" << endl;
	_state->update();
}

void StateMachine::draw(){
	cout << "draw" << endl;
	_state->draw();
}
