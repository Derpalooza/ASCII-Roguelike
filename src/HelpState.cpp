#include <iostream>
#include "HelpState.h"
#include "MenuState.h"
#include "conio.h"
#include <string>

using namespace std;

HelpState::HelpState(){}

State* HelpState::handleInput(){
	//cout << "Help input" << endl;

	char c;
	c = getch();

	return new MenuState();
}

void HelpState::update(){
	//cout << "Help update" << endl;
} 

void HelpState::draw(){
	//cout << "Help draw" << endl;
	string clearString(100, '\n');
	cout << clearString << endl;
	cout << "YE OLDE HELP SCREEN" << endl;
	cout << "PRESS ANY KEY TO CONTINUE" << endl;
}

void HelpState::exit(){
	//cout << "Help exit" << endl;
}
