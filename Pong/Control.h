#ifndef _CONTROL_H
#define _CONTROL_H

#include "GameEntity.h"

// Similar to Screen - provides a tighter restriction on the GameEntity tagging interface
class Control
	: public GameEntity
{
public:
	Control();

	SDL_Rect GetPosition() const;
	void SetPosition(const SDL_Point &NewPosition);
	void SetPosition(const int &x, const int &y);

	bool GetVisible() const;
	void SetVisible(const bool &Visible, const bool &SmoothTransition=true);

	bool PointInside(const int &x, const int &y);

protected:
	bool Visible;
	bool SmoothTransition;
	bool Transitioning;


	SDL_Rect Position;
};

#endif