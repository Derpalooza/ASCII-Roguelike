#include <iostream>
#include "HelpState.h"
#include "MenuState.h"
#include "conio.h"
#include <string>
#include <fstream>

using namespace std;

HelpState::HelpState(){}

State* HelpState::handleInput(){

	char c = getch();
	return new MenuState();
}

void HelpState::update(){
	//cout << "Help update" << endl;
} 

void HelpState::draw(){
	State::draw();
	
	string line;
	ifstream file("../assets/help_screen.txt");
	
	if (file.is_open()){
		while (getline(file, line)){
			cout << line << endl;
		}
	}
}

