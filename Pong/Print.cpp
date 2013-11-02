#include "Print.h"

#include <iostream>
#include <sstream>
#include <ctime>

std::ofstream PrintOut;

bool InitialisePrint()
{
	PrintOut.open("Out.txt");
	if(!PrintOut.good())
	{
		return false;
	}

	return true;
}

std::string GetCurrentTime()
{
	time_t Time=time(NULL);
	tm *Now=localtime(&Time);
	std::stringstream String;
	String<<(Now->tm_mday)<<"."<<(Now->tm_mon+1)<<"."<<(Now->tm_year+1900)<<" "<<(Now->tm_hour)<<":"<<(Now->tm_min)<<":"<<(Now->tm_sec);

	return String.str();
}

void Print(const std::string &Message)
{
	PrintOut<<GetCurrentTime()<<" "<<Message<<std::endl;
#ifdef _DEBUG
	std::cout<<GetCurrentTime()<<" "<<Message<<std::endl;
#endif
}