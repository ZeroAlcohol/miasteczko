#pragma once

#include <SFML/System.hpp>
#include "Text.hpp"

class FpsCounter
{
public:
    FpsCounter();
    void render(sf::RenderWindow& p_window);
	void show();
	void hide();
	bool isVisible() const;

private:
    unsigned getFrames();
    sf::Clock m_clock;
    unsigned m_framerate;
    Text m_text;
	bool m_visible;

};

