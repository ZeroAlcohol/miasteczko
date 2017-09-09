#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class IObject
{
public:
	virtual void run() = 0;
    virtual void render(sf::RenderWindow& p_window) = 0;
    virtual ~IObject(){}
};

