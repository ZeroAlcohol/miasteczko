#include "PassiveRenderRectangle.hpp"

PassiveRenderRectangle::PassiveRenderRectangle(float p_x, float p_y, float p_w, float p_h, float p_rotation, sf::Color p_color)
{
	// temporary

    l_renderTexture = std::make_unique<sf::RenderTexture>();

    if (l_renderTexture && l_renderTexture->create(p_w, p_h))
	{
        l_renderTexture->clear(p_color);
        l_renderTexture->display();
        m_sprite.setTexture(l_renderTexture->getTexture());
		m_sprite.setPosition(p_x, p_y);
		m_sprite.setRotation(p_rotation);
	}
}

PassiveRenderRectangle::~PassiveRenderRectangle()
{

}

void PassiveRenderRectangle::run()
{

}

void PassiveRenderRectangle::render(sf::RenderWindow& p_window)
{
	p_window.draw(m_sprite);
}
