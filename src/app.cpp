//#include <algorithm>

#include "config.hpp"
#include "easylogging++.h"
#include "app.hpp"
#include "MainLoopController.hpp"

namespace Spirit
{
	App::App()
	{
		m_currentState = m_appStates.end();
		m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
	}

	App::~App()
	{

	}

	void App::run() 
	{
		if (m_appStates.end() == m_currentState)
		{
			LOG(FATAL) << "Set correct state to run app!";
		}

		if (false == (*m_currentState)->onEntry())
		{
			LOG(FATAL) << "Failed to entry initial state!";
		}

		MainLoopController l_controller(*this, m_window);
		l_controller.run();
	}

	void App::onEvent(sf::Event p_event)
	{

		switch (p_event.type)
		{
		case sf::Event::Closed:
			(*m_currentState)->onQuit();
			m_window.close();
			break;

		case sf::Event::KeyReleased:
			switch (p_event.key.code)
			{
			case sf::Keyboard::F:
				if (m_fpsCounter.isVisible())
				{
					m_fpsCounter.hide();
				}
				else
				{
					m_fpsCounter.show();
				}
			}
		}
		
		(*m_currentState)->onEvent(p_event);
	}

	bool App::update()
	{
		const AppStateCode l_futureStateId = (*m_currentState)->update(DELAY_PER_UPDATE_FRAME_SEC);
		if (l_futureStateId != (*m_currentState)->getId())
		{
			return setActiveState(l_futureStateId);
		}
		return true;
	}

	void App::renderFrame(const float p_dt)
	{
		m_window.clear();
		(*m_currentState)->renderFrame(m_window, p_dt);
		m_window.setView(m_window.getDefaultView());
		m_fpsCounter.render(m_window);
		m_window.display();
	}

	void App::putState(std::unique_ptr<IAppState> p_appState, bool p_setActive)
	{
		const  Spirit::AppStateCode l_id = p_appState->getId();
		m_appStates.push_back(std::move(p_appState));
	
		if (p_setActive)
		{
			setActiveState(l_id);
		}
	}

	bool App::setActiveState(AppStateCode p_appStateCode)
	{
		bool quitApp{ false };

		if (m_appStates.end() != m_currentState)
		{
			if (false == (*m_currentState)->onQuit())
			{
				LOG(FATAL) << "Failed to quit current app state!";
			}
			m_currentState = m_appStates.end();
		}

		if (APP_STATE_CODE_EXIT == p_appStateCode)
		{
			m_window.close();
			quitApp = true;
		}

		for (auto & mapIterator = m_appStates.begin(); mapIterator != m_appStates.end(); ++mapIterator)
		{
			if (p_appStateCode == (*mapIterator)->getId())
			{
				m_currentState = mapIterator;
				if(false == (*m_currentState)->onEntry())
				{
					LOG(FATAL) << "Failed to entry new app state!";
				}
				break;
			}
		}
		return !quitApp;
	}
}
