#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class IAppState
{
public:
	enum class AppStateCode { Menu, Game, Exit };

	virtual bool onEntry() = 0;
	virtual bool onQuit() = 0;
	virtual void onEvent(sf::Event & p_event) = 0;
	virtual void renderFrame(sf::RenderWindow & p_window, const float dt) = 0;
	virtual AppStateCode update(const float dt) = 0;
};