#include <cmath>
#include "Game.hpp"
#include "LevelLoader.hpp"

Game::Game() : m_isLoaded{ false }, m_currentAppState{ IAppState::AppStateCode::Game }
{
	
}

bool Game::onEntry()
{
	m_currentAppState = IAppState::AppStateCode::Game;
	
	if (false == m_isLoaded)
	{
		const std::string l_levelId = "level_id";
		m_level = LevelLoader().load(l_levelId);
		m_isLoaded = m_level.getId() == l_levelId;
	}

	return m_isLoaded;
}

bool Game::onQuit()
{
	return true;
}

void Game::onEvent(sf::Event & p_event)
{
	switch (p_event.type)
	{

	case sf::Event::KeyReleased:

		switch (p_event.key.code)
		{

		case sf::Keyboard::Escape:
			m_currentAppState = AppStateCode::Menu;
			break;
		}
	}
}

IAppState::AppStateCode Game::update(const float dt)
{
    for (const auto& activeObject : m_level.getActiveObjects())
    {
        activeObject->run();
    }

	return m_currentAppState;
}

void Game::renderFrame(sf::RenderWindow & p_window, const float dt)
{
	p_window.setView(m_level.getLevelView());

	p_window.draw(m_level.getBackgroundSprite());

    for (const auto& passiveObject : m_level.getPassiveObjects())
	{
        passiveObject->render(p_window);
	}

    for (const auto& activeObject : m_level.getActiveObjects())
	{
        activeObject->render(p_window);
	}

}

