#pragma once
#include "Player.h"

class InteractionManager {
public:
	InteractionManager(Player& p);
	
	void crossRoads();
	
	//Town interactions (buy items)
	void town();
	void blacksmith();
	void alchemist();
	void guild();
	
	//Dungeon interactions (fight enemies)
	void dungeon();
	
	//House interaction (purchasable property)
	void house();
	
	//Castle interactions (final boss)
	void castle();

private:
	int choice;
	bool houseBought;
	Player& player;
};