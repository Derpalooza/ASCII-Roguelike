#include "Enemy.h"
#include <random>
#include <ctime>
#include <stdio.h>
#include <cmath>

using namespace std;

Enemy::Enemy(int posX, int posY){
	this->posX = posX;
	this->posY = posY;
	maxHP = 30;
	attack = 20;
	defence = 20;
	currentHP = maxHP;
}

//Make it so that proximity depends on the level

char Enemy::movePosition(int posX, int posY){

	/*
		1 - up, 2 - left, 3 - down, 4 - right
	*/

	int dx = this->posX - posX;
	int dy = this->posY - posY;

	int a_dx = abs(dx);
	int a_dy = abs(dy);

	int proximity = 7;

	if ( (dx * dx) + (dy * dy) <= (proximity * proximity) ){
		
		if (a_dx >= a_dy){
			if (dx > 0){ 
				//printf("dx = %d, dy = %d, Enemy must move left\n", dx, dy);
				return 'a'; 
			}
			else if (dx < 0) {
				//printf("dx = %d, dy = %d, Enemy must move right\n", dx, dy);
				return 'd';
			}
		}
		
		else {
			if (dy > 0){
				//printf("dx = %d, dy = %d, Enemy must move up\n", dx, dy);
				return 'w';
			}
			else if (dy < 0){
				//printf("dx = %d, dy = %d, Enemy must move down\n", dx, dy);
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

void Enemy::receiveDmg(int playerAttack){
	currentHP -= 10 * (playerAttack/defence);
	
	if (currentHP < 0){
		currentHP = 0;
	}
}
