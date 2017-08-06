#include "app.hpp"
#include "TextureContainer.hpp"
#include "easylogging++.h"

App::App()
{
	m_window.create(sf::VideoMode(600, 600), "Game");
	TextureContainer::createResources();
}

App::~App()
{

}

void App::run() 
{
	if (false == m_game.createGame())
	{
		LOG(FATAL) << "Failed to create game!";
	}

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(m_event))
		{
			if ((m_event.type == sf::Event::Closed) || ((m_event.type == sf::Event::KeyPressed) && (m_event.key.code == sf::Keyboard::Escape)))
				m_window.close();

			m_game.onEvent(m_event);
		}

		m_game.update(30.0f);

		renderFrame();
	}
}

void App::renderFrame()
{
	m_window.clear();
	m_game.renderFrame(m_window);
	m_window.display();
}