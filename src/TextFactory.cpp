#include "TextFactory.hpp"

TextFactory::TextFactory(std::string p_text, int p_scale, sf::Color p_color, std::string p_font)
{
    m_font.loadFromFile(p_font);
    m_text.setFont(m_font);
    m_text.setCharacterSize(p_scale);
    m_text.setColor(p_color);
    m_text.setString(p_text);
}

TextFactory::~TextFactory()
{
}

void TextFactory::run()
{

}

void TextFactory::render(sf::RenderWindow &p_window)
{
    p_window.draw(m_text);
}

void TextFactory::setText(const std::string p_text)
{
    m_text.setString(p_text);
}
