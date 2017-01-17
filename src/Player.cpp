#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(){
	cout << "Player created!" << endl;
	maxHP = 50;
	currentHP = maxHP;
	attack = 30;
	defence = 30;
	maxEXP = 75;
	currentEXP = 0;
	level = 1;
}

void Player::EXPGain(int EXP){
	currentEXP += EXP;
	if (currentEXP >= maxEXP){
		level++;
		cout << "Player leveled up!" << endl;
		currentEXP -= maxEXP;
		attack += 3;
		defence += 3;
		maxHP++;
		currentHP++;
		maxEXP++;
	}
}

void Player::receiveDmg(int enemyAttack){
	currentHP -= (int)(10*((float)enemyAttack/(float)defence));
	
	if (currentHP < 0) {
		currentHP = 0;
	}

}

void Player::restoreHP(){
	currentHP = maxHP;
}

int Player::getHP(){
	return currentHP;
}

int Player::getMaxHP(){
	return maxHP;
}

int Player::getLevel(){
	return level;
}

int Player::getAttack(){
	return attack;
}

int Player::getEXP(){
	return currentEXP;
}

int Player::getMaxEXP(){
	return maxEXP;
}
