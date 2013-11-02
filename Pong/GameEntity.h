#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H

#include <SDL.h>

#include "Settings.h"
#include "Resources.h"

// Superclass for all classes that are meant to be drawn and interacted with
class GameEntity
{
public:
	virtual bool HandleEvents(const SDL_Event &Event)=0;
	virtual void Update()=0;
	virtual void Draw(SDL_Renderer *const Renderer)=0;
};

#endif