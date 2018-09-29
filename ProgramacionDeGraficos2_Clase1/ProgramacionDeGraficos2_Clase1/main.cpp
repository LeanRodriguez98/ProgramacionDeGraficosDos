
#include "Game.h"
#include <iostream>
int main() 
{
	Game * game = new Game();
	
	//Todo Startup
	if (game->start())
	{
		game->loop();
	}
	game->stop();
	delete game;
	std::cin.get();
	return 0;
}