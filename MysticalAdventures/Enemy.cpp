#include "Enemy.h"
Enemy::Enemy(EnemyTypes newEnemyType) {
	enemyType = newEnemyType;
	switch (enemyType) {
	case goblin:
		health = 12;
		damage = 3;
		xpReward = 3;
		goldReward = 5;
		break;
	case bat:
		health = 6;
		damage = 2;
		xpReward = 2;
		goldReward = 3;
		break;
	case skeleton:
		health = 80;
		damage = 3;
		xpReward = 8;
		goldReward = 7;
		break;
	case mage:
		health = 130;
		damage = 7;
		xpReward = 35;
		goldReward = 20;
		break;
	case bandit:
		health = 125;
		damage = 6;
		xpReward = 25;
		goldReward = 25;
		break;
	case orc:
		health = 175;
		damage = 9;
		xpReward = 50;
		goldReward = 50;
		break;
	case rogueKnight:
		health = 225;
		damage = 13;
		xpReward = 125;
		goldReward = 100;
		break;
	case demon:
		health = 250;
		damage = 15;
		xpReward = 160;
		goldReward = 190;
		break;
	case mutatedGoblin:
		health = 200;
		damage = 12;
		xpReward = 110;
		goldReward = 95;
		break;
	case dragon:
		health = 500;
		damage = 17;
		xpReward = 700;
		goldReward = 800;
	}
}

std::string Enemy::toString()
{
	switch (enemyType) {
	case EnemyTypes::goblin: return "Goblin";
	case EnemyTypes::bat: return "Bat";
	case EnemyTypes::skeleton: return "Skeleton";
	case EnemyTypes::mage: return "Mage";
	case EnemyTypes::bandit: return "Bandit";
	case EnemyTypes::orc: return "Orc";
	case EnemyTypes::rogueKnight: return "Rogue Knight";
	case EnemyTypes::demon: return "Demon";
	case EnemyTypes::mutatedGoblin: return "Mutated Goblin";
	}
}

void Enemy::printRewards()
{
	std::cout << "You defeated the " << toString() << "! \nGold Reward: " << goldReward << "\tXP Reward: " << xpReward << "\n";
}

#pragma region Accessors
int Enemy::getHealth() {
	return health;
}

int Enemy::getDamage()
{
	return damage;
}

int Enemy::getXpReward()
{
	return xpReward;
}

int Enemy::getGoldReward()
{
	return goldReward;
}

EnemyTypes Enemy::getEnemyType()
{
	return enemyType;
}
#pragma endregion

#pragma region Mutators
void Enemy::setHealth(int newHealth) {
	health = newHealth;
}
#pragma endregion


