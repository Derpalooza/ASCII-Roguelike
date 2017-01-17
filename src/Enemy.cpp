#include "Enemy.h"
#include <random>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

Enemy::Enemy(int posX, int posY){
	this->posX = posX;
	this->posY = posY;
	maxHP = 30;
	attack = 20;
	defence = 20;
	currentHP = maxHP;
	EXPYield = 30;
}

char Enemy::movePosition(int posX, int posY){

	int dx = this->posX - posX;
	int dy = this->posY - posY;

	int a_dx = abs(dx);
	int a_dy = abs(dy);

	int proximity = 7;

	if ( (dx * dx) + (dy * dy) <= (proximity * proximity) ){
		
		if (a_dx >= a_dy){
			if (dx > 0){ 
				return 'a'; 
			}
			else if (dx < 0) {
				return 'd';
			}
		}
		
		else {
			if (dy > 0){
				return 'w';
			}
			else if (dy < 0){
				return 's';
			}
		}
	}	
	

	static default_random_engine randomGenerator(time(NULL));
	uniform_int_distribution<int> enemyDir(1, 6);
	
	switch(enemyDir(randomGenerator)){
		case 1:
			return 'w';
		case 2:
			return 'a';
		case 3:
			return 's';
		case 4:
			return 'd';
		default:
			return ' ';
	}
		
}

void Enemy::receiveDmg(Player* player){
	currentHP -= 10 * (player->getAttack()/this->defence);
	
	if (currentHP <= 0){
		currentHP = 0;
		player->EXPGain(this->EXPYield);
	}
}

int Enemy::getHP(){
	return currentHP;
}

int Enemy::getMaxHP(){
	return maxHP;
}

int Enemy::getAttack(){
	return attack;
}
