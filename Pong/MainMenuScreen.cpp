#include "MainMenuScreen.h"

#include "OptionsScreen.h"

MainMenuScreen::MainMenuScreen()
{
	OptionsPressed=false;
	ExitPressed=false;
}

bool MainMenuScreen::Load(SDL_Renderer *const Renderer)
{
	SDL_Colour White;
	memset(&White, 0xFF, sizeof(White));
	if(!Options.Load(Resources::Fonts::Arial, "Options", 20, White, Renderer))
	{
		return false;
	}
	if(!Exit.Load(Resources::Fonts::Arial, "Exit", 20, White, Renderer))
	{
		return false;
	}

	Options.SetPosition(50, 50); // Top left corner
	Exit.SetPosition(Settings::WindowWidth-(50+Exit.GetPosition().w), 50);

	Options.OnClick.AddHandler(std::bind(&MainMenuScreen::OptionsClick, this));
	Exit.OnClick.AddHandler(std::bind(&MainMenuScreen::ExitClick, this));

	return true;
}

Result MainMenuScreen::HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens)
{
	if(!Options.HandleEvents(Event))
	{
		return Error;
	}
	if(!Exit.HandleEvents(Event))
	{
		return Error;
	}
	if(OptionsPressed)
	{
		OptionsPressed=false;
		Screens->push(new OptionsScreen());
		return NewScreen;
	}
	if(ExitPressed)
	{
		ExitPressed=false;
		return RemoveScreen;
	}

	return OK;
}
void MainMenuScreen::Update()
{
	Options.Update();
	Exit.Update();
}
void MainMenuScreen::Draw(SDL_Renderer *const Renderer)
{
	Options.Draw(Renderer);
	Exit.Draw(Renderer);
}

void MainMenuScreen::OptionsClick()
{
	OptionsPressed=true;
}
void MainMenuScreen::ExitClick()
{
	ExitPressed=true;
}