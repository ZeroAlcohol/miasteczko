#pragma once
#include "SFML\Graphics.hpp"

class TextFactory
{
public:
	TextFactory();
	~TextFactory();

	sf::Text createText(std::string p_text, int p_scale, std::string p_font);

private:
	sf::Text m_text;
	sf::Font m_font;
};

