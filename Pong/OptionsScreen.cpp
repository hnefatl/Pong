#include "OptionsScreen.h"

OptionsScreen::OptionsScreen()
{
	BackPressed=false;
}

bool OptionsScreen::Load(SDL_Renderer *const Renderer)
{
	SDL_Colour White;
	memset(&White, 0xFF, sizeof(White));
	
	if(!Volume.Load(Resources::Fonts::Arial, "Volume", 20, White, Renderer))
	{
		return false;
	}
	if(!Save.Load(Resources::Fonts::Arial, "Save", 20, White, Renderer))
	{
		return false;
	}
	if(!Back.Load(Resources::Fonts::Arial, "Back", 20, White, Renderer))
	{
		return false;
	}

	Back.SetPosition(50, 50); // Top left corner
	Save.SetPosition(Back.GetPosition().x+Back.GetPosition().w+50, 50); // Same level as back, but 50p to the right
	Volume.SetPosition(50, Settings::WindowHeight-50); // Bottom left

	Back.OnClick.AddHandler(std::bind(&OptionsScreen::OnBackClick, this));
	Save.OnClick.AddHandler(std::bind(&OptionsScreen::OnSaveClick, this));

	return true;
}

Result OptionsScreen::HandleEvents(const SDL_Event &Event, std::stack <Screen *> *const Screen)
{
	if(!Back.HandleEvents(Event))
	{
		return Error;
	}
	if(!Save.HandleEvents(Event))
	{
		return Error;
	}
	if(!Volume.HandleEvents(Event))
	{
		return Error;
	}

	if(BackPressed)
	{
		BackPressed=false;
		return RemoveScreen;
	}

	return OK;
}
void OptionsScreen::Update()
{
	Back.Update();
	Save.Update();
	Volume.Update();
}
void OptionsScreen::Draw(SDL_Renderer *const Renderer)
{
	Back.Draw(Renderer);
	Save.Draw(Renderer);
	Volume.Draw(Renderer);
}

void OptionsScreen::OnBackClick()
{
	BackPressed=true;
}
void OptionsScreen::OnSaveClick()
{
	Settings::Save();
	Settings::Load();
}