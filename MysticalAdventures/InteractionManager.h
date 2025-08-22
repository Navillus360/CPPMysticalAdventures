#pragma once
#include "Player.h"
#include "Dungeon.h"

class InteractionManager {
public:
	InteractionManager(Player& p, Dungeon& d);
	
	void crossRoads();
	
	//Town interactions (buy items)
	void town();
	void blacksmith();
	void tavern();
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
	Player& r_player;
	Dungeon& r_dungeon;
};