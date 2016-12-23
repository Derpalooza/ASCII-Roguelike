#include "Level.h"
#include <iostream>
#include <fstream>

using namespace std;

Level::Level(int stage){

	// TODO: Comb level file for player position and record in player object
		
	string line;
	ifstream file ("../level/leveltest2.txt");
	
	player = new Player();
	 	
	if (file.is_open()){
	
		while (getline(file, line)){
			
			levelArea.push_back(line);
	
			for (int i=0; i<line.length(); i++){
				if (line[i] == '@'){
					cout << "Player identified at (" << i << ", " << levelArea.size()-1 << ")" << endl;
					player->posX = i;
					player->posY = levelArea.size()-1;
					break;
				}
			}
				
		}
	}

	levelNumber = stage;

}

void Level::handleInput(char c){

	int newX = player->posX, newY = player->posY;

	switch(c) {
		case 'w':
			newY--;
			break;
		case 'a':
			newX--;
			break;
		case 's':
			newY++;
			break;
		case 'd':
			newX++;
			break;
	}

	movePosition(player->posX, player->posY, newX, newY);

}

void Level::movePosition(int &posX, int &posY, int &newX, int &newY){
	
	if (levelArea[newY][newX] == '.'){

		levelArea[posY][posX] ^= levelArea[newY][newX];
		levelArea[newY][newX] ^= levelArea[posY][posX];
		levelArea[posY][posX] ^= levelArea[newY][newX];
		
		posX ^= newX;
		newX ^= posX;
		posX ^= newX;

		posY ^= newY;
		newY ^= posY;
		posY ^= newY;
	}		
}

Level* Level::update(){}

void Level::printLevel(){
	for (int i=0; i<levelArea.size(); i++){
		cout << levelArea[i] << endl;
	}
	
	cout << "Player position is: (" << player->posX << ", " << player->posY << ")\n"; 
}

void Level::exit(){}
