#pragma once
#include "Command.h"
class Cesar : public Command
{
public:
	std::string Execute(std::string text, int params[]) override;
};

