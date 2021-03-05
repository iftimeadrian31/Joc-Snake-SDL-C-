#include "Map.h"
#include "TextureManager.h"
#include <SDL.h>
#include <iostream>
#include <fstream>
using namespace std;

int lvl1[34][60];
int lvl2[34][60];
int lvl3[34][60];
int ending[34][60];

Map::Map(SDL_Renderer* renderer,int level)
{
	this->renderer = renderer;
	wall = TextureManager::LoadTexture("assets/wall.png", renderer);
	grass = TextureManager::LoadTexture("assets/grass.png", renderer);
	dirt = TextureManager::LoadTexture("assets/dirt.png", renderer);
	water = TextureManager::LoadTexture("assets/water.png", renderer);
	black = TextureManager::LoadTexture("assets/Black.png", renderer);
	brick= TextureManager::LoadTexture("assets/brick.png", renderer);
	carpet= TextureManager::LoadTexture("assets/carpet.png", renderer);

	if (level == 1)
	{
		ifstream fin("lvl1.txt");
		for (int i = 0; i < 34; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				fin>> lvl1[i][j];
			}
		}
		LoadMap(lvl1);
	}
	else if(level==2)
	{
		ifstream fin("lvl2.txt");
		for (int i = 0; i < 34; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				fin >> lvl2[i][j];
			}
		}
		LoadMap(lvl2);
	}
	else if (level == 3)
	{
		ifstream fin("lvl3.txt");
		for (int i = 0; i < 34; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				fin >> lvl3[i][j];
			}
		}
		LoadMap(lvl3);
	}
	else if (level == 4)
	{
		ifstream fin("lvl4.txt");
		for (int i = 0; i < 34; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				fin >> ending[i][j];
			}
		}
		LoadMap(ending);

	}
	else 
	{
		throw std::invalid_argument("valoarea nu are textura");
	}
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;
	dest.x = 0;
	dest.y = 0;
	dest.w = 32;
	dest.h = 32;

}

Map::~Map()
{

}

void Map::LoadMap(int arr[34][60])
{
	for (int row = 0; row < 34; row++)
	{
		for (int column = 0; column < 60; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 34; row++)
	{
		for (int column = 0; column < 60; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;
			switch (type)
			{
			case 0:
				{
				TextureManager::Draw(water, src, dest, renderer);
					break;
				}
			case 1:
			{
				TextureManager::Draw(grass, src, dest, renderer);
				break;
			}
			case 2:
			{
				TextureManager::Draw(wall, src, dest, renderer);
				break;
			}
			case 3:
			{
				TextureManager::Draw(black, src, dest, renderer);
				break;
			}
			case 4:
			{
				TextureManager::Draw(dirt, src, dest, renderer);
				break;
			}
			case 5:
			{
				TextureManager::Draw(brick, src, dest, renderer);
				break;
			}
			case 6:
			{
				TextureManager::Draw(carpet, src, dest, renderer);
				break;
			}
			default:
				throw std::invalid_argument("valoarea nu are textura");
				break;
			}
		}
	}
}

int Map::exceptie() {
	try {
		DrawMap();
	}
	catch (const std::invalid_argument & e) {
		return 1;
	}
}