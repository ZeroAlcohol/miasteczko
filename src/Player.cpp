#include "Player.hpp"
#include <iostream>
#include <cmath>

Player::Player(std::string p_name, sf::Sprite p_sprite) : m_name(p_name)
{
      m_animation.setTexture(*p_sprite.getTexture());
      m_animation.addFrame(sf::IntRect(0, 0, 152, 252));
      m_animation.addFrame(sf::IntRect(152, 0, 152, 252));
      m_animation.addFrame(sf::IntRect(0, 255, 152, 252));
      m_animation.addFrame(sf::IntRect(152, 252, 152, 252));
      m_animation.addFrame(sf::IntRect(0, 504, 152, 252));
      m_animation.addFrame(sf::IntRect(152, 504, 152, 252));

      m_animation.setFrameDuration(std::chrono::milliseconds(100));
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
        m_animation.move(std::cos(angle) * l_speed, std::sin(angle) * l_speed);

        m_animation.playAnimation();
	}
    else
    {
        m_animation.pauseAnimation();
    }
}

void Player::render(sf::RenderWindow& p_window)
{
    m_animation.updateAnimation();
    p_window.draw(m_animation);
}

