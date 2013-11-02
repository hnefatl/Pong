#ifndef _PRINT_H
#define _PRINT_H

#include <string>
#include <fstream>

bool InitialisePrint();

std::string GetCurrentTime();

void Print(const std::string &Message);

#endif