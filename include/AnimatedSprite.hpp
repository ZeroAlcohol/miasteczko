#pragma once
#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Sprite
{
public:
    enum class Direction
    {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        DEFAULT
    };

    AnimatedSprite() : sf::Sprite() {}

    Direction getDirection();
    void setDirection(Direction p_direction);

    sf::Vector2f getOldPossition();
    void setOldPosstion(sf::Vector2f p_oldPossition);

    bool isDirectionChanged();

    void moveAnimation();

private:
    void rightAnimation();
    void leftAnimation();
    void upAnimation();
    void downAnimation();
    void defaultAnimation();

    sf::Vector2f m_oldPosition;
    Direction m_direction;
};
