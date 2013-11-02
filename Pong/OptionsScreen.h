#ifndef _OPTIONSSCREEN_H
#define _OPTIONSSCREEN_H

#include "Screen.h"
#include "Button.h"
#include "MultiButton.h"

class OptionsScreen
	: public Screen
{
public:
	OptionsScreen();

	virtual bool Load(SDL_Renderer *const Renderer);

	virtual Result HandleEvents(const SDL_Event &Event, std::stack<Screen *> * const Screens);

	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

	void OnBackClick();
	void OnSaveClick();

protected:
	Button Save;
	Button Back;
	MultiButton Volume;

	bool BackPressed;
};

#endif