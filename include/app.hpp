#pragma once

#include <chrono>
#include <array>
#include "Game.hpp"
#include "Menu.hpp"

class App
{

public:
	using AppStateCode = IAppState::AppStateCode;
	App();
	~App();
	void run();

private:
	void renderFrame();
    uint64_t getMicrosecondsFromStart() const;
	void wait();
	void onEvent(sf::Event p_event);
	void update();

	std::chrono::high_resolution_clock::time_point m_startupTimestamp;
	uint64_t m_updateTimeout;
	uint64_t m_renderMinTimeout;
	sf::RenderWindow m_window;
	sf::Event m_event;
    Menu m_menu;
	Game m_game;
    AppStateCode m_currentStateIndex;
	std::array<IAppState *, 2> m_appStates { &m_menu, &m_game };
};
