#pragma once

#include <chrono>
#include <memory>
#include <list>

#include "IAppState.hpp"
#include "FpsCounter.hpp"

namespace Spirit
{
	class App
	{
	public:
		App();
		~App();
		void run();
		void putState(std::unique_ptr<IAppState> p_appState, bool p_setActive = false);
		bool setActiveState(AppStateCode p_appStateCode);

	private:
		void renderFrame();
		uint64_t getMicrosecondsFromStart() const;
		void wait();
		void onEvent(sf::Event p_event);
		bool update();

		std::chrono::high_resolution_clock::time_point m_startupTimestamp;
		uint64_t m_updateTimeout;
		uint64_t m_renderMinTimeout;
		sf::RenderWindow m_window;
		sf::Event m_event;

		using StatesList = std::list<std::unique_ptr<IAppState>>;
		StatesList m_appStates;
		StatesList::iterator m_currentState;

		FpsCounter m_fpsCounter;
	};
}
