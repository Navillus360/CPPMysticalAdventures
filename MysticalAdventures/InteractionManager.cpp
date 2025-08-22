#include "InteractionManager.h"
#include <iostream>

InteractionManager::InteractionManager(Player& p, Dungeon& d) : r_player(p), r_dungeon(d) {}

void InteractionManager::crossRoads()
{
	std::cout << "You stand in the middle of the crossroads: \n1: Go to the town \n2: Go to the dungeon \n3: Go to the house \n4: Go to the castle \nWhat would you like to do adventurer?\n> ";
	choice;
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Go to the town";
		town();
		break;
	case 2:
		std::cout << "Go the the dungeon";
		dungeon();
		break;
	case 3:
		std::cout << "Go the house";
		house();
		break;
	case 4:
		std::cout << "Go the castle";
		castle();
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
		blacksmith();
		break;
	case 2:
		std::cout << "Go the the tavern";
		tavern();
		break;
	case 3:
		std::cout << "Go the guild";
		guild();
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
		//check if player has enough gold
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
	if (r_player.getLevel() == 5) {
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
	Enemy enemy = r_dungeon.getRandomEnemy();
	std::cout << "You encountered a " << enemy.toString();
	while (r_player.getHealth() > 0 || enemy.getHealth() > 0) {
		std::cout << "Player Health: " << r_player.getHealth() << "\tEnemy Health: " << enemy.getHealth();
	}
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
		r_player.setHealth(r_player.getMaxHealth());
		crossRoads();
	}
}
#pragma endregion

#pragma region Castle Interactions
void InteractionManager::castle()
{
	if (r_player.getLevel() >= 5) {
		std::cout << "Upon arriving at the castle enterance you only hear the eerie silence in the wind and an intense aura coming from the air, one you feel more than ready toward and face the danger head on. \n1: Enter the castle <NO RETURN!> \n2: Exit \n> ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			//enter combat with the final boss
		case 2:
			crossRoads();
		default:
			std::cout << "Please choose a valid option!";
			castle();
		}
	}
	else {
		std::cout << "Upon arriving at the castle enterance you only hear the eerie silence in the wind and an intense aura coming from the air. Hanging around for too long will certainly end in your demise, come back when your stronger. \n1: Exit \n>";
		std::cin >> choice;
		switch (choice) {
		case 1:
			crossRoads();
		default:
			std::cout << "Please choose a valid option!";
			castle();
		}
	}
	//Final boss, only allow the player inside when they've reached lvl5
}
#pragma endregion
