#include "Player.h"
#include<iostream>

Player::Player()
{
	level = 1;
	health = 100;
	maxHealth = health;
	damage = 3;
	gold = 0;
	currentXP = 0;
}

void Player::checkXP()
{
	srand(0);
	if (currentXP >= xpToNextLevel()) {
		level++;
		damage += 3 + (rand() % 6);
		maxHealth += 100;
		health = maxHealth;
		currentXP = 0;
		std::cout << "Level up! \nXP To next level " << xpToNextLevel() << " " << "New Damage: " << damage << " " << "New Health: " << health << "\n";
	}
}

int Player::xpToNextLevel()
{
	switch (level) {
	case 1:
		return 125;
	case 2:
		return 300;
	case 3:
		return 450;
	case 4:
		return 675;
	case 5:
		return 900;
	}
}

#pragma region Accessors
int Player::getHealth()
{
	return health;
}

int Player::getGold()
{
	return gold;
}

int Player::getXP()
{
	return currentXP;
}

int Player::getLevel()
{
	return level;
}

int Player::getMaxHealth()
{
	return maxHealth;
}

int Player::getDamage()
{
	return damage;
}
#pragma endregion

#pragma region Mutators
void Player::setHealth(int newHealth)
{
	health = newHealth;
}

void Player::setXP(int newXP)
{
	currentXP = newXP;
}

void Player::setGold(int newGold)
{
	gold = newGold;
}

void Player::setDamage(int newDamage)
{
	damage = newDamage;
}
#pragma endregion