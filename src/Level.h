#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

class Level{
public:
	Level(int stage);		// Load level from the level file specified by the parameter
	void movePlayer(char c);	// Make changes to the state based on the given input
 	void updateEnemies();		// Progress the game and return a new level if the level has been beaten
	void printLevel();		// Print the current level state
	void exit();			// destroys the level object (change to destructor)

private:
	void movePosition(int &posX, int &posY, int &newX, int &newY);	// Moves an entity in the level from one position to another
	std::vector<Enemy*> enemies;
	std::vector<std::string> levelArea;
	void getNewDir(char newDir, int &newX, int &newY);
	int levelNumber;
	Player player;
};
