#include "Menu.hpp"
#include <SFML/System.hpp>
#include <TextureContainer.hpp>


Menu::Menu() : Play("Play", 100, sf::Color::White, "../data/xxx.ttf"), Options("Options", 100, sf::Color::White, "../data/xxx.ttf"),Exit("Exit", 100, sf::Color::White, "../data/xxx.ttf"),
                    m_currentState(State::Play)
{

}

Menu::State Menu::run()
{
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(m_currentState == State::Play)
        {
            m_currentState = State::Exit;
        }
        else if(m_currentState == State::Options)
        {
            m_currentState = State::Play;
        }
        else if(m_currentState == State::Exit)
        {
            m_currentState = State::Options;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
       if(m_currentState == State::Play)
       {
           m_currentState = State::Options;
       }
       else if(m_currentState == State::Options)
       {
           m_currentState = State::Exit;
       }
       else if(m_currentState == State::Exit)
       {
           m_currentState = State::Play;
       }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
       return m_currentState;
    }

}

void Menu::renderFrame(sf::RenderWindow &p_window)
{
    //temp
    Play.setPossition(p_window.getView().getCenter().x - 100, p_window.getView().getCenter().y -300);
    Options.setPossition(p_window.getView().getCenter().x - 100, p_window.getView().getCenter().y -150);
    Exit.setPossition(p_window.getView().getCenter().x - 100, p_window.getView().getCenter().y);

    Play.render(p_window);
    Options.render(p_window);
    Exit.render(p_window);

    p_window.display();
}


