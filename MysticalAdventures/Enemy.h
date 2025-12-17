#pragma once
#include"EnemyTypes.h"
#include<iostream>
class Enemy {
public:
	Enemy(EnemyTypes newEnemyType);
	std::string toString();
	void printRewards();
	bool operator==(const Enemy& other) const {
		return id == other.id;
	}

#pragma region Accessors
	int getHealth();
	int getDamage();
	int getXpReward();
	int getGoldReward();
	EnemyTypes getEnemyType();
#pragma endregion

#pragma region Mutators
	void setHealth(int newHealth);
#pragma endregion

private:
	int health, damage, xpReward, goldReward, id;
	EnemyTypes enemyType;
};