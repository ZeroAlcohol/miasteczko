#pragma once

#include <chrono>

#include "Game.hpp"

class App
{

public:
	App();
	~App();
	void run();

private:
	void renderFrame();
    uint64_t getMicrosecondsFromStart() const;
	void wait();

	std::chrono::high_resolution_clock::time_point m_startupTimestamp;
	uint64_t m_updateTimeout;
	uint64_t m_renderMinTimeout;
	sf::RenderWindow m_window;
	sf::Event m_event;
	Game m_game;
};
