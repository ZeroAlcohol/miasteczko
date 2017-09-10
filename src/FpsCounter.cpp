#include "FpsCounter.hpp"
#include "config.hpp"

FpsCounter::FpsCounter() : m_framerate(0), m_text("Nacisniej F a zobaczysz Fps'y", 100, sf::Color::Red, XXX_FONT_SOURCE_PATH)
{

}

unsigned FpsCounter::getFrames()
{
    m_framerate = 1.f / m_clock.getElapsedTime().asSeconds();
    m_clock.restart();
    return m_framerate;
}

void FpsCounter::run()
{

}

void FpsCounter::render(sf::RenderWindow& p_window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        m_text.setText(std::to_string(getFrames()) + " Fps");
    }

     m_text.render(p_window);
}
