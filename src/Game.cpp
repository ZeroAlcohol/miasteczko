#include <chrono>
#include <cmath>
#include "TextureContainer.hpp"
#include "resources.textures.hpp"
#include "Game.hpp"
#include "GameObjectFactory.hpp"
#include "PassiveRenderRectangle.hpp"
#include "easylogging++.h"


Game::Game()
{

}

bool Game::createGame()
{
    m_activeObjects.push_back(GameObjectFactory().createPlayer());

    m_passiveObjects.push_back(GameObjectFactory().createPassiveRenderRectangle(200, 100, 100, 100, 50, { 255, 0, 0 }));
    m_passiveObjects.push_back(GameObjectFactory().createPassiveRenderRectangle(800, 120, 100, 300, 75, { 0, 255, 0 }));
    m_passiveObjects.push_back(GameObjectFactory().createPassiveRenderRectangle(700, 320, 150, 150, 0, { 0, 0, 255 }));

    auto l_activeObjectsIterator = std::find_if(m_passiveObjects.begin(), m_passiveObjects.end(), [](const auto& p){return p == nullptr;});
    if(*l_activeObjectsIterator == nullptr)
        return false;

    auto l_passiveObjectsIterator = std::find_if(m_passiveObjects.begin(), m_passiveObjects.end(), [](const auto& p){return p == nullptr;});
    if(*l_passiveObjectsIterator == nullptr)
        return false;

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
