#include"Player.hpp"
#include <iostream>

Player::Player(std::string p_name) : m_name(p_name)
{
	// temporary
	sf::RenderTexture * renderTexture = new sf::RenderTexture();
	if (renderTexture->create(70, 70))
	{
		renderTexture->clear({ 255, 255, 255 });
		renderTexture->display();
		m_sprite.setTexture(renderTexture->getTexture());
		m_sprite.setPosition(300, 300);
	}
}

Player::~Player()
{

}

std::string Player::getName()
{
    return m_name;
}

void Player::run()
{
   // std::cout<< "my name is "<< m_name <<std::endl;

}

void Player::render(sf::RenderWindow& p_window)
{
	p_window.draw(m_sprite);
}
