#ifndef _BUTTON_H
#define _BUTTON_H

#include "Control.h"
#include "Texture.h"

#include "Event.h"

class Button
	: public Control
{
public:
	Button();

	virtual bool Load(const std::string &ImagePath, SDL_Renderer *const Renderer);
	virtual bool Load(const std::string &FontPath, const std::string &Text, const unsigned int &PtSize, const SDL_Colour &Colour,
		SDL_Renderer *const Renderer);

	virtual bool HandleEvents(const SDL_Event &Event);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

	Event OnClick;

	bool Selected;

protected:
	static unsigned int FramesToUpdateAppearance;

	Texture Image;
	SDL_Colour ImageColour;
	SDL_Colour UnselectedColour;
};

#endif