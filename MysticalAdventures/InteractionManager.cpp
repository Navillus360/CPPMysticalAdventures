#include "InteractionManager.h"
#include <iostream>

InteractionManager::InteractionManager(Player& p, Dungeon& d) : r_player(p), r_dungeon(d)
{
	choice = 0;
	houseBought = false;
	exploring = false;
	inHouse = false;
	inDungeon = false;
	inTown = false;
	inCastle = false;
}

void InteractionManager::crossRoads()
{
	system("cls");
	exploring = true;
	while (exploring && !inHouse && !inDungeon && !inTown && !inCastle) {
		std::cout << "You stand in the middle of the crossroads: \n1: Go to the town \n2: Go to the dungeon \n3: Go to the house \n4: Go to the castle \nWhere would you like to go adventurer?\n> ";
		choice;
		std::cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			town();
			break;
		case 2:
			system("cls");
			dungeon();
			break;
		case 3:
			system("cls");
			house();
			break;
		case 4:
			system("cls");
			castle();
			break;
		default:
			system("cls");
			std::cout << "Please choose a valid option!\n";
			continue;
		}
	}
}

void InteractionManager::gameEnd(bool playerWon)
{
	switch (playerWon) {
	case true:
		std::cout << "You slain the dragon! \nThe town's citizens recognise you as a hero and the threat around the country has been reduced! \n\n\tGAME OVER";
		break;
	case false:
		std::cout << "You were slain in battle. Whilst your bravery will never be forgotten, \nthe citizens now have no one to save them from the dragons wrath. \n\n\tGAME OVER";
		break;
	}
}

#pragma region Purchaseable assets
void InteractionManager::PurchaseAsset(int cost, PurchaseableAssets asset)
{
	if (r_player.getGold() >= cost) {
		switch (asset) {
		case swordUpgrade:
			//increase players damage
			r_player.setDamage(r_player.getDamage() + 7);
			r_player.setGold(r_player.getGold() - 310);
			std::cout << "Damage increased to " << r_player.getDamage() << "\n";
			break;
		case armourUpgrade:
			//increase the players health
			r_player.setMaxHealth(r_player.getMaxHealth() + 25);
			r_player.setHealth(r_player.getMaxHealth());
			r_player.setGold(r_player.getGold() - 240);
			std::cout << "Health increased to " << r_player.getHealth() << "\n";
			break;
		case tavernRoom:
			//restore players health to max
			r_player.setHealth(r_player.getMaxHealth());
			r_player.setGold(r_player.getGold() - 30);
			std::cout << "After entering the rented room and resting for the night you wake up feeling refreshed with your health restored to full\n";
			break;
		case playerHouse:
			//unlocks the house to restore health for free
			r_player.setGold(r_player.getGold() - 10000);
			houseBought = true;
			break;
		}
	}
	else
	{
		switch (asset) {
		case swordUpgrade:
			std::cout << "You do not have enough gold to buy this upgrade!\n\n";
			break;
		case armourUpgrade:
			std::cout << "You do not have enough gold to buy this upgrade!\n\n";
			break;
		case tavernRoom:
			std::cout << "You do not have enough gold to book a room!\n\n";
			break;
		case playerHouse:
			std::cout << "You do not have enough gold to buy this house!\n\n";
			break;
		}
	}
}
#pragma endregion

#pragma region Town Interactions
void InteractionManager::town()
{
	inTown = true;
	while (inTown) {
		std::cout << "As you enter the town you see three locations to which you can visit: \n1: The blacksmith \n2: The tavern \n3: The guild \n4: Go back to the crossroads \nWhat's next? \n> ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			blacksmith();
			break;
		case 2:
			system("cls");
			tavern();
			break;
		case 3:
			system("cls");
			guild();
			break;
		case 4:
			system("cls");
			inTown = false;
			crossRoads();
			break;
		default:
			system("cls");
			std::cout << "Please choose a valid option!";
			town();
		}
	}
}

