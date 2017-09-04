#include <chrono>
#include <cmath>
#include "easylogging++.h"
#include "config.hpp"
#include "TextureContainer.hpp"
#include "resources.textures.hpp"
#include "Game.hpp"
#include "LevelLoader.hpp"
#include "TextFactory.hpp"
#include "Player.hpp"

Game::Game()
{
	
}

bool Game::createGame()
{
	const std::string l_levelId = "level_id";
	m_level = LevelLoader().load(l_levelId);
	bool levelLoadedCorrect = m_level.id == l_levelId;
	return levelLoadedCorrect;
}

void Game::onEvent(sf::Event & p_event)
{

}

void Game::update(const float dt)
{
    for (const auto& activeObject : m_level.activeObjects)
    {
        activeObject->run();
    }
}

void Game::renderFrame(sf::RenderWindow & p_window, const float dt)
{
	p_window.setView(getLevelView());

	p_window.draw(m_level.backgroundSrite);

    for (const auto& passiveObject : m_level.passiveObjects)
	{
        passiveObject->render(p_window);
	}

    for (const auto& activeObject : m_level.activeObjects)
	{
        activeObject->render(p_window);
	}
}

sf::View Game::getLevelView() const
{
    const Player* const l_pPlayer{ dynamic_cast<const Player*> (m_level.activeObjects.front().get())};
	if (nullptr == l_pPlayer)
	{
		return sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	}

	const std::pair <float, float> l_coords{ l_pPlayer->getCenterCoordinates() };

	float l_rectLeft{ std::max(0.0f, std::min(l_coords.first - WINDOW_WIDTH * 0.5f, float(m_level.width - WINDOW_WIDTH))) };
	float l_rectTop{ std::max(0.0f, std::min(l_coords.second - WINDOW_HEIGHT * 0.5f, float(m_level.height - WINDOW_HEIGHT))) };

	return sf::View(sf::FloatRect(l_rectLeft, l_rectTop, WINDOW_WIDTH, WINDOW_HEIGHT));
}
