#include <SFML\Graphics.hpp>
#include "Game.h"


int main()
{
	srand(time(NULL));
	Game game;
	game.runGame();
	return EXIT_SUCCESS;
}
