#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "AppStateCode.hpp"

namespace Spirit
{
	class IAppState
	{
	public:
		virtual bool onEntry() = 0;
		virtual bool onQuit() = 0;
		virtual void onEvent(sf::Event & p_event) = 0;
		virtual void renderFrame(sf::RenderWindow & p_window, const float dt) = 0;
		virtual AppStateCode update(const float dt) = 0;
		virtual AppStateCode getId() const = 0;
	};
}