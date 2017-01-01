#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

class Level{
public:
	Level(int stage);		// Load level from the level file specified by the parameter
	int movePlayer(char c);		// Updates the level based on the given input and gives an output detailing the next action
 	void updateEnemies();		// Progress the game and return a new level if the level has been beaten
	void printLevel();		// Print the current level state
	void exit();			// destroys the level object (change to destructor)
	~Level();			// Delete enemy pointers<F8>

private:
	void movePosition(int &posX, int &posY, int &newX, int &newY);	// Moves an entity in the level from one position to another
	void getNewDir(char newDir, int &newX, int &newY);
	void updateStatusBar();
	std::vector<Enemy*> enemies;
	std::vector<std::string> levelArea;
	std::vector<std::string> levelText;
	int levelNumber;
	Player player;
};
