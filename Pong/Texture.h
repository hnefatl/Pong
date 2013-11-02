#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Print.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	bool Load(const std::string &Path, SDL_Renderer *const Renderer);
	bool Load(const std::string &Text, const std::string &FontFile, const unsigned int &Size, const SDL_Color &TextColour, SDL_Renderer *const Renderer);

	static Texture *Create(const std::string &Path, SDL_Renderer *const Renderer);
	static Texture *Create(const std::string &Text, const std::string &FontFile, const unsigned int &Size, const SDL_Color &TextColour, SDL_Renderer *const Renderer);

	void Render(SDL_Renderer *const Renderer, const int &x, const int &y);
	void Render(SDL_Renderer *const Renderer, const int &x, const int &y, const SDL_RendererFlip &Flip);
	void Render(SDL_Renderer *const Renderer, const int &x, const int &y, const double &Angle, SDL_Point *const Centre);
	void Render(SDL_Renderer *const Renderer, const int &x, const int &y, const double &Angle, SDL_Point *const Centre, const SDL_RendererFlip &Flip);
	void Render(SDL_Renderer *const Renderer, const int &x, const int &y, SDL_Rect *const Clip);
	void Render(SDL_Renderer *const Renderer, const int &x, const int &y, SDL_Rect *const Clip, const double &Angle, SDL_Point *const Centre);
	void Render(SDL_Renderer *const Renderer, const int &x, const int &y, SDL_Rect *const Clip, const double &Angle, SDL_Point *const Centre, const SDL_RendererFlip &Flip);

	void SetColour(const unsigned int &Red, const unsigned int &Green, const unsigned int &Blue, const unsigned int &Alpha=255);
	void SetBlendMode(const SDL_BlendMode &Mode);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

protected:
	void Free();

	SDL_Texture *Image;

	unsigned int Width, Height;
};

#endif