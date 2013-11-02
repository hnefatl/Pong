#include "Timer.h"

#include <SDL.h>

Timer::Timer()
{
	StartTicks=0;
	PausedTicks=0;
	Started=false;
	Paused=false;
}

void Timer::Start()
{
	Started=true;
	Paused=false;
	StartTicks=SDL_GetTicks();
}
void Timer::Stop()
{
	Started=false;
	Paused=false;
}
void Timer::Pause()
{
	if(!Paused && Started)
	{
		Paused=true;
		PausedTicks=SDL_GetTicks()-StartTicks;
	}
}
void Timer::Resume()
{
	if(Paused)
	{
		Paused=false;
		StartTicks=SDL_GetTicks()-PausedTicks;
		PausedTicks=0;
	}
}

unsigned int Timer::GetTicks() const
{
	if(Started)
	{
		if(Paused)
		{
			return PausedTicks;
		}
		else
		{
			return SDL_GetTicks()-StartTicks;
		}
	}

	return 0;
}

bool Timer::IsStarted() const
{
	return Started;
}
bool Timer::IsPaused() const
{
	return Paused;
}