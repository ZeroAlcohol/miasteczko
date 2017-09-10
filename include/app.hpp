#pragma once

#include <chrono>

#include "Game.hpp"
#include "Menu.hpp"

class App
{

public:
    enum class State {Menu, Game};
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
    Menu m_menu;
	Game m_game;
    State m_currentState;
};
