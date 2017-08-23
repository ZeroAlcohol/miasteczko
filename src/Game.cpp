#include <chrono>
#include <cmath>
#include "TextureContainer.hpp"
#include "resources.textures.hpp"
#include "Game.hpp"
#include "LevelLoader.hpp"
#include "easylogging++.h"
#include "TextFactory.hpp"

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
	for (auto t = m_level.activeObjects.begin(); t != m_level.activeObjects.end(); t++)
	{
		(*t)->run();
	}
}

void Game::renderFrame(sf::RenderWindow & p_window, const float dt)
{

	p_window.draw(m_level.backgroundSrite);

	for (auto& t : m_level.passiveObjects)
	{
        t->render(p_window);
	}

	for (auto& t : m_level.activeObjects)
	{
		t->render(p_window);
	}

	// here render hud
}
