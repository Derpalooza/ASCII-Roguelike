#include <iostream>
#include "StateMachine.h"
#include "State.h"
#include "MenuState.h"

using namespace std;

StateMachine::StateMachine(){
	//Initialize state to "Menu"
	
	cout << "Engine works." << endl;

	MenuState initState;
	_state = &initState;
	//_active = true;

}

void StateMachine::handleInput(){
	_state->handleInput();
}

void StateMachine::update(){
	_state->update();
}

void StateMachine::draw(){
	_state->draw();
}