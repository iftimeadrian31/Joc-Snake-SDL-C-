#include "Player.h"
#include "TextureManager.h"
Player::Player(const char* textureSheet, SDL_Renderer* renderer): GameObject("a",renderer,1000,1000),renderer(renderer)
{
   setTex(textureSheet);
}

void Player::setTex(const char* path)
{
   texture = TextureManager::LoadTexture(path, renderer);
}


void Player::init()
{
	destRect.x=896;
	destRect.y = 512;
	srcRect.x = 32;
	srcRect.y = 32;
   srcRect.w = srcRect.h = 32;
   destRect.w = destRect.h = 64;
}

void Player::update()
{
	const Uint8* keys = SDL_GetKeyboardState(nullptr);
	if (keys[SDL_SCANCODE_A])
	{	
		if (directia != 2)

		directia = 1;
	}
	else if (keys[SDL_SCANCODE_D])
	{
		if (directia != 1)

		directia = 2;
	}
	else if (keys[SDL_SCANCODE_W])
	{
		if (directia != 4)

		directia = 3;
	}
	else if (keys[SDL_SCANCODE_S])
	{
		if (directia != 3)

		directia = 4;
	}
	if(directia==1)
		destRect.x -= 64;
	else if(directia==2)
		destRect.x += 64;
	else if(directia==3)
		destRect.y -= 64;
	else if(directia==4)
		destRect.y += 64;
	if (directia == 0)
	{

	}


}


void Player::draw()
{
   TextureManager::Draw(texture, srcRect, destRect, renderer);
}
bool Player::out1()
{
	if ((destRect.x>= 1856) || (destRect.y>= 1024)||(destRect.x <=0)||(destRect.y <=0))
	{
		return 1;
	}
	return 0;
}
bool Player::out2()
{
	if (((destRect.x>= 1856) || (destRect.y> 1024) || (destRect.x <=0) || (destRect.y <=0)))
	{
		return 1;
	}
	else if(((destRect.x>=1344))&&(destRect.y==192))
	{
		return 1;
	}
	else if(((destRect.x<=448)&&(destRect.y==320))||((destRect.x==448)&&(destRect.y==384)))
	{
		return 1;
	}
	else if((destRect.x>=896)&&(destRect.y==640))
	{
		return 1;
	}
	else if (((destRect.x == 448) && (destRect.y == 640)) || ((destRect.x<=448)&&(destRect.y==704)))
	{
		return 1;
	}
	return 0;
}
bool Player::out3()
{
	if ((destRect.x >= 1856) || (destRect.y >= 1024) || (destRect.x <= 0) || (destRect.y <= 0))
	{
		return 1;
	}
	else if ((destRect.x >=64 )&&(destRect.y >=384 )&&(destRect.x <=704)&&(destRect.y <= 640))
	{
		return 1;
	}
	else if ((destRect.x >= 768) && (destRect.y >= 448) && (destRect.x <= 832) && (destRect.y <= 640))
	{
		return 1;
	}
	else if ((destRect.x >= 832) && (destRect.y == 640) && (destRect.x <= 1728))
	{
		return 1;
	}
	else if ((destRect.x == 320) && ((destRect.y == 704) || (destRect.y == 768) || (destRect.y == 896) || (destRect.y == 960)))
	{
		return 1;
	}
	else if ((destRect.x >= 960) && (destRect.y >= 448) && (destRect.x <= 1856) && (destRect.y <= 512))
	{
		return 1;
	}
	else if ((destRect.x >= 1088) && (destRect.y == 384) && (destRect.x <= 1856))
	{
		return 1;
	}
	else if ((destRect.x ==1216) && ((destRect.y ==64)||(destRect.y == 128) ||(destRect.y == 192)))
	{
		return 1;
	}
	return 0;
}
int Player::getX()
{
	return destRect.x;
}
int Player::getY()
{
	return destRect.y;
}
int Player::eat()
{
	if ((destRect.x == posxp[o]) && (destRect.y == posyp[o]))
	{
			o++;
		
		return 1;
	}
	else return 0;
}
int  Player::getDirectia()
{
	return directia;
}
void Player::resetDirectia()
{
	directia = 0;
}
void Player::reset()
{
	o = 0;
}
int Player::getPosX(int i)
{
	return posxp[i];
}
int Player::getPosY(int i)
{
	return posyp[i];
}
