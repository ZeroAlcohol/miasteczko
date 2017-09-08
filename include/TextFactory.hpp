#pragma once

#include "SFML/Graphics.hpp"
#include "IObject.hpp"

class TextFactory : public IObject
{
public:
    TextFactory(std::string p_text, int p_scale, sf::Color p_color, std::string p_font);
	~TextFactory();
    void run() override;
    void render(sf::RenderWindow& p_window) override;
    void setText(const std::string p_text);

private:
	sf::Text m_text;
	sf::Font m_font;
};

