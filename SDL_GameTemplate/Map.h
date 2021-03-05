#pragma once
#include <SDL_image.h>

class Map
{
public:
	Map(SDL_Renderer* renderer,int level);
	~Map();

	void LoadMap(int arr[34][60]);
	void DrawMap();
	int exceptie();

private:
	SDL_Renderer* renderer;
	SDL_Rect src, dest;
	SDL_Texture* wall;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* black;
	SDL_Texture* dirt;
	SDL_Texture* brick;
	SDL_Texture* carpet;
	int map[34][60];
};