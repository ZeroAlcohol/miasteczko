#include <chrono>
#include <cmath>
#include "TextureContainer.hpp"
#include "resources.textures.hpp"
#include "Game.hpp"
#include "LevelLoader.hpp"
#include "easylogging++.h"


Game::Game()
{

}

bool Game::createGame()
{
	m_level = LevelLoader().load("exampleLevel");
    return true;
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
	// here render backround

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
