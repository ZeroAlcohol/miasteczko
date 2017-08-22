#include "TextFactory.hpp"


sf::Text TextFactory::createText(std::string p_text, int p_scale, std::string p_font) 
{
	m_font.loadFromFile(p_font);
		
	m_text.setFont(m_font);
    m_text.setCharacterSize(p_scale);
	m_text.setString(p_text);	
	
	return m_text;
}

TextFactory::TextFactory()
{
}


TextFactory::~TextFactory()
{
}
