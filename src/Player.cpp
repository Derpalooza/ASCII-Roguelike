#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(){
	cout << "Player created!" << endl;
	maxHP = 50;
	currentHP = maxHP;
	attack = 30;
	defence = 30;
}

void Player::receiveDmg(int enemyAttack){
	currentHP -= (int)(10*((float)enemyAttack/(float)defence));
	
	if (currentHP < 0) {
		currentHP = 0;
	}

	cout << currentHP << endl;
}

