#include "Text.hpp"

Text::Text(std::string p_text, int p_scale, sf::Color p_color, std::string p_font)
{
    m_font.loadFromFile(p_font);
    m_text.setFont(m_font);
    m_text.setCharacterSize(p_scale);
    m_text.setColor(p_color);
    m_text.setString(p_text);
}

Text::~Text()
{
}

void Text::run()
{

}

void Text::render(sf::RenderWindow &p_window)
{
    p_window.draw(m_text);
}

void Text::setText(const std::string p_text)
{
    m_text.setString(p_text);
}

void Text::setPossition(float x, float y)
{
    m_text.setPosition(x,y);
}

void Text::setColor(sf::Color p_color)
{
    m_text.setColor(p_color);
}
