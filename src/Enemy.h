#pragma once
#include "Player.h"
class Enemy{
public:
	Enemy(int posX, int posY);
	int currentHP;
	int maxHP;
	int attack;
	int defence;
	int posX;
	int posY;
	int EXPYield;
	void receiveDmg(Player* player);
	char movePosition(int posX, int posY);
};
