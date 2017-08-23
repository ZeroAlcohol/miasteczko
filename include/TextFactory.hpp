#ifndef TEXT_FACTORY_H
#define TEXT_FACTORY_H
#include "SFML/Graphics.hpp"
#include "IObject.hpp"

class TextFactory : public IObject
{
public:
    TextFactory(std::string p_text, int p_scale, std::string p_font);
	~TextFactory();

    void run() override;
    void render(sf::RenderWindow& p_window) override;

    void setText(std::string p_text);

private:
	sf::Text m_text;
	sf::Font m_font;
};

#endif
