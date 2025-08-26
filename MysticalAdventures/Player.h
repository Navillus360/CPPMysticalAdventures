#pragma once
class Player {
public:
	Player();

	void checkXP();

#pragma region Accessors
	int getHealth();
	int getGold();
	int getXP();
	int getLevel();
	int getMaxHealth();
	int getDamage();
#pragma endregion

#pragma region Mutators
	void setHealth(int newHealth);
	void setXP(int newXP);
	void setGold(int newGold);
	void setDamage(int newDamage);
#pragma endregion

private:
	int xpToNextLevel();
	int health, maxHealth, damage, currentXP;
	int gold, level;
};