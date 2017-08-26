#include <thread>
#include <algorithm>
#include "config.hpp"
#include "easylogging++.h"
#include "TextureContainer.hpp"
#include "app.hpp"

App::App()
{
	m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
	TextureContainer::createResources();
}

App::~App()
{

}

void App::run() 
{
	if (false == m_game.createGame())
	{
		LOG(FATAL) << "Failed to create game!";
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
                if ((m_event.type == sf::Event::Closed) || ((m_event.type == sf::Event::KeyPressed) && (m_event.key.code == sf::Keyboard::Escape)))
                    m_window.close();

                m_game.onEvent(m_event);
            }

            for (auto i = 0; i < MAX_FRAMESKIP && getMicrosecondsFromStart() > m_updateTimeout; ++i)
            {
                m_game.update(DELAY_PER_UPDATE_FRAME_SEC);
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
	m_game.renderFrame(m_window, dt);
	m_window.display();
}

uint64_t App::getMicrosecondsFromStart() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_startupTimestamp).count();
}
