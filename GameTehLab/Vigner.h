#pragma once
#include "Command.h"
class Vigner : public Command
{
	std::string key;
public:
	Vigner(std::string key) : key(key) {};
	std::string Execute(std::string text, int params[]) override;
};