#include <thread>
#include <algorithm>
#include "config.hpp"
#include "easylogging++.h"
#include "TextureContainer.hpp"
#include "app.hpp"

App::App()
{
	m_window.create(sf::VideoMode(600, 600), "Game");
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

	m_startupTimestamp = std::chrono::high_resolution_clock::now();
	m_updateTimeout = getMicros() + DELAY_PER_UPDATE_FRAME;
	m_renderMinTimeout = getMicros() + MIN_DELAY_PER_RENDER_FRAME;

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(m_event))
		{
			if ((m_event.type == sf::Event::Closed) || ((m_event.type == sf::Event::KeyPressed) && (m_event.key.code == sf::Keyboard::Escape)))
				m_window.close();

			m_game.onEvent(m_event);
		}

		for (auto i = 0; i < MAX_FRAMESKIP && getMicros() > m_updateTimeout; ++i)
		{
			m_game.update(DELAY_PER_UPDATE_FRAME_SEC);
			m_updateTimeout += DELAY_PER_UPDATE_FRAME;
		}

		//Prevent accumulating more than 1 second of game updates (can happen in severe frame drops or breakpoints while debugging)
		const uint64_t now = getMicros();
		if (now > m_updateTimeout + GAME_TARGET_UPS*DELAY_PER_UPDATE_FRAME) {
			m_updateTimeout = now + DELAY_PER_UPDATE_FRAME;
		}

		if (getMicros() >= m_renderMinTimeout)
		{
			renderFrame();
			m_renderMinTimeout = getMicros() + MIN_DELAY_PER_RENDER_FRAME;
		}
		else
		{
			wait();
		}
	}
}

void App::wait() 
{
	uint64_t now = getMicros();

	if (now < m_renderMinTimeout && now < m_updateTimeout) 
	{
		auto delay = std::min(m_renderMinTimeout - now, m_updateTimeout - now);
		std::this_thread::sleep_for(std::chrono::microseconds(delay));
	}
}
void App::renderFrame()
{
	//temporary
	static uint64_t l_lastFrameRenderTime{ getMicros() };
	m_window.clear();
	const float dt{(getMicros() - l_lastFrameRenderTime)/1000000.0f};
	l_lastFrameRenderTime = getMicros();
	m_game.renderFrame(m_window, dt);
	m_window.display();
}

uint64_t App::getMicros() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_startupTimestamp).count();
}