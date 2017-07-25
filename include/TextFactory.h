#pragma once
#include "SFML\Graphics.hpp"
#include "IObject.hpp"

class TextFactory : public IObject
{
public:
	TextFactory();
	~TextFactory();

	bool createText(sf::String p_text, int p_scale, sf::Color p_color);
	
private:
	sf::Text m_text;
	sf::Font m_font;
};

