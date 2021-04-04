#include <iostream>
#include "Store.h"
#include "Player.h"
#include "GameSimulator.h"



int main()
{
	GameSimulator* game = new GameSimulator();
	game->Start();




	delete game;
	return 0;
}