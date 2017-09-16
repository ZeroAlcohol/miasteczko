#pragma once

#include <string>
#include <memory>

#include "ILevelObject.hpp"
#include "Animation.hpp"

class Player : public ILevelObject
{
public:
    Player();
    Player(std::string p_name, Animation p_animation, unsigned p_speed);
    ~Player();
    std::string getName() const;
    void update() override;
    void render(sf::RenderWindow& p_window) override;
    std::pair <float, float> getCenterCoordinates() const;
	
private:
    std::string m_name;
    Animation m_animation;
    float m_speed;
};

