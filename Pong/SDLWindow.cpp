#include "SDLWindow.h"

SDLWindow::SDLWindow()
{
	Font=NULL;
	Background.a=0;
	Background.b=0;
	Background.g=0;
	Background.r=0;
}
SDLWindow::~SDLWindow()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool SDLWindow::Create(const unsigned int &Width, const unsigned int &Height, const std::string &Title,const SDL_WindowFlags &Flags)
{
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		return false;
	}

	// Create the ImageFlags - JPG and PNG
	int ImgFlags=0 | IMG_InitFlags::IMG_INIT_JPG | IMG_InitFlags::IMG_INIT_PNG;

	if(IMG_Init(ImgFlags)!=ImgFlags)
	{
		return false;
	}
	if(TTF_Init()<0)
	{
		return false;
	}

	Window=SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, Flags);
	if(Window==NULL)
	{
		return false;
	}
	Renderer=SDL_CreateRenderer(Window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if(Renderer==NULL)
	{
		return false;
	}

	SDL_Colour BackgroundColour;
	BackgroundColour.r=0x00;
	BackgroundColour.g=0x00;
	BackgroundColour.b=0x00;
	BackgroundColour.a=0xFF;
	SetBackgroundColour(BackgroundColour);

	return true;
}

void SDLWindow::BeginScene()
{
	SDL_RenderClear(Renderer);
}
void SDLWindow::EndScene()
{
	SDL_RenderPresent(Renderer);
}

void SDLWindow::SetBackgroundColour(const SDL_Colour &Background)
{
	this->Background=Background;
	SDL_SetRenderDrawColor(Renderer, Background.r, Background.g, Background.b, Background.a);
}

SDL_Renderer *const SDLWindow::GetRenderer()
{
	return Renderer;
}

SDL_Window *const SDLWindow::GetWindow()
{
	return Window;
}

unsigned int SDLWindow::GetWidth() const
{
	return Width;
}
unsigned int SDLWindow::GetHeight() const
{
	return Height;
}