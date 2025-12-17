#include <iostream>
#include "Player.h"
#include "Dungeon.h"
#include "InteractionManager.h"

int main()
{
	Player player;
	Dungeon dungeon(player);
	InteractionManager iM(player, dungeon);
	iM.crossRoads();
}
