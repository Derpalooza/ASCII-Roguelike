#include <iostream>
#include "HelpState.h"
#include "MenuState.h"
#include "conio.h"
#include <string>
#include <fstream>

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
	
	string line;
	ifstream file("../assets/help_screen.txt");
	
	if (file.is_open()){
		while (getline(file, line)){
			cout << line << endl;
		}
	}
}

void HelpState::exit(){
	//cout << "Help exit" << endl;
}
