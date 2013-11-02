#include "Button.h"

Button::Button()
{
	Selected=false;
	FramesToUpdateAppearance=15;

	// Invisible, set to transition to visible 
	Visible=false;
	SmoothTransition=true;
	Transitioning=true;
}

bool Button::Load(const std::string &ImagePath, SDL_Renderer *const Renderer)
{
	if(!Image.Load(ImagePath, Renderer))
	{
		return false;
	}

	this->Position.w=Image.GetWidth();
	this->Position.h=Image.GetHeight();

	UnselectedColour.a=Visible?0xFF:0x00;
	UnselectedColour.r=0xFF;
	UnselectedColour.g=0xFF;
	UnselectedColour.b=0xFF;
	ImageColour=UnselectedColour;

	return true;
}

bool Button::Load(const std::string &FontPath, const std::string &Text, const unsigned int &PtSize, const SDL_Colour &Colour,
				  SDL_Renderer *const Renderer)
{
	if(!Image.Load(Text, FontPath, PtSize, Colour, Renderer))
	{
		return false;
	}

	this->Position.w=Image.GetWidth();
	this->Position.h=Image.GetHeight();

	UnselectedColour.a=Visible?0xFF:0x00;
	UnselectedColour.r=0xFF;
	UnselectedColour.g=0xFF;
	UnselectedColour.b=0xFF;
	ImageColour=UnselectedColour;

	return true;
}

bool Button::HandleEvents(const SDL_Event &Event)
{
	if(Event.type==SDL_EventType::SDL_MOUSEMOTION)
	{
		if(PointInside(Event.motion.x, Event.motion.y))
		{
			Selected=true;
		}
		else
		{
			Selected=false;
		}
	}
	else if(Event.type==SDL_EventType::SDL_MOUSEBUTTONDOWN)
	{
		if(Event.button.button==SDL_BUTTON_LEFT)
		{
			if(PointInside(Event.button.x, Event.button.y))
			{
				OnClick();
			}
		}
	}

	return true;
}
void Button::Update()
{
	if(Selected)
	{
		if(ImageColour.r!=Settings::GameColour.r)
		{
			int r=ImageColour.r+((int)Settings::GameColour.r-(int)UnselectedColour.r)/(int)FramesToUpdateAppearance;
			if(r<0)
			{
				r=0;
			}
			else if(r>255)
			{
				r=255;
			}
			ImageColour.r=r;
		}
		if(ImageColour.g!=Settings::GameColour.g)
		{
			int g=ImageColour.g+((int)Settings::GameColour.g-(int)UnselectedColour.g)/(int)FramesToUpdateAppearance;
			if(g<0)
			{
				g=0;
			}
			else if(g>255)
			{
				g=255;
			}
			ImageColour.g=g;
		}
		if(ImageColour.b!=Settings::GameColour.b)
		{
			int b=ImageColour.b+((int)Settings::GameColour.b-(int)UnselectedColour.b)/(int)FramesToUpdateAppearance;
			if(b<0)
			{
				b=0;
			}
			else if(b>255)
			{
				b=255;
			}
			ImageColour.b=b;
		}
	}
	else
	{
		if(ImageColour.r!=UnselectedColour.r)
		{
			int r=ImageColour.r-((int)Settings::GameColour.r-(int)UnselectedColour.r)/(int)FramesToUpdateAppearance;
			if(r<0)
			{
				r=0;
			}
			else if(r>255)
			{
				r=255;
			}
			ImageColour.r=r;
		}
		if(ImageColour.g!=UnselectedColour.g)
		{
			int g=ImageColour.g-((int)Settings::GameColour.g-(int)UnselectedColour.g)/(int)FramesToUpdateAppearance;
			if(g<0)
			{
				g=0;
			}
			else if(g>255)
			{
				g=255;
			}
			ImageColour.g=g;
		}
		if(ImageColour.b!=UnselectedColour.b)
		{
			int b=ImageColour.b-((int)Settings::GameColour.b-(int)UnselectedColour.b)/(int)FramesToUpdateAppearance;
			if(b<0)
			{
				b=0;
			}
			else if(b>255)
			{
				b=255;
			}
			ImageColour.b=b;
		}
	}

	if(Transitioning)
	{
		int NewAlpha=0;
		if(Visible) // Need to become invisible
		{
			if(ImageColour.a!=0)
			{
				NewAlpha=ImageColour.a-Settings::GameColour.a/FramesToUpdateAppearance;
				if(NewAlpha<0)
				{
					NewAlpha=0;
				}
				else if(NewAlpha>255)
				{
					NewAlpha=255;
				}
				ImageColour.a=NewAlpha;
			}
			else
			{
				Visible=false;
				Transitioning=false;
			}
		}
		else
		{
			if(ImageColour.a!=Settings::GameColour.a)
			{
				NewAlpha=ImageColour.a+Settings::GameColour.a/FramesToUpdateAppearance;
				if(NewAlpha<0)
				{
					NewAlpha=0;
				}
				else if(NewAlpha>255)
				{
					NewAlpha=255;
				}
				ImageColour.a=NewAlpha;
			}
			else
			{
				Visible=true;
				Transitioning=false;
			}
		}
	}

	Image.SetColour(ImageColour.r, ImageColour.g, ImageColour.b, ImageColour.a);
}
void Button::Draw(SDL_Renderer *Renderer)
{
	if(Visible || Transitioning)
	{
		Image.Render(Renderer, Position.x, Position.y);
	}
}

unsigned int Button::FramesToUpdateAppearance;