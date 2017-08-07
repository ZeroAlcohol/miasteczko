#include <chrono>
#include <cmath>
#include "TextureContainer.hpp"
#include "resources.textures.hpp"
#include "Game.hpp"
#include "GameObjectFactory.hpp"
#include "passive-game-object-mock.hpp"
#include "easylogging++.h"


Game::Game()
{

}

bool Game::createGame()
{
    m_activeObjects.push_back(GameObjectFactory().createPlayer());
	
	// temporary
	m_passiveObjects.push_back(GameObjectFactory().createPassiveObjectMock(200, 100, 100, 100, 50, { 255, 0, 0 }));
	m_passiveObjects.push_back(GameObjectFactory().createPassiveObjectMock(800, 120, 100, 300, 75, { 0, 255, 0 }));
	m_passiveObjects.push_back(GameObjectFactory().createPassiveObjectMock(700, 320, 150, 150, 0, { 0, 0, 255 }));
    return true;
}

void Game::onEvent(sf::Event & p_event)
{

}

void Game::update(const float dt)
{
	for (auto t = m_activeObjects.begin(); t != m_activeObjects.end(); t++)
	{
		(*t)->run();
	}
}

void Game::renderFrame(sf::RenderWindow & p_window, const float dt)
{
	// here render backround

	for (auto& t : m_passiveObjects)
	{
        t->render(p_window);
	}

	for (auto& t : m_activeObjects)
	{
		t->render(p_window);
	}

	// here render hud
}
