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
		attack++;
		defence++;
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

