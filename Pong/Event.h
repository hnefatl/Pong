#ifndef _EVENT_H
#define _EVENT_H

#include <functional>
#include <vector>

class Event
{
protected:
	typedef std::function<void()> FuncPtr;
	std::vector<FuncPtr> Handlers;

public:
	void operator +=(FuncPtr Handler)
	{
		AddHandler(Handler);
	}
	void AddHandler(FuncPtr Handler)
	{
		Handlers.push_back(Handler);
	}

	void operator ()()
	{
		for(unsigned int x=0; x<Handlers.size(); x++)
		{
			Handlers[x]();
		}
	}

};

#endif