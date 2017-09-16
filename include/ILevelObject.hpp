#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class ILevelObject
{
public:
	virtual void update() = 0;
    virtual void render(sf::RenderWindow& p_window) = 0;
    virtual ~ILevelObject(){}
};

