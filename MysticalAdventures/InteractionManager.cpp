#include "InteractionManager.h"
#include <iostream>

InteractionManager::InteractionManager(Player& p) : player(p) {}

void InteractionManager::crossRoads()
{
	std::cout << "You stand in the middle of the crossroads: \n1: Go to the town \n2: Go to the dungeon \n3: Go to the house \n4: Go to the castle \nWhat would you like to do adventurer?\n> ";
	choice;
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Go to the town";
		break;
	case 2:
		std::cout << "Go the the dungeon";
		break;
	case 3:
		std::cout << "Go the house";
		break;
	case 4:
		std::cout << "Go the castle";
		break;
	default:
		std::cout << "Please choose a valid option!";
		crossRoads();
	}
}

#pragma region Town Interactions
void InteractionManager::town()
{
	std::cout << "As you enter the town you see three locations to which you can visit: \n1: The blacksmith \n2: The alchemist \n3: The guild \n4: Go back to the crossroads \nWhat's next? \n> ";
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Go to the blacksmith";
		break;
	case 2:
		std::cout << "Go the the alchemist";
		break;
	case 3:
		std::cout << "Go the guild";
		break;
	case 4:
		crossRoads();
		break;
	default:
		std::cout << "Please choose a valid option!";
		town();
	}
}

#pragma endregion

#pragma region Dungeon Interactions
void InteractionManager::dungeon()
{
	//needs to be expanded to allow players to not always fight enemies
	//e.g find random items to restore health or boost XP
}
#pragma endregion

#pragma region House Interactions
void InteractionManager::house()
{
	if (!houseBought) {
		std::cout << "Ahead of you is an empty yet furbished house for sale. A nice place to restore health without paying for potions. \nBuy? {10000 Gold} \n1: Yes \n2: No \n> ";
		std::cin >> choice;
		switch (choice) {
		case 1: 
			//check if the player has enough gold
			//if have enough gold then call this method again
			break;
		case 2:
			crossRoads();
			break;
		default:
			"Please choose a valid option!";
			house();
			break;
		}
	}
	else
	{
		std::cout << "After entering the house you head to your comfy bed and rest for a few hours. Feeling refreshed your health has been restored to full";
		player.setHealth(player.getMaxHealth());
		crossRoads();
	}
}
#pragma endregion

#pragma region Castle Interactions
void InteractionManager::castle()
{
	//Final boss, only allow the player when they've reached lvl5
}
#pragma endregion