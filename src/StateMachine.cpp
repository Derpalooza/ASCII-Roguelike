#include <iostream>
#include "StateMachine.h"
#include "State.h"
#include "MenuState.h"

using namespace std;

StateMachine::StateMachine(){
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
	_state->update();
}

void StateMachine::draw(){
	_state->draw();
}
