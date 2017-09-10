#pragma once

#include "SFML/Graphics.hpp"
#include "IObject.hpp"

class Text : public IObject
{
public:
    Text(std::string p_text, int p_scale, sf::Color p_color, std::string p_font);
    ~Text();
    void run() override;
    void render(sf::RenderWindow& p_window) override;
    void setText(const std::string p_text);
    void setPossition(float x, float y);
    void setColor(sf::Color p_color);

private:
    sf::Text m_text;
    sf::Font m_font;
};

