#include <sdl.h>
#include "Game.h"


Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();

	int windowWidth = 1024;
	int windowHeight = 768;
	game->init("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, true);
	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}