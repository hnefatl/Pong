#include <SDL.h>
#ifdef _DEBUG
#include <iostream>
#endif

#include "Print.h"
#include "Settings.h"

#include "Game.h"

int main(int argc, char *argv[])
{
	if(!InitialisePrint())
	{
		return -1;
	}
	if(!Settings::Initialise())
	{
		return -2;
	}

	Game Pong;
	if(!Pong.Load())
	{
		return -3;
	}

	Pong.Run();

	return 0;
}