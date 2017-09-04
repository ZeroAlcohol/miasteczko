#include "PassiveTexturedRectangle.hpp"

PassiveTexturedRectangle::PassiveTexturedRectangle(float p_x, float p_y, float p_rotation, sf::Sprite p_sprite) :
	m_sprite{p_sprite}
{
	m_sprite.setPosition(p_x, p_y);
	m_sprite.setRotation(p_rotation);
}

PassiveTexturedRectangle::~PassiveTexturedRectangle()
{

}

void PassiveTexturedRectangle::run()
{

}

void PassiveTexturedRectangle::render(sf::RenderWindow& p_window)
{
     	p_window.draw(m_sprite);
}
