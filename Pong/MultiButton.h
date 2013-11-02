#ifndef _MULTIBUTTON_H
#define _MULTIBUTTON_H

#include "Button.h"

#include <vector>

class Blip
	: public Button
{
public:
	std::string Name;
};

class MultiButton
	: public Button
{
public:
	MultiButton();
	~MultiButton();

	virtual bool HandleEvents(const SDL_Event &Event);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

	void AddBlip(Blip *const NewBlip);

	bool DropDown;

protected:
	void Clicked();

	bool Selected;

	std::vector<Blip *> Blips;
};

#endif