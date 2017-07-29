#include <chrono>
#include <cmath>
#include "resources.textures.hpp"
#include "Game.hpp"
#include "GameObjectFactory.hpp"
#include "TextureContainer.hpp"


Game::Game()
{

}

bool Game::createGame()
{
    m_window.create(sf::VideoMode(600,600), "Game");
    m_activeObjects.push_back(GameObjectFactory().createPlayer());
    TextureContainer::createResources();

    return true;
}

void Game::mainRun()
{
    auto& resource = TextureContainer::getInstance();

	// temporary
	sf::Sprite l_exampleSprite = TextureContainer::getSprite(rs::tx::vodka);
	l_exampleSprite.setPosition(sf::Vector2f(125, 70));
	
    while (m_window.isOpen())
    {

        while (m_window.pollEvent(m_event))
        {
            if ((m_event.type == sf::Event::Closed) || ((m_event.type == sf::Event::KeyPressed) && (m_event.key.code==sf::Keyboard::Escape)))
                    m_window.close();
        }

		m_window.clear();

		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		float scale = 1.0f + std::sin(ms.count()/50)*0.2f;
		l_exampleSprite.setScale(sf::Vector2f(scale, scale));

		m_window.draw(l_exampleSprite);

        m_window.display();

    }
}

void Game::physicsIteration()
{
	for (auto t = m_activeObjects.begin(); t != m_activeObjects.end(); t++)
	{
		(*t)->run();
	}
}

void Game::renderIteration()
{
	for (auto& t : m_activeObjects)
	{
        t->render(m_window);
	}

	for (auto& t : m_passiveObjects)
	{
        t->render(m_window);
	}

}
