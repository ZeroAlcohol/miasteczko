#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Level.hpp>

class Game
{
public:
    Game();
	void onEvent(sf::Event & p_event);
	void renderFrame(sf::RenderWindow & p_window, const float dt);
	void update(const float dt);
    bool createGame();

private:
	Level m_level;
};

