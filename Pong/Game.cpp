#include "Game.h"

#include "Print.h"

#include "MainMenuScreen.h"
#include "Timer.h"

Game::Game()
{
}
Game::~Game()
{
	while(!Screens.empty())
	{
		delete Screens.top();
		Screens.pop();
	}
}

bool Game::Load()
{
	Print("Creating window.");
	if(!Window.Create(Settings::WindowWidth, Settings::WindowHeight, "Pong"))
	{
		return false;
	}
	Screens.push(new MainMenuScreen());
	Screens.top()->Load(Window.GetRenderer());

	return true;
}

void Game::Run()
{
	const unsigned int FPS=50;
	const unsigned int ScreenTicksPerFrame=1000/FPS;

	Timer CapTimer;

	while(true)
	{
		CapTimer.Start();
		if(!Update())
		{
			return;
		}
		Draw();

		if(CapTimer.GetTicks()<(1000/FPS))
		{
			SDL_Delay((1000/FPS)-CapTimer.GetTicks());
		}
	}
}

bool Game::Update()
{
	SDL_Event Event;
	if(SDL_PollEvent(&Event))
	{
		if(Event.type==SDL_EventType::SDL_QUIT)
		{
			return false;
		}

		Result ScreensResult=Screens.top()->HandleEvents(Event, &Screens);
		if(ScreensResult==Error)
		{
			Print("Error occurred.");
			return false;
		}
		else if(ScreensResult==NewScreen)
		{
			Screens.top()->Load(Window.GetRenderer());
		}
		else if(ScreensResult==RemoveScreen)
		{
			Screens.pop();
			if(Screens.size()==0)
			{
				return false;
			}
		}
	}
	Screens.top()->Update();

	return true;
}
void Game::Draw()
{
	Window.BeginScene();

	Screens.top()->Draw(Window.GetRenderer());

	Window.EndScene();
}