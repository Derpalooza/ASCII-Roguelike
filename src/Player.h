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
	void receiveDmg(int enemyAttack);

private:
};
