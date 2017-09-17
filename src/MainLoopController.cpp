#include <thread>

#include "MainLoopController.hpp"
#include "config.hpp"

constexpr uint64_t DELAY_PER_UPDATE_FRAME{ 1000000ULL / Config::GAME_TARGET_UPS };
constexpr float DELAY_PER_UPDATE_FRAME_SEC{ 1.0f / Config::GAME_TARGET_UPS };
constexpr uint64_t MIN_DELAY_PER_RENDER_FRAME{ 1000000ULL / Config::GAME_MAX_FPS };

namespace Spirit
{
	MainLoopController::MainLoopController(App & p_app, sf::RenderWindow & p_window) : 
		m_app{ p_app }, m_window{ p_window } {}

	void MainLoopController::run()
	{
		m_startupTimestamp = std::chrono::high_resolution_clock::now();
		m_updateTimeout = getMicrosecondsFromStart() + DELAY_PER_UPDATE_FRAME;
		m_renderMinTimeout = getMicrosecondsFromStart() + MIN_DELAY_PER_RENDER_FRAME;
		m_renderLastFrameTime = getMicrosecondsFromStart();

		while (m_window.isOpen())
		{
			while (m_window.pollEvent(m_event))
			{
				m_app.onEvent(m_event);
			}

			for (auto i = 0; i < Config::MAX_FRAMESKIP && getMicrosecondsFromStart() > m_updateTimeout; ++i)
			{
				if (false == m_app.update(DELAY_PER_UPDATE_FRAME_SEC))
				{
					return;
				}
				m_updateTimeout += DELAY_PER_UPDATE_FRAME;
			}

			//Prevent accumulating more than 1 second of game updates (can happen in severe frame drops or breakpoints while debugging)
			if (getMicrosecondsFromStart() > m_updateTimeout + Config::GAME_TARGET_UPS*DELAY_PER_UPDATE_FRAME) {
				m_updateTimeout = getMicrosecondsFromStart() + DELAY_PER_UPDATE_FRAME;
			}

			if (getMicrosecondsFromStart() >= m_renderMinTimeout)
			{
				const float dt{ (getMicrosecondsFromStart() - m_renderLastFrameTime) / 1000000.0f };
				m_app.renderFrame(dt);
				m_renderLastFrameTime = getMicrosecondsFromStart();
				m_renderMinTimeout = m_renderLastFrameTime + MIN_DELAY_PER_RENDER_FRAME;
			}
			else
			{
				wait();
			}
		}
	}

	uint64_t MainLoopController::getMicrosecondsFromStart() const
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_startupTimestamp).count();
	}

	void MainLoopController::wait()
	{
		const uint64_t l_now = getMicrosecondsFromStart();

		if (l_now < m_renderMinTimeout && l_now < m_updateTimeout)
		{
			auto l_delay = std::min(m_renderMinTimeout - l_now, m_updateTimeout - l_now);
			std::this_thread::sleep_for(std::chrono::microseconds(l_delay));
		}
	}
}