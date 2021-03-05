#include "Game.h"
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "GameObject.h"
int i = 0;
int lvl =1;
bool menu = 1;
int score =0;
int Bx0[10];
int By0[10];
const Uint8* keys = SDL_GetKeyboardState(nullptr);
GameObject * Level;
GameObject * Score;
GameObject * Start;
GameObject * GameOver;
GameObject* End;
Map* map;
SDL_Event Game::event;
Player *head;
GameObject *body[10];
GameObject *Fruit;
Game::Game(): isRunning(false), window(nullptr), renderer(nullptr)
{
}

Game::~Game()
{
	delete Fruit;
   delete head;
   delete GameOver;
}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized" << std::endl;
		auto window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window!=nullptr)
		{
			std::cout << "Window created" << std::endl;
		}
 
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}


		head = new Player("assets/Black.png", renderer);

		Fruit = new GameObject("assets/fruit.png", renderer, head->getPosX(i), head->getPosY(i));
		for (int i = 0; i < 10; i++)
		{
			body[i] = new GameObject("assets/snake.png", renderer, head->getX() + 1000, head->getY());
		}
		GameOver = new GameObject("assets/Game_over.png", renderer, head->getX() + 1000, head->getY());
		End = new GameObject("assets/welldone.png", renderer, head->getX() + 1000, head->getY());
		Start = new GameObject("assets/Start.png", renderer, head->getX() + 1000, head->getY());
		Score = new GameObject("assets/0.png", renderer, head->getX() + 1000, head->getY());
		Level = new GameObject("assets/L1.png", renderer, head->getX() + 1000, head->getY());

	
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT: {
		isRunning = false;
		break;
	}
	default:
		break;
	}
	try {
		map = new Map(renderer, lvl);
	}
	catch (const std::invalid_argument & e)
	{
		isRunning = false;
	}
	try {
		
		scoreTest();
	}
	catch (const std::invalid_argument & e)
	{
		isRunning = false;
	}

}
void Game::update()
{	
	if (menu == 1)
	{
		menuscreen();
	}


	if (menu == 0)
	{	
		if (keys[SDL_SCANCODE_ESCAPE])
		{
			close();
		}

		if (keys[SDL_SCANCODE_R])
		{
			restart();
		}

		map = new Map(renderer, lvl);
		Start->Update(750, 10000);
		head->Hx0 = head->getX();
		head->Hy0 = head->getY();
		Fruit->Update(head->getPosX(i), head->getPosY(i));
		head->update();

		out();

		if (head->eat() == 1)
		{
			eat();
		}

		grow();

		canibal();

		if(score==10)
		nextLevel();



	}

}

void Game::render()
{
	SDL_RenderClear(renderer);
	if (map->exceptie() == 1)
	{
		close();
	}
	else
	{
		if (Fruit)
			map->DrawMap();
		Fruit->Render();
		GameOver->Render();
		Start->Render();
		Level->Render();
		End->Render();
		Score->Render();
		head->draw();
		for (int i = 0; i < 10; i++)
		{
			body[i]->Render();
		}
		SDL_RenderPresent(renderer);
	}
	
}

void Game::clean() const
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_QUIT;
	std::cout << "Game cleaned" << std::endl;
}
void Game::menuscreen()
{
	map = new Map(renderer, 4);
	Start->Update2(600, 350, 640, 320);
	if (keys[SDL_SCANCODE_RETURN])
	{

		menu = 0;
		head->init();
	}
}

void Game::close()
{
		isRunning = 0;
}
void Game::restart()
{
		lvl = 1;
		map = new Map(renderer, lvl);
		score = 0;
		head->init();
		head->resetDirectia();
		i = 0;
		head->reset();
		Fruit = new GameObject("assets/fruit.png", renderer, 10000, 10000);
		GameOver->Update(10000, 10000);
		for (int j = 0; j < 10; j++)
		{
			body[j] = new GameObject("assets/snake.png", renderer, 10000, 10000);
			body[j]->Update(10000, 1000);
		}
}
void Game::out()
{
	if (((head->out1() == 1) && (lvl == 1))|| ((head->out2() == 1) && (lvl == 2))|| ((head->out3() == 1) && (lvl == 3)))
	{
		lose();

	}

}

