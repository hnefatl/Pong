#ifndef _GAME_H
#define _GAME_H

#include "SDLWindow.h"
#include <stack>

#include "Screen.h"

class Game
{
public:
	Game();
	~Game();

	bool Load();

	void Run();

	bool Update();
	void Draw();

protected:
	SDLWindow Window;

	std::stack<Screen *> Screens;
};

#endif