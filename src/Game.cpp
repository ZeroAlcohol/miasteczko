#include <chrono>
#include <cmath>
#include "TextureContainer.hpp"
#include "resources.textures.hpp"
#include "Game.hpp"
#include "GameObjectFactory.hpp"


Game::Game()
{

}

bool Game::createGame()
{
    m_activeObjects.push_back(GameObjectFactory().createPlayer());
	
	// temporary
	m_exampleSprite = TextureContainer::getSprite(rs::tx::vodka);
	m_exampleSprite.setPosition(sf::Vector2f(125, 70));

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

void Game::renderFrame(sf::RenderWindow & p_window)
{
	for (auto& t : m_activeObjects)
	{
        t->render(p_window);
	}

	for (auto& t : m_passiveObjects)
	{
        t->render(p_window);
	}

	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	float scale = 1.0f + std::sin(ms.count() / 50)*0.2f;
	m_exampleSprite.setScale(sf::Vector2f(scale, scale));
	p_window.draw(m_exampleSprite);
}
