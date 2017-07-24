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

    while (m_window.isOpen())
    {

        while (m_window.pollEvent(m_event))
        {
            if ((m_event.type == sf::Event::Closed) || ((m_event.type == sf::Event::KeyPressed) && (m_event.key.code==sf::Keyboard::Escape)))
                    m_window.close();
        }
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