void InteractionManager::blacksmith()
{
	std::cout << "Gold: " << r_player.getGold() << "\nEntering the blacksmiths workshop you feel an overwhelming amount of heat in an instant. \nWithout skipping a beat or even stopping the blacksmith looks to you\nwith a somewhat intimidating expressions and coldly asks 'what do you want?' \n1: Upgrade sword {310 Gold + 5 Damage} \n2: Upgrade Armour {240 Gold + 25 Health} \n3: Exit workshop \n> ";
	std::cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		PurchaseAsset(310, swordUpgrade);
		blacksmith();
		break;
	case 2:
		system("cls");
		PurchaseAsset(310, armourUpgrade);
		blacksmith();
		break;
	case 3:
		system("cls");
		town();
		break;
	default:
		system("cls");
		std::cout << "Please choose a valid option!";
		blacksmith();
		break;
	}
}

void InteractionManager::tavern()
{
	std::cout << "Gold: " << r_player.getGold() << "Entering the tavern you are greeted by an old elf who is the owner of the building. After a brief conversation, the elf offers a room for the night, for a price {30 gold + restored health} \n1: Rent room \n2: Exit tavern \n>";
	std::cin >> choice;
	switch (choice) {
	case 1:
		PurchaseAsset(30, tavernRoom);
		tavern();
		break;
	case 2:
		town();
		break;
	default:
		system("cls");
		std::cout << "Please choose a valid option!\n";
		tavern();
		break;
	}
}

void InteractionManager::guild()
{
	if (r_player.getLevel() == 5) {
		std::cout << "Upon entering the guild you see the main area huddled with adventures of diffrent ranks murmuring amongst each other. The only words that you can piece together is 'Dragon' and 'Castle'. Whatever it is, seems like no one is going out there to investigate. Better make sure your well prepared adventurer... \n1: Exit \n> ";
	}
	else
	{
		std::cout << "Entering the guild you see various types of adventurers in the main area, some in groups, some by themselves and some of the popular ones trying to outshine the other. Walking through to the crowd and reaching the reception you are greeted by a staff member on how you can rank up within the guild: \n\n'Heading to the dungeon from the crossroads you'll find items which can restore your health or give you some extra XP, but the main objective is to defeat the enemies you may encounter as they'll give you both XP and gold rewards. \n\nSounds easy right? Well, as you level up so will the monsters so make sure you can defeat them or run if you can. Good luck!' \n1: Exit \n> ";
	}
	std::cin >> choice;
	switch (choice) {
	case 1:
		town();
		break;
	default:
		system("cls");
		std::cout << "Please choose a valid option!\n";
		guild();
		break;
	}
}
#pragma endregion

#pragma region Dungeon Interactions
void InteractionManager::dungeon()
{
	inDungeon = true;
	r_dungeon.generateDungeon();
	Enemy enemy = r_dungeon.getRandomEnemy();
	std::cout << "You encountered a " << enemy.toString() << "!\n";
	while (inDungeon)
		dungeonCombat(enemy);
}

void InteractionManager::dungeonCombat(Enemy& enemy)
{
	while (r_player.getHealth() > 0 || enemy.getHealth() > 0) {
		std::cout << "Player Health: " << r_player.getHealth() << "\tEnemy Health: " << enemy.getHealth() << "\n1: Attack \n2: Flee \n> ";
		if (r_player.getHealth() <= 0) {
			gameEnd(false);
			break;
		}
		else if (enemy.getHealth() <= 0) {
			enemy.printRewards();
			r_player.setGold(r_player.getGold() + enemy.getGoldReward());
			r_player.setXP(r_player.getXP() + enemy.getXpReward());
			r_dungeon.removeEnemy(enemy);
			combatEnd();
			break;
		}
		std::cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			enemy.setHealth(enemy.getHealth() - r_player.getDamage());
			r_player.setHealth(r_player.getHealth() - enemy.getDamage());
			break;
		case 2:
			system("cls");
			flee();
			break;
		default:
			system("cls");
			std::cout << "Please choose a valid option!\n";
			break;
		}
	}
}

