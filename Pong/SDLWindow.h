#ifndef _SDLWINDOW_H
#define _SDLWINDOW_H

#include "Print.h"

#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class SDLWindow
{
public:
	SDLWindow();
	~SDLWindow();

	bool Create(const unsigned int &WindowWidth, const unsigned int &WindowHeight, const std::string &Title,
		const SDL_WindowFlags &Flags=SDL_WindowFlags::SDL_WINDOW_SHOWN);

	void BeginScene();
	void EndScene();

	void SetBackgroundColour(const SDL_Colour &Background);

	SDL_Renderer *const GetRenderer();

	SDL_Window *const GetWindow();

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

protected:
	SDL_Window *Window;
	SDL_Renderer *Renderer;

	unsigned int Width;
	unsigned int Height;

	TTF_Font *Font;

	SDL_Colour Background;
};

#endif