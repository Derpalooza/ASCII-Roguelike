#pragma once
#include <vector>
#include <string>

class Level{
public:
	Level(int stage);		// Load level from the level file specified by the parameter
	void handleInput(char c);	// Make changes to the state based on the given input
 	Level* update();		// Progress the game and return a new level if the level has been beaten
	void printLevel();		// Print the current level state
	void exit();			// destroys the level object (change to destructor)

private:
	std::vector<std::string> levelArea;
	int levelNumber;
	// std::vector<Enemy> enemies;
	// Player player;
};
