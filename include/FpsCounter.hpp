#pragma once

#include <SFML/System.hpp>
#include "TextFactory.hpp"
#include "IObject.hpp"

class FpsCounter : public IObject
{
public:
    FpsCounter();
    unsigned getFrames();
    void run() override;
    void render(sf::RenderWindow& p_window) override;

private:
    sf::Clock m_clock;
    unsigned m_framerate;
    TextFactory m_text;

};

