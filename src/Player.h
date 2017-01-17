#pragma once

class Player{
public:
	Player();
	int posX;
	int posY;

	int getHP();				// Returns the player's current HP
	int getMaxHP();				// Returns the player's max HP
	int getLevel();				// Returns the player's current level
	int getAttack();			// Returns the player's attack stat	
	int getEXP();				// Returns the player's current EXP
	int getMaxEXP();			// Returns the player's max EXP

	void restoreHP();			// Fully restores the player's HP
	void EXPGain(int EXP);			// Increases the EXP of the player
	void receiveDmg(int enemyAttack);	// Damage reception for Player

private:
	int currentHP;
	int maxHP;
	int attack;
	int defence;
	int level;
	int currentEXP;
	int maxEXP;
};
