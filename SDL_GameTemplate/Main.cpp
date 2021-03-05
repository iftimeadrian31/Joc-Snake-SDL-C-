//Using SDL and standard IO
#include "Game.h"
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main(int argc, char* args[])
{
	const int fps = 60;
	// max time between frames
	const int frameDelay = 10000 / fps;
	Game *game = new Game();

	game->init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (game->running())
	{
		Uint32 frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		const int frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}


	game->clean();
	delete game;
	return 0;
}