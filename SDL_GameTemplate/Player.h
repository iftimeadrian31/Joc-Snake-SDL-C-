#pragma once
#include "Component.h"
#include "GameObject.h"
#include "SDL.h"

class Player : public GameObject
{
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};
	int directia;
	int o = 0;
	int posxp[30] = { 192,512,256,768,1280,1600,1408,320,1792,704,192,448,1088,1152,320,64,1216,448,704,1792,768,448,256,1600,128,320,448,1664,896,896 };
	int posyp[30] = { 192,256,768,448,192,512,320,640,704,128,960,128,384,768,384,960,576,832,768,64,768,832,128,64,704,832,192,768,448,768 };
public:
   Player() = default;
   Player(const char* path, SDL_Renderer* renderer);
   int Hy0;
   int Hx0;
	void setTex(const char* path);

	void init() override;

	void update() override;

	void draw() override;
	bool out1();
	bool out2();
	bool out3();
	int score();
	int getY();
	int getX();
	int eat();
	int  getDirectia();
	void resetDirectia();
	void reset();
	int getPosX(int i);
	int getPosY(int i);

};
