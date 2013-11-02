#include "Texture.h"

Texture::Texture()
	:Width(0),
	Height(0),
	Image(NULL)
{

}
Texture::~Texture()
{
	Free();
}

bool Texture::Load(const std::string &Path, SDL_Renderer *const Renderer)
{
	Free();

	SDL_Texture *New=NULL;
	SDL_Surface *Surface=NULL;
	// Load the surface
	Surface=IMG_Load(Path.c_str());
	if(Surface==NULL)
	{
		Print("Failed to load file \""+Path+"\".");
		return false;
	}

	// Create texture
	New=SDL_CreateTextureFromSurface(Renderer, Surface);
	if(New==NULL)
	{
		SDL_FreeSurface(Surface);
		Print("Failed to create texture from Surface from file \""+Path+"\".");
		return false;
	}

	// Store the texture dimensions
	Width=Surface->w;
	Height=Surface->h;

	// Free up the memory
	SDL_FreeSurface(Surface);

	// Store the fully loaded texture
	Image=New;

	Print("Loaded image from \""+Path+"\".");
	return true;
}
bool Texture::Load(const std::string &Text, const std::string &FontFile, const unsigned int &Size, const SDL_Color &TextColour, SDL_Renderer *const Renderer)
{
	Free();
	TTF_Font *Font=TTF_OpenFont(FontFile.c_str(), Size);

	SDL_Surface *Surface=TTF_RenderText_Solid(Font, Text.c_str(), TextColour);
	TTF_CloseFont(Font);

	if(Surface==NULL)
	{
		return false;
	}

	SDL_Texture *New=NULL;
	New=SDL_CreateTextureFromSurface(Renderer, Surface);
	if(New==NULL)
	{
		SDL_FreeSurface(Surface);
		return false;
	}

	Image=New;
	Width=Surface->w;
	Height=Surface->h;

	SDL_FreeSurface(Surface);

	return true;
}

Texture *Texture::Create(const std::string &Path, SDL_Renderer *const Renderer)
{
	Texture *New=new Texture();
	New->Load(Path, Renderer);
	return New;
}
Texture *Texture::Create(const std::string &Text, const std::string &FontFile, const unsigned int &Size, const SDL_Color &TextColour, SDL_Renderer *const Renderer)
{
	Texture *New=new Texture();
	New->Load(Text, FontFile, Size, TextColour, Renderer);
	return New;
}

void Texture::Render(SDL_Renderer *const Renderer, const int &x, const int &y)
{
	return Render(Renderer, x, y, NULL, 0.0, NULL, SDL_RendererFlip());
}
void Texture::Render(SDL_Renderer *const Renderer, const int &x, const int &y, const SDL_RendererFlip &Flip)
{
	return Render(Renderer, x, y, NULL, 0.0, NULL, Flip);
}
void Texture::Render(SDL_Renderer *const Renderer, const int &x, const int &y, const double &Angle, SDL_Point *const Centre)
{
	return Render(Renderer, x, y, NULL, Angle, Centre, SDL_RendererFlip());
}
void Texture::Render(SDL_Renderer *const Renderer, const int &x, const int &y, const double &Angle, SDL_Point *const Centre, const SDL_RendererFlip &Flip)
{
	return Render(Renderer, x, y, NULL, Angle, Centre, Flip);
}
void Texture::Render(SDL_Renderer *const Renderer, const int &x, const int &y, SDL_Rect *const Clip)
{
	return Render(Renderer, x, y, Clip, 0.0, NULL, SDL_RendererFlip());
}
void Texture::Render(SDL_Renderer *const Renderer, const int &x, const int &y, SDL_Rect *const Clip, const double &Angle, SDL_Point *const Centre)
{
	return Render(Renderer, x, y, Clip, Angle, Centre, SDL_RendererFlip());
}
void Texture::Render(SDL_Renderer *const Renderer, const int &x, const int &y, SDL_Rect *const Clip, const double &Angle, SDL_Point *const Centre, const SDL_RendererFlip &Flip)
{
	SDL_Rect RenderQuad;
	RenderQuad.x=x;
	RenderQuad.y=y;
	if(Clip!=NULL)
	{
		RenderQuad.w=Clip->w;
		RenderQuad.h=Clip->h;
	}
	else
	{
		RenderQuad.w=Width;
		RenderQuad.h=Height;
	}

	SDL_RenderCopyEx(Renderer, Image, Clip, &RenderQuad, Angle, Centre, Flip);
}

void Texture::SetColour(const unsigned int &Red, const unsigned int &Green, const unsigned int &Blue, const unsigned int &Alpha)
{
	SDL_SetTextureColorMod(Image, (Uint8)Red, (Uint8)Green, (Uint8)Blue);
	SDL_SetTextureAlphaMod(Image, (Uint8)Alpha);
}
void Texture::SetBlendMode(const SDL_BlendMode &Mode)
{
	SDL_SetTextureBlendMode(Image, Mode);
}

unsigned int Texture::GetWidth() const
{
	return Width;
}
unsigned int Texture::GetHeight() const
{
	return Height;
}

void Texture::Free()
{
	if(Image!=NULL)
	{
		SDL_DestroyTexture(Image);
		Image=NULL;
		Print("Freed texture.");
	}
	Width=0;
	Height=0;
}