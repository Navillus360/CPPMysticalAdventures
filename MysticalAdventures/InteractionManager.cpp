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
	std::cout << "As you enter the town you see three locations to which you can visit: \n1: The blacksmith \n2: The tavern \n3: The guild \n4: Go back to the crossroads \nWhat's next? \n> ";
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Go to the blacksmith";
		break;
	case 2:
		std::cout << "Go the the tavern";
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

void InteractionManager::blacksmith()
{
	std::cout << "Entering the blacksmiths workshop you feel an overwhelming amount of heat in an instant. Without skipping a beat or even stopping the blacksmith looks to you with a somewhat intimidating expressions and coldly asks . \n1: Upgrade sword {310 Gold + 5 Damage} \n2: Upgrade Armour {240 Gold + 25 Health} \n3: Exit workshop \n> ";
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Sword upgraded";
		break;
	case 2:
		std::cout << "Armour upgraded";
	case 3:
		town();
	default:
		std::cout << "Please choose a valid option!";
		blacksmith();
	}
}

void InteractionManager::tavern()
{
	std::cout << "Entering the tavern you are greeted by an old elf who is the owner of the building. After a brief conversation, the elf offers a room for the night, for a price {30 gold + restored health} 1: Rent room \n2: Exit tavern \n>"; 
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Health fully restored";
		break;
	case 2:
		town();
	default:
		std::cout << "Please choose a valid option!";
		tavern();
	}
}

void InteractionManager::guild()
{
	if (player.getLevel() == 5) {
		std::cout << "Upon entering the guild you see the main area huddled with adventures of diffrent ranks murmuring amongst each other. The only words that you can piece together is 'Dragon' and 'Castle'. Whatever it is, seems like no one is going out there to investigate. Better make sure your well prepared adventurer... \n1: Exit \n> ";
	}
	else
	{
		std::cout << "Entering the guild you see various types of adventurers in the main area, some in groups, some by themselves and some of the popular ones trying to outshine the other. Walking through to the crowd and reaching the reception you are greeted by a staff member on how you can rank up within the guild: \n\n'Heading to the dungeon from the crossroads you'll find items which can restore your health or give you some extra XP, but the main objective is to defeat the enemies you may encounter as they'll give you both XP and gold rewards. \n\nSounds easy right? Well, as you level up so will the monsters so make sure you can defeat them or run if you can. Good luck!' 1: Exit \n> ";
	}
	std::cin >> choice;
	switch (choice) {
	case 1:
		town();
	default:
		std::cout << "Please choose a valid option!";
		guild();
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