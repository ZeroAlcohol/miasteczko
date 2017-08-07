#include "passive-game-object-mock.hpp"

PassiveGameObjectMock::PassiveGameObjectMock(float p_x, float p_y, float p_w, float p_h, float p_rotation, sf::Color p_color)
{
	// temporary
	sf::RenderTexture * renderTexture = new sf::RenderTexture();
	if (renderTexture->create(p_w, p_h))
	{
		renderTexture->clear(p_color);
		renderTexture->display();
		m_sprite.setTexture(renderTexture->getTexture());
		m_sprite.setPosition(p_x, p_y);
		m_sprite.setRotation(p_rotation);
	}
}

PassiveGameObjectMock::~PassiveGameObjectMock()
{

}

void PassiveGameObjectMock::run()
{

}

void PassiveGameObjectMock::render(sf::RenderWindow& p_window)
{
	p_window.draw(m_sprite);
}