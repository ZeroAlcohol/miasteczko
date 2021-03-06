#include <SFML/System.hpp>
#include "config.hpp" 
#include "Menu.hpp"

Menu::Menu(const Spirit::AppStateCode p_id) : 
	m_id{ p_id },
	Play{ "Play", 100, sf::Color::White, Config::XXX_FONT_SOURCE_PATH },
	Options{ "Options", 100, sf::Color::White, Config::XXX_FONT_SOURCE_PATH },
	Exit{ "Exit", 100, sf::Color::White, Config::XXX_FONT_SOURCE_PATH },
	m_currentState(State::Play), 
	m_currentAppState(p_id)
{

}

bool Menu::onEntry()
{
	setMenuState(State::Play);
	m_currentAppState = m_id;
	return true;
}

bool Menu::onQuit()
{
	return true;
}

void Menu::onEvent(sf::Event & p_event)
{
	switch (p_event.type)
	{
	case sf::Event::KeyReleased:

		switch (p_event.key.code)
		{
		case sf::Keyboard::Down:
			switchToNextMenuState();
			break;

		case sf::Keyboard::Up:
			switchToPreviousMenuState();
			break;

		case sf::Keyboard::Space:
		case sf::Keyboard::Return:

			switch (m_currentState)
			{
			case State::Play:
				m_currentAppState = Config::APP_STATE_CODE_GAME;
				break;

			case State::Exit:
				m_currentAppState = Spirit::APP_STATE_CODE_EXIT;
				break;
			}
		}
	}
}

void Menu::switchToNextMenuState()
{
	switch (m_currentState)
	{
	case State::Play:
		setMenuState(State::Options);
		break;

	case State::Options:
		setMenuState(State::Exit);
		break;

	case State::Exit:
		setMenuState(State::Play);
		break;
	}
}

void Menu::switchToPreviousMenuState()
{
	switch (m_currentState)
	{
	case State::Play:
		setMenuState(State::Exit);
		break;

	case State::Options:
		setMenuState(State::Play);
		break;

	case State::Exit:
		setMenuState(State::Options);
		break;
	}
}

void Menu::setMenuState(State p_state)
{
	m_currentState = p_state;

	switch (m_currentState)
	{
	case State::Play:
		Play.setColor(sf::Color::Red);
		Options.setColor(sf::Color::White);
		Exit.setColor(sf::Color::White);
		break;
	case State::Options:
		Play.setColor(sf::Color::White);
		Options.setColor(sf::Color::Red);
		Exit.setColor(sf::Color::White);
		break;
	case State::Exit:
		Play.setColor(sf::Color::White);
		Options.setColor(sf::Color::White);
		Exit.setColor(sf::Color::Red);
		break;
	default:
		break;
	}
}

Spirit::AppStateCode Menu::update(const float dt)
{
	return m_currentAppState;
}

Spirit::AppStateCode Menu::getId() const
{
	return m_id;
}

void Menu::renderFrame(sf::RenderWindow & p_window, const float dt)
{
    //temp
    Play.setPossition(p_window.getView().getCenter().x - 100, p_window.getView().getCenter().y -300);
    Options.setPossition(p_window.getView().getCenter().x - 100, p_window.getView().getCenter().y -150);
    Exit.setPossition(p_window.getView().getCenter().x - 100, p_window.getView().getCenter().y);

    Play.render(p_window);
    Options.render(p_window);
    Exit.render(p_window);
}


