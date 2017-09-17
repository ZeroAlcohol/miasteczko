#include <cmath>
#include "Game.hpp"
#include "LevelLoader.hpp"

Game::Game(const Spirit::AppStateCode p_id, const Spirit::ITextureProvider & p_textureProvider) :
	m_id{ p_id },
	m_isLoaded{ false },
	m_textureProvider{ p_textureProvider }, 
	m_currentAppState { p_id }
{
	
}

bool Game::onEntry()
{
	m_currentAppState = m_id;
	
	if (false == m_isLoaded)
	{
		const std::string l_levelId = "level_id";
		m_level = LevelLoader(m_textureProvider).load(l_levelId);
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
			m_currentAppState = Config::APP_STATE_CODE_MENU;
			break;
		}
	}
}

Spirit::AppStateCode Game::update(const float dt)
{
    for (const auto& activeObject : m_level.getActiveObjects())
    {
        activeObject->update();
    }

	return m_currentAppState;
}

Spirit::AppStateCode Game::getId() const
{
	return m_id;
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

