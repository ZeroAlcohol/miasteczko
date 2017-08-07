#include"Player.hpp"
#include <iostream>
#include <cmath>

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
	// temporary 

	double l_dirx{}, l_diry{};
	double l_speed{ 2 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		l_dirx = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		l_dirx = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		l_diry = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		l_diry = 1;
	}

	bool l_move = l_dirx || l_diry;

	if (l_move)
	{
		double angle = std::atan2(l_diry, l_dirx);
		m_sprite.move(std::cos(angle) * l_speed, std::sin(angle) * l_speed);
	}
}

void Player::render(sf::RenderWindow& p_window)
{
	p_window.draw(m_sprite);
}
