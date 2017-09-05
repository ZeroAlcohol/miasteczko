#include "Player.hpp"
#include <cmath>

Player::Player(std::string p_name, Animation p_animation) : m_name(p_name), m_animation(p_animation), m_speed(5)
{

}

Player::~Player()
{

}

std::string Player::getName() const
{
    return m_name;
}

void Player::run()
{
    float l_directionX{};
    float l_directionY{};

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
        l_directionX = -1;

	}
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
        l_directionX = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
        l_directionY = -1;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
        l_directionY = 1;
	}

    if (l_directionX || l_directionY)
	{
        double l_angle = std::atan2(l_directionY, l_directionX);
        m_animation.move(std::cos(l_angle) * m_speed, std::sin(l_angle) * m_speed);
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

std::pair<float, float> Player::getCenterCoordinates() const
{
    sf::FloatRect l_rect {m_animation.getGlobalBounds()};
    float l_x {l_rect.left + l_rect.width * 0.5f};
    float l_y {l_rect.top + l_rect.height * 0.5f};

    return std::make_pair(l_x, l_y);
}
