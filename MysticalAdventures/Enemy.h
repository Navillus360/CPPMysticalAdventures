#pragma once
#include"EnemyTypes.h"
#include<iostream>
class Enemy {
public:
	Enemy(EnemyTypes newEnemyType);
	std::string toString();

#pragma region Accessors
	int getHealth();
	int getDamage();
	int getXpReward();
	int getGoldReward();
	EnemyTypes getEnemyType();
#pragma endregion


private:
	int health, damage, xpReward, goldReward;
	EnemyTypes enemyType;
};