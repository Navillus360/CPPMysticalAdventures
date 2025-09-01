#pragma once
#include <vector>
#include "Enemy.h"
#include "EnemyTypes.h"
#include "Player.h"
class Dungeon {
public: 
	Dungeon(Player& p);
	void generateDungeon();
	Enemy getRandomEnemy();
	void removeEnemy(Enemy& enemy);
	std::vector<Enemy> getEnemies();

private:
	int numOfEnemies;
	std::vector<Enemy> enemies;
	void createEnemy();
	Player& player;
};