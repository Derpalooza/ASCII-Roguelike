#include <iostream>
#include "StateMachine.h"
#include "State.h"
#include "MenuState.h"

using namespace std;

StateMachine::StateMachine(){
	//Initialize state to "Menu"
	
	cout << "Engine works." << endl;
	
	// The error in MenuState is  appearing here. _state only points to initstate, and since initstate deallocates 
	// after it goes out of scope, _state will point to a null object.
	
	_state = new MenuState();
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
