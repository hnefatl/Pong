#ifndef _TIMER_H
#define _TIMER_H

class Timer
{
public:
	Timer();

	void Start();
	void Stop();
	void Pause();
	void Resume();

	unsigned int GetTicks() const;

	bool IsStarted() const;
	bool IsPaused() const;
protected:
	unsigned int StartTicks;
	unsigned int PausedTicks;

	bool Paused;
	bool Started;
};

#endif