#pragma once

class Enemy{
public:
	Enemy(int posX, int posY);
	int currentHP;
	int maxHP;
	int attack;
	int defence;
	int posX;
	int posY;
	void receiveDmg(int playerAttack);
	char movePosition(int posX, int posY);
};
