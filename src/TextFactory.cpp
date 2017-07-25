#include "..\include\TextFactory.h"


bool TextFactory::createText(sf::String p_text, int p_scale, sf::Color p_color) 
{
	if (!m_font.loadFromFile("arial.ttf"))
	{
		do 
		{
			m_font.loadFromFile("arial.ttf");
		} 
		while (m_font.loadFromFile("arial.ttf"));
	}

	m_text.setFont(m_font);
	m_text.setCharacterSize(m_text.getCharacterSize() * p_scale);
	m_text.setString(p_text);	
	//m_text.setColor(p_color);
}

TextFactory::TextFactory()
{
}


TextFactory::~TextFactory()
{
}
