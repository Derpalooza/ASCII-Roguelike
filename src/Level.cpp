#include "Level.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
	TODO: 	-Refactor code so that the movement for the player and enemies use the same function
		-Make Player and Enemy inherit from the same class
		-Delete enemy objects after level is completed
*/

Level::Level(int stage){

	string line;
	ifstream file ("../assets/levels/leveltest2.txt");
	
	if (file.is_open()){
	
		while (getline(file, line)){
			
			levelArea.push_back(line);
			Enemy* newEnemy;
				
			for (int i=0; i<line.length(); i++){
				if (line[i] == '@'){
					
					// Create the player object from position data
					// TODO: make a new constructor for the player object
					cout << "Player identified at (" << i << ", " << levelArea.size()-1 << ")" << endl;
					player.posX = i;
					player.posY = levelArea.size()-1;
					break;
				}
				else if (line[i] == 'S'){
				
					// Push to the vector a pointer to the enemy
					cout << "Enemy identified at (" << i << ", " << levelArea.size()-1 << ")" << endl;
					newEnemy = new Enemy(i, levelArea.size()-1);
					enemies.push_back(newEnemy);
				}
			}
				
		}
	}

	levelNumber = stage;

}

void Level::movePlayer(char c){

	int newX = player.posX, newY = player.posY;

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

	movePosition(player.posX, player.posY, newX, newY);

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

void Level::moveEnemies(){
	
	
	for (int i=0; i < enemies.size(); i++){
		int newX = enemies[i]->posX, newY = enemies[i]->posY;
		
		int newDir = enemies[i]->movePosition();
			
		switch (newDir){
			case 1:
				newY--;
				cout << "Enemy " << i+1 << " moves up" << endl;
				break;

			case 2:
				newX--;
				cout << "Enemy " << i+1 << " moves left" << endl;
				break;

			case 3:
				newY++;
				cout << "Enemy " << i+1 << " moves down" << endl;
				break;
			
			case 4:
				newX++;
				cout << "Enemy " << i+1 << " moves right" << endl;
				break;
		}	
		movePosition(enemies[i]->posX, enemies[i]->posY, newX, newY);
	
	cout << "Enemy at (" << enemies[i]->posX << ", " << enemies[i]->posY << ")\n";
	}
	
	 
}

void Level::printLevel(){
	for (int i=0; i<levelArea.size(); i++){
		cout << levelArea[i] << endl;
	}
	
	cout << "Player position is: (" << player.posX << ", " << player.posY << ")\n"; 
}

void Level::exit(){}
