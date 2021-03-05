#include "GameObject.h"
#include "TextureManager.h"
#include <SDL.h>

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y)
{
   _renderer = renderer;
   _texture = TextureManager::LoadTexture(textureSheet, _renderer);
   _x = x;
   _y = y;
}

GameObject::~GameObject() = default;

void GameObject::draw()
{
	TextureManager::Draw(_texture,_srcRectangle,_destRectangle,_renderer);
}
void GameObject::update() {
	_srcRectangle.h = 32;
	_srcRectangle.w = 32;
	_srcRectangle.x = 0;
	_srcRectangle.y = 0;

	_destRectangle.x = 0;
	_destRectangle.y = 0;
	_destRectangle.w = 64;
	_destRectangle.h = 64;
}
void GameObject::init()
{
	_destRectangle.x = 896;
	_destRectangle.y = 512;
	_srcRectangle.x = 32;
	_srcRectangle.y = 32;
	_srcRectangle.w = _srcRectangle.h = 32;
	_destRectangle.w = _destRectangle.h = 64;
}
void GameObject::Update(int a,int b) {
	_srcRectangle.h = 32;
	_srcRectangle.w = 32;
	_srcRectangle.x = 0;
	_srcRectangle.y = 0;

	_x = a;
	_y = b;
	_destRectangle.x = a;
	_destRectangle.y = b;
	_destRectangle.w = 64;
	_destRectangle.h = 64;
}
void GameObject::Update2(int a, int b,int c,int d) {
	_srcRectangle.h = 32;
	_srcRectangle.w = 32;
	_srcRectangle.x = 0;
	_srcRectangle.y = 0;

	_x = a;
	_y = b;
	_destRectangle.x = a;
	_destRectangle.y = b;
	_destRectangle.w = c;
	_destRectangle.h = d;
}

void GameObject::Render()
{
	SDL_RenderCopy(_renderer, _texture, nullptr, &_destRectangle);
}
int GameObject::getX()
{
	return _x;
}
int GameObject::getY()
{
	return _y;
}
void GameObject::setX(int a)
{
	_x = a;
}
void GameObject::setY(int b)
{
	_y = b;
}