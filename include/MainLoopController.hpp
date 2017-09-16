#pragma once

#include <chrono>
#include "app.hpp"

namespace Spirit
{
	class MainLoopController
	{
	public:
		MainLoopController(App &p_app, sf::RenderWindow & p_window);
		void run();

	private:
		App & m_app;
		sf::RenderWindow & m_window;

		std::chrono::high_resolution_clock::time_point m_startupTimestamp;

		uint64_t m_updateTimeout;
		uint64_t m_renderMinTimeout;
		uint64_t m_renderLastFrameTime;
		sf::Event m_event;

		uint64_t getMicrosecondsFromStart() const;
		void wait();

	};
}