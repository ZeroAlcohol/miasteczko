#include"Player.hpp"
#include <iostream>
#include <cmath>

Player::Player(std::string p_name) : m_name(p_name)
{
	// temporary
    l_renderTexture = std::make_unique<sf::RenderTexture>();
    if (l_renderTexture && l_renderTexture->create(70, 70))
	{
        l_renderTexture->clear({ 255, 255, 255 });
        l_renderTexture->display();
        m_animatedSprite.setOrigin(35,35);
        m_animatedSprite.setTexture(l_renderTexture->getTexture());
        m_animatedSprite.setPosition(300, 300);
        m_animatedSprite.setOldPosstion(m_animatedSprite.getPosition());
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
        m_animatedSprite.setDirection(AnimatedSprite::Direction::LEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		l_dirx = 1;
         m_animatedSprite.setDirection(AnimatedSprite::Direction::RIGHT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		l_diry = -1;
         m_animatedSprite.setDirection(AnimatedSprite::Direction::UP);
    }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		l_diry = 1;
         m_animatedSprite.setDirection(AnimatedSprite::Direction::DOWN);
	}

	bool l_move = l_dirx || l_diry;

	if (l_move)
	{
		double angle = std::atan2(l_diry, l_dirx);
        m_animatedSprite.move(std::cos(angle) * l_speed, std::sin(angle) * l_speed);

	}
}

void Player::render(sf::RenderWindow& p_window)
{
        m_animatedSprite.moveAnimation();
        p_window.draw(m_animatedSprite);
}

