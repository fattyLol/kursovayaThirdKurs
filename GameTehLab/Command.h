#pragma once
#include <iostream>
#include <string>
/**
 * Интерфейс Команды объявляет метод для выполнения команд.
 */
class Command {
public:
    virtual ~Command() {};
    virtual std::string Execute(std::string text, int params[]) = 0;
};
