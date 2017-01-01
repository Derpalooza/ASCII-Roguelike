#include <iostream>
#include "MenuState.h"
#include "HelpState.h"
#include "LevelState.h"
#include "conio.h"
#include <fstream>

using namespace std; 

//TODO: Make it so that the title can be read from a file

MenuState::MenuState()
{
	cout << "Menu init" << endl;
	
	menuOptions[0] = "NEW GAME";
	menuOptions[1] = "HELP";
	menuOptions[2] = "QUIT";	
	
	cout << "Sizeof array is: " << sizeof(menuOptions)/sizeof(*menuOptions) << endl;
	
	selected = 0; 

}

State* MenuState::handleInput(){
	//cout << "Menu input" << endl;
	//cout << "selected == " << selected << endl;	

	char c;
	
	while (c != 'w' && c != 's' && c != ' '){
	
		c = getch();
		
		changeSelected(c);	
		
	}
	
	if (c == ' '){ 
		if (menuOptions[selected] == "HELP"){
			return new HelpState();
		}
		else if (menuOptions[selected] == "NEW GAME"){
			return new LevelState();
		}
	}
	
	return NULL;
}

void MenuState::update(){
	cout << "Menu update" << endl;
}

void MenuState::draw(){
	
	State::draw();	
	printTitle();
	
	for (int i=0; i < sizeof(menuOptions)/sizeof(*menuOptions); i++){
		if (i == selected){
			cout << ">";
		}
		
		cout << menuOptions[i] << endl;			
	}

}

void MenuState::changeSelected(char input){
	
	switch (input){
		case 'w':
			selected--;
			break;
		
		case 's':
			selected++;
			break;

		default:
			 break;
	}
	
	if (selected < 0) {
		selected = sizeof(menuOptions)/sizeof(*menuOptions) - 1;
	}
	
	else {
		selected %= sizeof(menuOptions)/sizeof(*menuOptions);
	}
}

void MenuState::printTitle(){
	string line;
	ifstream file ("../title.txt");

	if (file.is_open()){
	
		while (getline (file, line)){
			cout << line << endl;			
		}
	}

	file.close();
}
