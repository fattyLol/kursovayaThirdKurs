#pragma once
#include <SFML/Graphics.hpp>
#include "Cesar.h"
#include "Vigner.h"
#include "Enigma.h"
#include <iostream>
#include <fstream>
#include <string>

class Invoker
{
    sf::RenderWindow* window;
public:
    void OpenApp();
    void IsReady();
    ~Invoker() {
    }
};

