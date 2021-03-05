#pragma once
#include <SDL.h>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean() const;
	static SDL_Event event;
	bool running() const { return isRunning;  }
	void notRunning();
	void startMenu();
	void menuscreen();
	void close();
	void restart();
	void out();
	void eat();
	void grow();
	void scoreIcon();
	void canibal();
	void nextLevel();
	void lose();
	void scoreTest();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
