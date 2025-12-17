#pragma once
#include "Player.h"
#include "Dungeon.h"
#include "PurchaseableAssets.h"

class InteractionManager {
public:
	InteractionManager(Player& p, Dungeon& d);

	void crossRoads();
	void PurchaseAsset(int cost, PurchaseableAssets assets);
	void gameEnd(bool playerWon);
	
	//Town interactions (buy items)
	void town();
	void blacksmith();
	void tavern();
	void guild();
	
	//Dungeon interactions (fight enemies)
	void dungeon();
	void dungeonCombat(Enemy& enemy);
	void combatEnd();
	void flee();
	
	//House interaction (purchasable property)
	void house();
	
	//Castle interactions (final boss)
	void castle();
	void finalBossFight();

private:
	std::string choice;
	bool houseBought;
	bool exploring, inHouse, inDungeon, inTown, inCastle, isGameEnd;
	Player& r_player;
	Dungeon& r_dungeon;
	enum class string_code {
		cmd1, cmd2, cmd3, cmd4, unknown
	};
	string_code hashString(const::std::string str);
};