void InteractionManager::combatEnd() {
	if (r_dungeon.getEnemies().size() == 0) {
		std::cout << "\nYou cleared this dungeon! Come back again to clear another. \n1: Exit \n> ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			inDungeon = false;
			crossRoads();
			break;
		default:
			inDungeon = false;
			crossRoads();
			break;
		}
	}
	else {
		std::cout << "\nThis enemy has been defeated! \nWould you like to fight more enemies or leave ? \n1 : Fight another enemy \n2 : Leave the dungeon \n> ";
		std::cin >> choice;
		switch (choice) {
		case 1:
		{
			Enemy enemy = r_dungeon.getRandomEnemy();
			std::cout << "You encountered a " << enemy.toString() << "!\n";
			dungeonCombat(enemy);
			break;
		}
		break;
		case 2:
			inDungeon = false;
			crossRoads();
			break;
		default:
			std::cout << "Please choose a valid option!\n";
			break;
		}
	}
}

void InteractionManager::flee() {
	srand(time(0));
	int fleeChance = rand() % 100;
	if (fleeChance >= 50) {
		inDungeon = false;
		crossRoads();
	}
	else
		std::cout << "Your attempt to flee failed!";
}
#pragma endregion

#pragma region House Interactions
void InteractionManager::house()
{
	inHouse = true;
	while (inHouse) {
		if (!houseBought) {
			std::cout << "Gold: " << r_player.getGold() << "\nAhead of you is an empty yet furbished house for sale. A nice place to restore health without paying for potions. \nBuy? {10000 Gold} \n1: Yes \n2: No \n> ";
			std::cin >> choice;
			switch (choice) {
			case 1:
				PurchaseAsset(10000, playerHouse);
				house();
				break;
			case 2:
				inHouse = false;
				crossRoads();
				break;
			default:
				system("cls");
				std::cout << "Please choose a valid option!\n";
				house();
				break;
			}
		}
		else
		{
			std::cout << "After entering the house you head to your comfy bed and rest for a few hours. Feeling refreshed your health has been restored to full.";
			r_player.setHealth(r_player.getMaxHealth());
			crossRoads();
			inHouse = false;
		}
	}
}
#pragma endregion

#pragma region Castle Interactions
void InteractionManager::castle()
{
	inCastle = true;
	while (inCastle) {
		if (r_player.getLevel() >= 5) {
			std::cout << "Upon arriving at the castle enterance you only hear the eerie silence in the wind and an intense aura coming from the air, one you feel more than ready toward and face the danger head on. \n1: Enter the castle <NO RETURN!> \n2: Exit \n> ";
			std::cin >> choice;
			switch (choice) {
			case 1:
				finalBossFight();
			case 2:
				inCastle = false;
				crossRoads();
				break;
			default:
				system("cls");
				std::cout << "Please choose a valid option!\n";
				castle();
				break;
			}
		}
		else {
			std::cout << "Upon arriving at the castle enterance you only hear the eerie silence in the wind and an intense aura coming from the air. Hanging around for too long will certainly end in your demise, come back when your stronger. \n1: Exit \n>";
			std::cin >> choice;
			switch (choice) {
			case 1:
				inCastle = false;
				crossRoads();
				break;
			default:
				system("cls");
				std::cout << "Please choose a valid option!\n";
				castle();
			}
		}
	}
	//Final boss, only allow the player inside when they've reached lvl5
}

void InteractionManager::finalBossFight() {
	Enemy finalBoss = EnemyTypes::dragon;
	while (r_player.getHealth() > 0 || finalBoss.getHealth() > 0) {
		std::cout << "Player Health: " << r_player.getHealth() << "\tEnemy Health: " << finalBoss.getHealth() << "\n1: Attack \n> ";
		std::cin >> choice;
		if (r_player.getHealth() <= 0) {
			gameEnd(false);
			break;
		}
		else if (finalBoss.getHealth() <= 0) {
			gameEnd(true);
			break;
		}
		switch (choice) {
		case 1:
			finalBoss.setHealth(finalBoss.getHealth() - r_player.getDamage());
			r_player.setHealth(r_player.getHealth() - finalBoss.getDamage());
		default:
			std::cout << "Please choose a valid option!";
		}
	}
}
#pragma endregion