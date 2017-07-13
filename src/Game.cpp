#include "Game.hpp"

Game::Game()
{

}

bool Game::createGame()
{
    m_window.create(sf::VideoMode(600,600), "Game");

    return true;
}

void Game::run()
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