void Game::eat()
{
	score++;
	i++;
}
void Game::scoreIcon()
{
	if (score == 0)
		Score = new GameObject("assets/0.png", renderer, head->getX() + 1000, head->getY());
	if (score == 1)
		Score = new GameObject("assets/1.png", renderer, head->getX() + 1000, head->getY());
	if (score == 2)
		Score = new GameObject("assets/2.png", renderer, head->getX() + 1000, head->getY());
	if (score == 3)
		Score = new GameObject("assets/3.png", renderer, head->getX() + 1000, head->getY());
	if (score == 4)
		Score = new GameObject("assets/4.png", renderer, head->getX() + 1000, head->getY());
	if (score == 5)
		Score = new GameObject("assets/5.png", renderer, head->getX() + 1000, head->getY());
	if (score == 6)
		Score = new GameObject("assets/6.png", renderer, head->getX() + 1000, head->getY());
	if (score == 7)
		Score = new GameObject("assets/7.png", renderer, head->getX() + 1000, head->getY());
	if (score == 8)
		Score = new GameObject("assets/8.png", renderer, head->getX() + 1000, head->getY());
	if (score == 9)
		Score = new GameObject("assets/9.png", renderer, head->getX() + 1000, head->getY());
}
void Game::grow()
{
	if ((score == 0)||(score == 1))
	{
		scoreIcon();
		Score->Update2(1856, 0, 64, 64);
		if (lvl == 1)
			Level = new GameObject("assets/L1.png", renderer, head->getX() + 1000, head->getY());
		else if (lvl == 2)
			Level = new GameObject("assets/L2.png", renderer, head->getX() + 1000, head->getY());
		else
			Level = new GameObject("assets/L3.png", renderer, head->getX() + 1000, head->getY());
		Level->Update2(1792, 0, 64, 64);
		if (score == 1)
		{
			body[0]->Update(head->Hx0, head->Hy0);
		}
	}

	if (score>=2)
	{
		scoreIcon();
		Score->Update2(1856, 0, 64, 64);
		if (lvl == 1)
			Level = new GameObject("assets/L1.png", renderer, head->getX() + 1000, head->getY());
		else if (lvl == 2)
			Level = new GameObject("assets/L2.png", renderer, head->getX() + 1000, head->getY());
		else
			Level = new GameObject("assets/L3.png", renderer, head->getX() + 1000, head->getY());
		Level->Update2(1792, 0, 64, 64);
		Bx0[0] = body[0]->getX();
		By0[0] = body[0]->getY();

		body[0]->Update(head->Hx0, head->Hy0);

		for (int m = 1; m < score; m++)
		{
			Bx0[m] = body[m]->getX();
			By0[m] = body[m]->getY();

			body[m]->Update(Bx0[m - 1], By0[m - 1]);
		}
	}
}
void Game::canibal()
{
	for (int k = 0; k < 10; k++)
	{
		if ((head->getX() == body[k]->getX()) && (head->getY() == body[k]->getY()))
		{
			lose();
		}
	}
}
void Game::nextLevel()
{
	if (lvl == 1)
	{

		for (int j = 0; j < 10; j++)
		{
			body[j] = new GameObject("assets/snake2.png", renderer, 650, 573);
		}
		Fruit = new GameObject("assets/fruit2.png", renderer, head->getPosX(i), head->getPosY(i));

	}




	if (lvl == 2)
	{
		
		for (int j = 0; j < 10; j++)
		{
			body[j] = new GameObject("assets/snake3.png", renderer, 650, 573);
		}
		Fruit = new GameObject("assets/fruit3.png", renderer, head->getPosX(i), head->getPosY(i));

	}




	if (lvl == 3)
	{
		Score = new GameObject("assets/black.png", renderer, head->getX() + 1000, head->getY());
		Level = new GameObject("assets/black.png", renderer, head->getX() + 1000, head->getY());
		map = new Map(renderer, 4);
		End->Update2(600, 350, 700, 380);
		head = new Player("assets/black.png", renderer);
		Fruit = new GameObject("assets/black.png", renderer, 650, 573);
		for (int j = 0; j < 10; j++)
		{
			body[j] = new GameObject("assets/black.png", renderer, 650, 573);
		}
	}
	lvl++;
	map = new Map(renderer, lvl);
	score = 0;
	head->init();
	head->resetDirectia();
}
void Game::lose()
{
	map = new Map(renderer, 4);
	GameOver->Update2(600, 350, 640, 320);
	head = new Player("assets/black.png", renderer);
	Fruit = new GameObject("assets/black.png", renderer, 650, 573);
	for (int j = 0; j < 10; j++)
	{
		body[j] = new GameObject("assets/black.png", renderer, 650, 573);
	}
}
void Game::scoreTest()
{
	if((score<0)||(score>10))
		throw std::invalid_argument("score-ul este gresit");
}