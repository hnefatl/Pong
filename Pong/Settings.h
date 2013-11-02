#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <SDL.h>
#include <vector>
#include <string>

class Settings
{
public:
	static bool Initialise();

	static bool Load();
	static bool Save();

	static SDL_Colour GameColour;
	static unsigned int Volume;

	const static unsigned int WindowWidth;
	const static unsigned int WindowHeight;

protected:
	static std::string FilePath;

	static std::vector<std::string> Split(const std::string &Input, const std::string &Delimiters);
};

#endif