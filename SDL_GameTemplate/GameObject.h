#pragma once
#include "Component.h"
#include "SDL_image.h"

class GameObject:public Component

{
public:
	GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y);

	~GameObject();
	void init() override;

	void update() override;

	void draw() override;
	void Update(int a, int b);
	void Update2(int a, int b,int c,int d);
	void Render();
	int getX();
	int getY();
	void setX(int a);
	void setY(int b);

private:

	int _x;
	int _y;
	SDL_Texture* _texture;
	SDL_Rect _srcRectangle;
	SDL_Rect _destRectangle;
	SDL_Renderer* _renderer;
};