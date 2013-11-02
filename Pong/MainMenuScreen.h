#ifndef _MAINMENUSCREEN_H
#define _MAINMENUSCREEN_H

#include "Screen.h"

#include "Button.h"

class MainMenuScreen
	: public Screen
{
public:
	MainMenuScreen();

	virtual bool Load(SDL_Renderer *const Renderer);

	virtual Result HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

	void OptionsClick();
	void ExitClick();

protected:
	Button Options;
	bool OptionsPressed;

	Button Exit;
	bool ExitPressed;
};

#endif