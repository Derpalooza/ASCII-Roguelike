#include <iostream>
#include "MenuState.h"

using namespace std; 

MenuState::MenuState()
{
	cout << "Menu init" << endl;
}

void MenuState::handleInput(){
	cout << "Menu input" << endl;
}

void MenuState::update(){
	cout << "Menu update" << endl;
}

void MenuState::draw(){
	cout << "Menu draw" << endl;
}

void MenuState::exit(){
	cout << "Menu exit" << endl;
}