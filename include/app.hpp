#pragma once

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
		void renderFrame(const float p_dt);
		void onEvent(sf::Event p_event);
		bool update();

	private:
		sf::RenderWindow m_window;
		using StatesList = std::list<std::unique_ptr<IAppState>>;
		StatesList m_appStates;
		StatesList::iterator m_currentState;
		FpsCounter m_fpsCounter;
	};
}
