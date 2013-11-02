#include "Settings.h"

#include "Print.h"

#include <fstream>
#include <sstream>

bool Settings::Initialise()
{
	Print("Initialising Settings.");
	FilePath="Settings.dat";

	return Load();
}

bool Settings::Load()
{
	Print("Loading settings.");
	std::ifstream In(FilePath.c_str());
	if(!In.good())
	{
		return false;
	}

	unsigned int SettingsLoaded=0;
	std::string Line;
	while(std::getline(In, Line))
	{
		if(Line.size()>0)
		{
			std::vector<std::string> Parts=Split(Line, ": ");
			if(Parts.size()==2)
			{
				if(Parts[0]=="Volume")
				{
					SettingsLoaded++;
					Volume=atoi(Parts[1].c_str());
				}
			}
			else if(Parts.size()==4)
			{
				if(Parts[0]=="Colour")
				{
					SettingsLoaded++;
					GameColour.a=255;
					GameColour.r=atoi(Parts[1].c_str());
					GameColour.g=atoi(Parts[2].c_str());
					GameColour.b=atoi(Parts[3].c_str());
				}
			}
		}
	}

	In.close();

	if(SettingsLoaded!=2)
	{
		Print("Failed to load settings.");
		return false;
	}
	else
	{
		Print("Loaded settings succesfully.");
		return true;
	}
}
bool Settings::Save()
{
	Print("Saving settings.");
	std::ofstream Out(FilePath.c_str());
	if(!Out.good())
	{
		Print("Failed to save settings.");
		return false;
	}

	Out<<"Volume: "<<Volume<<std::endl;
	Out<<"Colour: "<<(int)GameColour.r<<" "<<(int)GameColour.g<<" "<<(int)GameColour.b;

	Out.close();

	Print("Settings saved sucessfully.");
	return true;
}

std::vector<std::string> Settings::Split(const std::string &Input, const std::string &Delimiters)
{
	std::vector<std::string> Parts;

	std::string Temp;
	for(unsigned int x=0; x<Input.size(); x++)
	{
		bool Delimiter=false;
		for(unsigned int y=0; y<Delimiters.size(); y++)
		{
			if(Input[x]==Delimiters[y])
			{
				Delimiter=true;
			}
		}
		if(Delimiter)			
		{
			if(Temp.size()>0)
			{
				Parts.push_back(Temp);
				Temp.clear();
			}
		}
		else
		{
			Temp+=Input[x];
		}
	}
	if(Temp.size()>0)
	{
		Parts.push_back(Temp);
	}

	return Parts;
}

const unsigned int Settings::WindowWidth=600;
const unsigned int Settings::WindowHeight=600;

SDL_Colour Settings::GameColour;
unsigned int Settings::Volume;

std::string Settings::FilePath;