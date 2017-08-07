#pragma once

#include "IObject.hpp"

class PassiveGameObjectMock: public IObject
{
public:
    PassiveGameObjectMock(float p_x, float p_y, float p_w, float p_h, float p_rotation, sf::Color p_color);
    ~PassiveGameObjectMock();
    virtual void run() override;
    virtual void render(sf::RenderWindow& p_window) override;

private:
	sf::Sprite m_sprite;
};