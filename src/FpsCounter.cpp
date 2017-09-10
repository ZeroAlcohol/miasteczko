#include "FpsCounter.hpp"
#include "config.hpp"

FpsCounter::FpsCounter() : m_framerate(0), m_text("Nacisniej F a zobaczysz Fps'y", 1000, sf::Color::Red, XXX_FONT_SOURCE_PATH), m_visible{false}
{

}

unsigned FpsCounter::getFrames()
{
    m_framerate = 1.f / m_clock.getElapsedTime().asSeconds();
    m_clock.restart();
    return m_framerate;
}

void FpsCounter::render(sf::RenderWindow& p_window)
{
	if (isVisible())
	{
		m_text.setText(std::to_string(getFrames()) + " Fps");
		m_text.render(p_window);
	}
}

void FpsCounter::show()
{
	m_visible = true;
}

void FpsCounter::hide()
{
	m_visible = false;
}

bool FpsCounter::isVisible() const
{
	return m_visible;
}