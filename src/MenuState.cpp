#include <iostream>
#include "MenuState.h"
#include "conio.h"

using namespace std; 

//TODO: Make it so that the title can be read from a file

MenuState::MenuState()
{
	cout << "Menu init" << endl;
	
	menuOptions[0] = "NEW GAME";
	menuOptions[1] = "HELP";
	menuOptions[2] = "OTHER";	
	
	cout << "Sizeof array is: " << sizeof(menuOptions)/sizeof(*menuOptions) << endl;
	
	selected = 0; 

}

void MenuState::handleInput(){

	char c;
	
	while (c != 'w' && c != 's'){
	
		c = getch();
		
		changeSelected(c);	
		
	}
}

void MenuState::update(){

}

void MenuState::draw(){
		
	string clearstring(100, '\n');
	cout << clearstring << endl;	
	printTitle();
	
	for (int i=0; i < sizeof(menuOptions)/sizeof(*menuOptions); i++){
		if (i == selected){
			cout << ">";
		}
		
		cout << menuOptions[i] << endl;			
	}

}

void MenuState::exit(){

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
		selected *= -1;
	}
	
	selected %= sizeof(menuOptions)/sizeof(*menuOptions);
}

void MenuState::printTitle(){
	cout <<" _____                        " << endl;
	cout <<"|  __ \\                       " << endl;
	cout <<"| |__) |___   __ _ _   _  ___ " << endl;
        cout <<"|  _  // _ \\ / _` | | | |/ _ \\" << endl;
        cout <<"| | \\ \\ (_) | (_| | |_| |  __/" << endl;
        cout <<"|_|  \\_\\___/ \\__, |\\__,_|\\___|" << endl;
        cout <<"              __/ |           " << endl;
        cout <<"             |___/            " << endl;
}
