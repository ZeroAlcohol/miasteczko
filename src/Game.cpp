#include <cmath>
#include "Game.hpp"
#include "LevelLoader.hpp"

Game::Game()
{
	
}

bool Game::createGame()
{
	const std::string l_levelId = "level_id";
	m_level = LevelLoader().load(l_levelId);
	bool levelLoadedCorrect = m_level.getId() == l_levelId;
	return levelLoadedCorrect;
}

void Game::onEvent(sf::Event & p_event)
{

}

void Game::update(const float dt)
{
    for (const auto& activeObject : m_level.getActiveObjects())
    {
        activeObject->run();
    }
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
