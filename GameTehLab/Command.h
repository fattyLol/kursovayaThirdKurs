#pragma once
#include <iostream>
#include <string>
/**
 * ��������� ������� ��������� ����� ��� ���������� ������.
 */
class Command {
public:
    virtual ~Command() {};
    virtual std::string Execute(std::string text, int params[]) = 0;
};
