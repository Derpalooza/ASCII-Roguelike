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

	string levelPath = "../assets/levels/level";
	levelPath.append(1, (char)(stage+48));
	levelPath.append(".txt");
	ifstream file (levelPath);
	
	string line;
	
	if (file.is_open()){
	
		while (getline(file, line)){
			
			levelArea.push_back(line);
			Enemy* newEnemy;
			
			for (int i=0; i<line.length(); i++){
				if (line[i] == '@'){
					
					// Create the player object from position data
					// TODO: make a new constructor for the player object
					player.posX = i;
					player.posY = levelArea.size()-1;
				}

				else if (line[i] == 'S'){
				
					// Push to the vector a pointer to the enemy
					newEnemy = new Enemy(i, levelArea.size()-1);
					enemies.push_back(newEnemy);
				}
			}
				
		}
	}

	levelNumber = stage;

}

int Level::movePlayer(char input){

	int newX = player.posX, newY = player.posY;
	getNewDir(input, newX, newY);
	
	switch(levelArea[newY][newX]){

		case '.': 
			movePosition(player.posX, player.posY, newX, newY);
			return 0;

		case '~':
			return (levelNumber + 1);

		case 'S':
			//find pointer to enemy matching new coords
			int enemyID;
	
			for (int i=0; i < enemies.size(); i++){
				if ((newX == enemies[i]->posX) && (newY == enemies[i]->posY)){
					enemyID = i;
					break;
				}
			}
		
			enemies[enemyID]->receiveDmg(player.attack);
		
			if (enemies[enemyID]->currentHP == 0){
				delete enemies[enemyID];
				enemies[enemyID] = enemies.back();
				enemies.pop_back();
				levelArea[newY][newX] = '.';
				levelText.push_back("Attacked enemy! Enemy has fallen!");
			} 
			
			else {
				string line = "Attacked enemy! Enemy has " + to_string(enemies[enemyID]->currentHP) + "HP remaining.";
				levelText.push_back(line);
			}
			
			player.receiveDmg(enemies[enemyID]->attack);
			
			if (player.currentHP == 0){
				levelText.push_back("The enemy attacked! You have died...");
				return -1;
			}
			else{
				levelText.push_back("The enemy attacked! You have " + to_string(player.currentHP) + "HP remaining.");
			}
			
			return 0;

		default:
			return 0;
	}

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

void Level::getNewDir(char newDir, int& newX, int& newY){
	switch (newDir){
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

}

void Level::updateEnemies(){
	
	// Instead of swapping.
	
	for (int i=0; i < enemies.size(); i++){
		int newX = enemies[i]->posX, newY = enemies[i]->posY;
		
		getNewDir(enemies[i]->movePosition(player.posX, player.posY), newX, newY);
			
		if (levelArea[newY][newX] == '@') { 
			//enemies[i]->attackPlayer(player);
			//levelText.push_back("")	
		}
		
		movePosition(enemies[i]->posX, enemies[i]->posY, newX, newY);
	
	}
	
	 
}

void Level::updateStatusBar(){
	string statusBar = "HP |";
	
	if (player.currentHP > 0){
		int barLength = (int)(20 * ((float)player.currentHP/(float)player.maxHP) + 1);
		
		for (int i=0; i < 20; i++) {
			if (i < barLength) {
				statusBar.append(1, '#');
			}
			else{
				statusBar.append(1, ' ');
			}
		}
	}
	else {
		statusBar.append(20, ' ');
	}
	statusBar.append("| ");
	
	cout << statusBar << player.currentHP << "/" << player.maxHP << endl;
	
}

void Level::printLevel(){
	for (int i=0; i<levelArea.size(); i++){
		cout << levelArea[i] << endl;
	}
	
	updateStatusBar();
	
	for (int i=0; i < levelText.size(); i++){
		cout << levelText[i] << endl;
	}
	
	if (levelText.size() < 2) {
		for (int i=0; i < (2 - levelText.size()); i++){
			cout << "\n";
		}
	}
	
	levelText.clear();
	
}

void Level::exit(){}
