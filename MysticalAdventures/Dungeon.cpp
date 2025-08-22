#include "Dungeon.h"

Dungeon::Dungeon(Player& p) : player(p) {}

void Dungeon::generateDungeon()
{
	srand(time(0));
	numOfEnemies = 1 + rand() % 21;
	for (int i = 0; i < numOfEnemies; i++) {
		createEnemy();
	}
}

Enemy Dungeon::getRandomEnemy()
{
	int index = rand() % enemies.size();
	Enemy randomEnemy = enemies[index];
	return randomEnemy;
}

void Dungeon::createEnemy()
{
	switch (player.getLevel()) {
	case 1: {
		int randEnemyIndex = rand() % 2;
		EnemyTypes enemyType = static_cast<EnemyTypes>(randEnemyIndex);
		Enemy randomEnemy(enemyType);
		enemies.push_back(randomEnemy);
	}
	case 2: {
		int randEnemyIndex = rand() % 3;
		EnemyTypes enemyType = static_cast<EnemyTypes>(randEnemyIndex);
		Enemy randomEnemy(enemyType);
		enemies.push_back(randomEnemy);
		break;
	}
	case 3: {
		int randEnemyIndex = rand() % 4;
		EnemyTypes enemyType = static_cast<EnemyTypes>(randEnemyIndex);
		Enemy randomEnemy(enemyType);
		enemies.push_back(randomEnemy);
		break;
	}

	case 4: {
		int randEnemyIndex = rand() % 5;
		EnemyTypes enemyType = static_cast<EnemyTypes>(randEnemyIndex);
		Enemy randomEnemy(enemyType);
		enemies.push_back(randomEnemy);
		break;
	}

	case 5: {
		int randEnemyIndex = rand() % 6;
		EnemyTypes enemyType = static_cast<EnemyTypes>(randEnemyIndex);
		Enemy randomEnemy(enemyType);
		enemies.push_back(randomEnemy);
		break;
	}
	}
}