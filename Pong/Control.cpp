#include "Control.h"

Control::Control()
{
	Visible=true;
	SmoothTransition=false;
	Transitioning=false;
}

SDL_Rect Control::GetPosition() const
{
	return Position;
}

void Control::SetPosition(const SDL_Point &NewPosition)
{
	return SetPosition(NewPosition.x, NewPosition.y);
}
void Control::SetPosition(const int &x, const int &y)
{
	Position.x=x;
	Position.y=y;
}

bool Control::PointInside(const int &x, const int &y)
{
	return (x>=Position.x && x<=Position.x+Position.w && y>=Position.y && y<=Position.y+Position.h);
}

bool Control::GetVisible() const
{
	return Visible;
}
void Control::SetVisible(const bool &Visible, const bool &SmoothTransition)
{
	this->Visible=Visible;
	this->SmoothTransition=SmoothTransition;
	this->Transitioning=true;
}