#include "AnimatedSprite.hpp"


sf::Vector2f AnimatedSprite::getOldPossition()
{
    return m_oldPosition;
}

void AnimatedSprite::setOldPosstion(sf::Vector2f p_oldPossition)
{
    m_oldPosition = p_oldPossition;
}

void AnimatedSprite::setDirection(AnimatedSprite::Direction p_direction)
{
    m_direction = p_direction;
}

bool AnimatedSprite::isDirectionChanged()
{
    return getPosition() != getOldPossition();
}

void AnimatedSprite::moveAnimation()
{
    if(isDirectionChanged())
    {
        setOldPosstion(getPosition());

        switch (getDirection()) {
        case AnimatedSprite::Direction::RIGHT:
            rightAnimation();
            break;
        case AnimatedSprite::Direction::LEFT:
            leftAnimation();
            break;
        case AnimatedSprite::Direction::UP:
            upAnimation();
            break;
        case AnimatedSprite::Direction::DOWN:
            downAnimation();
            break;
        default:
            break;
        }

    }
}

AnimatedSprite::Direction AnimatedSprite::getDirection()
{
    return m_direction;
}

void AnimatedSprite::rightAnimation()
{
    rotate(3);
}

void AnimatedSprite::leftAnimation()
{
    rotate(-3);
}

void AnimatedSprite::upAnimation()
{
    setColor({250,0, 0});
}

void AnimatedSprite::downAnimation()
{
    setColor({0,250, 0});
}

void AnimatedSprite::defaultAnimation()
{

}
