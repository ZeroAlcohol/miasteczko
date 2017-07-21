#include "Game.hpp"
#include "GameObjectLoader.hpp"

Game::Game()
{

}

bool Game::createGame()
{
    m_window.create(sf::VideoMode(600,600), "Game");

    m_activeObjects.push_back(GameObjectLoader().createPlayer());

    return true;
}

void Game::mainRun()
{
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
		t->render();
	}

	for (auto& t : m_passiveObjects)
	{
		t->render();
	}

}
