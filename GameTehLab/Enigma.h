#pragma once
#include "Command.h"
class Enigma : public Command
{
	std::string key;
public:
	Enigma(std::string key) : key(key) {};
	std::string Execute(std::string text, int params[]) override;
};

