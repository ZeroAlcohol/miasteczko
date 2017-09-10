#include <thread>
#include <algorithm>
#include "config.hpp"
#include "easylogging++.h"
#include "TextureContainer.hpp"
#include "app.hpp"

App::App() : m_currentStateIndex(IAppState::AppStateCode::Menu)
{
	m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
	TextureContainer::createResources();
}

App::~App()
{

}

void App::run() 
{

    if (false == m_menu.onEntry())
    {
        LOG(FATAL) << "Failed to entry menu!";
    }
    else
    {
        m_startupTimestamp = std::chrono::high_resolution_clock::now();
        m_updateTimeout = getMicrosecondsFromStart() + DELAY_PER_UPDATE_FRAME;
        m_renderMinTimeout = getMicrosecondsFromStart() + MIN_DELAY_PER_RENDER_FRAME;

        while (m_window.isOpen())
        {
			while (m_window.pollEvent(m_event))
			{
				onEvent(m_event);
			}

            for (auto i = 0; i < MAX_FRAMESKIP && getMicrosecondsFromStart() > m_updateTimeout; ++i)
            {
				update();
                m_updateTimeout += DELAY_PER_UPDATE_FRAME;
            }

            //Prevent accumulating more than 1 second of game updates (can happen in severe frame drops or breakpoints while debugging)
            if (getMicrosecondsFromStart() > m_updateTimeout + GAME_TARGET_UPS*DELAY_PER_UPDATE_FRAME) {
                m_updateTimeout = getMicrosecondsFromStart() + DELAY_PER_UPDATE_FRAME;
            }

            if (getMicrosecondsFromStart() >= m_renderMinTimeout)
            {
                renderFrame();
                m_renderMinTimeout = getMicrosecondsFromStart() + MIN_DELAY_PER_RENDER_FRAME;
            }
            else
            {
                wait();
            }
        }
    }
}

void App::onEvent(sf::Event p_event)
{

	switch (p_event.type)
	{
	case sf::Event::Closed:
		m_appStates[int(m_currentStateIndex)]->onQuit();
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
		
	m_appStates[int(m_currentStateIndex)]->onEvent(p_event);
}

void App::update()
{
	const IAppState::AppStateCode l_futureStateIndex = m_appStates[int(m_currentStateIndex)]->update(DELAY_PER_UPDATE_FRAME_SEC);
	if (l_futureStateIndex != m_currentStateIndex)
	{
		if (false == m_appStates[int(m_currentStateIndex)]->onQuit())
		{
			LOG(FATAL) << "Failed to quit current app state!";
		}

		if (IAppState::AppStateCode::Exit == l_futureStateIndex)
		{
			m_window.close();
		}
		else
		{
			m_currentStateIndex = l_futureStateIndex;
			if (false == m_appStates[int(m_currentStateIndex)]->onEntry())
			{
				LOG(FATAL) << "Failed to entry new app state!";
			}
		}
	}
}

void App::wait() 
{
     const uint64_t l_now = getMicrosecondsFromStart();

    if (l_now < m_renderMinTimeout && l_now < m_updateTimeout)
	{
        auto l_delay = std::min(m_renderMinTimeout - l_now, m_updateTimeout - l_now);
        std::this_thread::sleep_for(std::chrono::microseconds(l_delay));
	}
}

void App::renderFrame()
{
	//temporary
    static uint64_t l_lastFrameRenderTime {getMicrosecondsFromStart()};
    const float dt{(getMicrosecondsFromStart() - l_lastFrameRenderTime)/1000000.0f};
    l_lastFrameRenderTime = getMicrosecondsFromStart();

    m_window.clear();
	m_appStates[int(m_currentStateIndex)]->renderFrame(m_window, dt);
	m_fpsCounter.render(m_window);
	m_window.display();
}

uint64_t App::getMicrosecondsFromStart() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_startupTimestamp).count();
}
