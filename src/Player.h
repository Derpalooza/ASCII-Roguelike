#pragma once
#include "Player.h"

class Player{
public:
	Player();
	int posX;
	int posY;
	int currentHP;
	int maxHP;
	int attack;
	int defence;
	int level;
	int currentEXP;
	int maxEXP;
	void EXPGain(int EXP);
	void receiveDmg(int enemyAttack);

private:
};
